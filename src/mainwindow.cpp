#include "mainwindow.h"
#include <QScrollArea>
#include "gameview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QScrollArea *scroll = new QScrollArea;
    scroll->setWidget(new GameView());
    scroll->setWidgetResizable(true);
    setCentralWidget(scroll);
}
