#include "level.h"
#include <QStringList>
#include <QDebug>

Level::Level(const QStringList &definition, QObject *parent) :
    QObject(parent),
    m_width(-1),
    m_height(-1)
{
    m_valid = parse(definition);
}

bool Level::parse(const QStringList &definition)
{
    int w;
    QVector<Field> part;
    Q_FOREACH(const QString &line, definition) {
        ++m_height;
        w = 0;
        for (auto it = line.begin(); it != line.end(); ++it) {
            switch(it->toAscii()) {
            case ' ':
                part.append(Field::EMPTY);
                break;
            case '#':
                part.append(Field::WALL);
                break;
            case '@':
                part.append(Field::PLAYER);
                m_playerPosition = qMakePair(w, m_height);
                break;
            case '+':
                part.append(Field::PLAYER_ON_GOAL);
                m_playerPosition = qMakePair(w, m_height);
                break;
            case '$':
                part.append(Field::BOX);
                break;
            case '*':
                part.append(Field::BOX_ON_GOAL);
                break;
            case '.':
                part.append(Field::GOAL);
                break;
            default:
                qCritical() << "incorrect level description" << it->toAscii();
                return false;
            }
            ++w;
        }
        m_map.append(part);
        m_width = qMax(m_width, w);
        part.clear();
    }
    ++m_height;
    for (auto it = m_map.begin(); it != m_map.end(); ++it)
        while (it->count() < m_width)
            it->append(Field::EMPTY);
    return true;
}

Level::Field Level::spot(int x, int y) const
{
    Q_ASSERT(x < m_width && y < m_height);
    return m_map.at(y).at(x);
}

Level& Level::operator=(const Level& other)
{
    this->m_map = other.m_map;
    this->m_width = other.m_width;
    this->m_height = other.m_height;
    this->m_playerPosition = other.m_playerPosition;
    this->m_valid = other.m_valid;
    return *this;
}
