#ifndef TXTPARSER_H
#define TXTPARSER_H

#include "iparser.h"
#include <QStringList>

class TxtParser : public IParser
{
public:
    TxtParser(const QString &file);
    Level getLevel(int index);
    int levelCount();
    QString levelSetName();
    QString levelName(int index);

private:
    bool getLevelInfo(int index, QStringList *definition, QString *levelName = NULL) const;
};

#endif // TXTPARSER_H
