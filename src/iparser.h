#ifndef IPARSER_H
#define IPARSER_H

#include <QString>
#include "level.h"

class IParser
{
public:
    IParser(const QString &file) :
        m_file(file)
    {
    }

    virtual ~IParser()
    {
    }

    virtual Level getLevel(int index) = 0;
    virtual int levelCount() = 0;
    virtual QString levelSetName() = 0;
    virtual QString levelName(int index) = 0;

protected:
    const QString m_file;
};

#endif // IPARSER_H
