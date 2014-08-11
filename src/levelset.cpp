#include <QDebug>
#include <QFile>
#include <QDir>
#include "levelset.h"

LevelSet::LevelSet(const QString &file, QObject *parent) :
    QObject(parent),
    m_file(file)
{
    load();
}

LevelSet::~LevelSet()
{
}

bool LevelSet::load()
{
    QFile file(m_file);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_file;
        return false;
    }
    QTextStream in(&file);
    QString line;
    QStringList lines;
    QStringList levelLines;
    while (!in.atEnd())
        lines.push_back(in.readLine());
    file.close();

    m_name = lines.takeFirst().mid(2);
    //skip header
    while (!lines.isEmpty()) {
        line = lines.takeFirst();
        if (line.isEmpty() || line.startsWith(';'))
            continue;
        lines.prepend(line);
        break;
    }
    //read all levels
    while (!lines.isEmpty()) {
        //read single level
        while (!lines.isEmpty()) {
            line = lines.takeFirst();
            if (line.startsWith(';')) {
                m_levels.append(new Level(levelLines, this));
                //remove empty line after level name
                if (!lines.isEmpty())
                    lines.removeFirst();
                break;
            }
            levelLines.append(line);
        }
        levelLines.clear();
    }
    return true;
}
