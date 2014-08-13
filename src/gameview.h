#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>

class QPaintEvent;
class QRect;
class QPainter;
class QImage;

class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = 0);
    ~GameView();

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void resizeForLevel();

private:
    QImage *m_imgWall;
    QImage *m_imgGoal;
    QImage *m_imgGround;
    QImage *m_imgBox;
    QImage *m_imgBoxGoal;
};

#endif // GAMEVIEW_H
