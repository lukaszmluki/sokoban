#ifndef LEVELSET_H
#define LEVELSET_H

#include <QString>
#include <QList>
#include "level.h"
#include "iparser.h"

class LevelSet
{
public:
    explicit LevelSet(const QString &file);
    ~LevelSet();

    int count() const { return m_parser->levelCount(); }
    QString name() const { return m_parser->levelSetName(); }
    Level level(int index) const { return m_parser->getLevel(index); }

private:
    IParser *m_parser;
};

#endif // LEVELSET_H
