#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QDebug>
#include "gameview.h"
#include "levelmanager.h"

namespace {
    const int TEXTURE_SIZE = 64;
}

GameView::GameView(QWidget *parent) :
    QWidget(parent)
{
    connect(&LevelManager::instance(), SIGNAL(levelSelected()), this, SLOT(resizeForLevel()));
    resizeForLevel();
}

void GameView::resizeForLevel()
{
    setMinimumSize(QSize(LevelManager::instance().selectedLevel().width()  * TEXTURE_SIZE,
                         LevelManager::instance().selectedLevel().height() * TEXTURE_SIZE));
}

void GameView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(rect());
    const Level &level = LevelManager::instance().selectedLevel();

    if (!level.isValid())
        return;

    int w = level.width();
    int h = level.height();
    int xoffset = qMax(0, (width() - w * TEXTURE_SIZE) >> 1);
    int yoffset = qMax(0, (height() - h * TEXTURE_SIZE) >> 1);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            QRect rect(QPoint(xoffset + x * TEXTURE_SIZE, yoffset + y * TEXTURE_SIZE),
                       QSize(TEXTURE_SIZE, TEXTURE_SIZE));
            switch (level.spot(x, y)) {
            case Level::Field::WALL:
                drawWall(painter, rect);
                break;
            case Level::Field::BOX:
                drawBox(painter, rect);
                break;
            case Level::Field::GOAL:
                drawGoal(painter, rect);
                break;
            default:
                //TODO: assert
                break;
            }
        }
    }
}

void GameView::drawWall(QPainter &painter, const QRect &rect)
{
    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(rect);
}

void GameView::drawBox(QPainter &painter, const QRect &rect)
{
    painter.setBrush(QBrush(Qt::yellow));
    painter.drawRect(rect);
}

void GameView::drawGoal(QPainter &painter, const QRect &rect)
{
    painter.setBrush(QBrush(Qt::darkYellow));
    painter.drawRect(rect);
}

void GameView::drawPlayer(QPainter &painter, const QRect &rect)
{

}
