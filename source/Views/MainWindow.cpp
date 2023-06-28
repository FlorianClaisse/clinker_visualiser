#include <QApplication>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
#include <QFileDialog>
#include <QTimer>
#include <QProgressBar>
#include <QMessageBox>

#include <iostream>
#include <unistd.h>

#include "include/MainWindow.hpp"
#include "../Models/JsonData/JsonData.hpp"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    createActions();
    createMenus();

    QProgressBar *progressBar = new QProgressBar{this};
    progressBar->setRange(0, 0);

    statusBar()->addPermanentWidget(progressBar);
    statusBar()->clearMessage();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout(QTimer::QPrivateSignal)), progressBar, SLOT(repaint()));
    timer->start(50);

    timer->stop();

    setWindowTitle(tr("Clinker Visualiser"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::createActions() {
    openAct = new QAction(tr("Open File"), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

    saveDataAct = new QAction(tr("Save Data"), this);
    saveDataAct->setShortcut(QKeySequence::Save);
    saveDataAct->setStatusTip(tr("Save current data to json"));
    connect(saveDataAct, &QAction::triggered, this, &MainWindow::saveData);

    saveSVGAct = new QAction(tr("Save SVG"), this);
    saveSVGAct->setStatusTip(tr("Save current data to SVG"));
    connect(saveSVGAct, &QAction::triggered, this, &MainWindow::saveSVG);

    undoAct = new QAction(tr("Undo"), this);
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo action"));
    connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

    redoAct = new QAction(tr("Redo"), this);
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo action"));
    connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

    aboutAct = new QAction(tr("About"), this);
    aboutAct->setStatusTip(tr("About action"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("About Qt"), this);
    aboutQtAct->setStatusTip(tr("About Qt action"));
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(saveDataAct);
    fileMenu->addAction(saveSVGAct);

    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);

    helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::openFile() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("In progress");
    todoBox.setText("En cours de developpement");
    todoBox.exec();

    QString filePath = QFileDialog::getOpenFileName(this, "Open a file", "", "Fichiers (*.json)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QString content = file.readAll();
            file.close();

            json_data::JsonData data =  nlohmann::json::parse(content.toStdString());
            std::cout << "Finish\n";
            std::cout.flush();
        } else {
            // TODO: Show error message
        }
    }
}

void MainWindow::saveData() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("TODO");
    todoBox.setText("Doit etre implementer");
    todoBox.exec();
}

void MainWindow::saveSVG() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("TODO");
    todoBox.setText("Doit etre implementer");
    todoBox.exec();
}

void MainWindow::undo() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("TODO");
    todoBox.setText("Doit etre implementer");
    todoBox.exec();
}

void MainWindow::redo() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("TODO");
    todoBox.setText("Doit etre implementer");
    todoBox.exec();
}

void MainWindow::about() {
    QMessageBox todoBox;
    todoBox.setWindowTitle("TODO");
    todoBox.setText("Doit etre implementer");
    todoBox.exec();
}

void MainWindow::aboutQt() {
    QApplication::aboutQt();
}

