#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionAbout_triggered() {
    QMessageBox::information(this, "About Me", "This is About Me");
}


void MainWindow::on_actionAbout_Qt_triggered() {
    QApplication::aboutQt();
}

