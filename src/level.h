#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QPair>
#include <QVector>

class Level : public QObject
{
    Q_OBJECT

    static const int F_EMPTY  = 0;
    static const int F_WALL   = 1;
    static const int F_GOAL   = 2;
    static const int F_BOX    = 4;
    static const int F_PLAYER = 8;
public:
    explicit Level(const QStringList &definition, QObject *parent = 0);
    Level() : m_valid(false) {}

    enum class Field {
        EMPTY          = F_EMPTY,
        WALL           = F_WALL,
        GOAL           = F_GOAL,
        PLAYER         = F_PLAYER,
        BOX            = F_BOX,
        PLAYER_ON_GOAL = F_GOAL | F_PLAYER,
        BOX_ON_GOAL    = F_GOAL | F_BOX,
    };

    Field spot(int x, int y) const;
    QPair<int, int> playerPosition() const { return m_playerPosition; }
    int width() const { return m_width; }
    int height() const { return m_height; }
    bool isValid() const { return m_valid; }

    Level& operator=(const Level& other);

signals:

public slots:

private:
    bool parse(const QStringList &definition);

    QVector<QVector<Field>> m_map;
    int m_width;
    int m_height;
    QPair<int, int> m_playerPosition;
    bool m_valid;
};

#endif // LEVEL_H
