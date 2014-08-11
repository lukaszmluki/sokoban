#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>

class QPaintEvent;
class QRect;
class QPainter;

class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void resizeForLevel();

private:
    void drawWall(QPainter &painter, const QRect &rect);
    void drawBox(QPainter &painter, const QRect &rect);
    void drawGoal(QPainter &painter, const QRect &rect);
    void drawPlayer(QPainter &painter, const QRect &rect);
};

#endif // GAMEVIEW_H
