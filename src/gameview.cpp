#include <QPainter>
#include <QPaintEvent>
#include "gameview.h"
#include "levelmanager.h"

GameView::GameView(QWidget *parent) :
    QWidget(parent)
{
    connect(&LevelManager::instance(), SIGNAL(levelSelected()), this, SLOT(resizeForLevel()));
    resize(LevelManager::instance().selectedLevel().width() * 64, LevelManager::instance().selectedLevel().height() * 64);
}

void GameView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(rect());
}
