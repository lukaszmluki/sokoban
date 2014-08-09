#include "mainwindow.h"
#include "gameview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setCentralWidget(new GameView());
}
