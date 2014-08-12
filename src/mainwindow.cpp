#include "mainwindow.h"
#include <QScrollArea>
#include <QKeyEvent>
#include <QDebug>
#include "gameview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QScrollArea *scroll = new QScrollArea;
    scroll->setWidget(new GameView());
    scroll->setWidgetResizable(true);
    scroll->installEventFilter(this);
    setCentralWidget(scroll);
    setFocusPolicy(Qt::StrongFocus);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        switch (keyEvent->key()) {
        case Qt::Key_Left:
        case Qt::Key_Up:
        case Qt::Key_Right:
        case Qt::Key_Down:
            return true;
        default:
            break;
        }
    }
    return QObject::eventFilter(obj, event);
}
