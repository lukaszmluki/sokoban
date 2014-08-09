TEMPLATE = app
TARGET = sokoban
VERSION = 0.0.1

CONFIG += debug
QT += opengl

QMAKE_CXXFLAGS += -Werror -Wextra -Wno-error=unused-parameter -std=c++11

INCLUDEPATH += ./src/

MOC_DIR = ./moc
OBJECTS_DIR = ./obj

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/gameview.cpp \
    src/level.cpp \
    src/levelset.cpp \
    src/levelmanager.cpp

HEADERS += \
    src/mainwindow.h \
    src/gameview.h \
    src/level.h \
    src/levelset.h \
    src/levelmanager.h