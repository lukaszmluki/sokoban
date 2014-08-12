#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QString>

class Level
{
    static const int F_EMPTY  = 0;
    static const int F_WALL   = 1;
    static const int F_GOAL   = 2;
    static const int F_BOX    = 4;
    static const int F_PLAYER = 8;
public:
    enum class Field {
        EMPTY          = F_EMPTY,
        WALL           = F_WALL,
        GOAL           = F_GOAL,
        PLAYER         = F_PLAYER,
        BOX            = F_BOX,
        PLAYER_ON_GOAL = F_GOAL | F_PLAYER,
        BOX_ON_GOAL    = F_GOAL | F_BOX,
    };

    explicit Level(const QVector<QVector<Field>> &definition, const QString &name);

    Level() :
        m_valid(false)
    {
    }

    Field spot(int x, int y) const;
    int width() const { return m_width; }
    int height() const { return m_height; }
    bool isValid() const { return m_valid; }
    QString name() const { return m_name; }

private:
    QVector<QVector<Field>> m_map;
    int m_width;
    int m_height;
    bool m_valid;
    QString m_name;
};

#endif // LEVEL_H
