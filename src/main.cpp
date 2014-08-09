
#include <QApplication>
#include <mainwindow.h>
#include "levelmanager.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    //load levels
    //TODO: make it asynch
    LevelManager::instance().selectLevel(0, 0);
    MainWindow window;
    window.show();
    return app.exec();
}
