#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QWidget>

class QPaintEvent;

class GameView : public QWidget
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:

};

#endif // GAMEVIEW_H
