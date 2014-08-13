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
    QWidget(parent),
    m_imgWall(new QImage(":/image/wall.png")),
    m_imgGoal(new QImage(":/image/goal.png")),
    m_imgGround(new QImage(":/image/ground.png")),
    m_imgBox(new QImage(":/image/box.png")),
    m_imgBoxGoal(new QImage(":/image/boxgoal.png"))
{
    connect(&LevelManager::instance(), SIGNAL(levelSelected()), this, SLOT(resizeForLevel()));
    resizeForLevel();
}

GameView::~GameView()
{
    delete m_imgWall;
    delete m_imgGoal;
    delete m_imgGround;
    delete m_imgBox;
    delete m_imgBoxGoal;
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
    painter.drawRect(event->rect());
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
            if (!rect.intersects(event->rect()))
                continue;
            switch (level.spot(x, y)) {
            case Level::Field::WALL:
                painter.drawImage(rect, *m_imgWall);
                break;
            case Level::Field::BOX:
                painter.drawImage(rect, *m_imgBox);
                break;
            case Level::Field::BOX_ON_GOAL:
                painter.drawImage(rect, *m_imgBoxGoal);
                break;
            case Level::Field::GOAL:
                painter.drawImage(rect, *m_imgGoal);
                break;
            case Level::Field::EMPTY:
                painter.drawImage(rect, *m_imgGround);
                break;
            case Level::Field::PLAYER:
            case Level::Field::PLAYER_ON_GOAL:
                painter.drawImage(rect, *m_imgGround);
                painter.setBrush(QBrush(Qt::green));
                painter.drawRect(rect.x() + 10, rect.y() + 10, rect.width() - 20, rect.height() - 20);
            default:
                //TODO: assert
                break;
            }
        }
    }
}
