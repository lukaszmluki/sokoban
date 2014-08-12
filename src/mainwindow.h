#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QKeyEvent;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
