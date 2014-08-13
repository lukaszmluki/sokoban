#include "level.h"
#include <QStringList>
#include <QDebug>

Level::Level(const QVector<QVector<Field>> &definition, const QString &name) :
    m_map(definition),
    m_width(definition.at(0).count()),
    m_height(definition.count()),
    m_valid(true),
    m_name(name)
{
}

Level::Field Level::spot(int x, int y) const
{
    Q_ASSERT(x < m_width && y < m_height);
    return m_map.at(y).at(x);
}
