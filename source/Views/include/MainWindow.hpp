#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openFile();
    void saveData();
    void saveSVG();

    void undo();
    void redo();

    void about();
    static void aboutQt();

private:
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *saveDataAct;
    QAction *saveSVGAct;

    QAction *undoAct;
    QAction *redoAct;

    QAction *aboutAct;
    QAction *aboutQtAct;

private:
    void createActions();
    void createMenus();
};
#endif // MAINWINDOW_H
