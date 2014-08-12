#include <QDebug>
#include "levelset.h"
#include "txtparser.h"

LevelSet::LevelSet(const QString &file)
{
    m_parser = new TxtParser(file);
}

LevelSet::~LevelSet()
{
    delete m_parser;
}
