#include "txtparser.h"
#include <QFile>
#include <QDir>
#include <QDebug>

TxtParser::TxtParser(const QString &file) :
    IParser(file)
{
}

bool TxtParser::getLevelInfo(int index, QStringList *definition, QString *levelName) const
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

    /*m_name =*/ lines.takeFirst().mid(2);
    //skip header
    while (!lines.isEmpty()) {
        line = lines.takeFirst();
        if (line.isEmpty() || line.startsWith(';'))
            continue;
        lines.prepend(line);
        break;
    }

    //read level definition
    while (!lines.isEmpty()) {
        //read single level
        while (!lines.isEmpty()) {
            line = lines.takeFirst();
            if (line.startsWith(';')) {
                if (!index--) {
                    if (definition)
                        *definition = levelLines;
                    if (levelName)
                        *levelName = line.mid(2);
                    return true;
                }
                //remove empty line after level name
                if (!lines.isEmpty())
                    lines.removeFirst();
                break;
            }
            levelLines.append(line);
        }
        levelLines.clear();
    }
    return false;
}


Level TxtParser::getLevel(int index)
{
    int maxw = 0, w;
    QVector<Level::Field> part;
    QVector<QVector<Level::Field>> map;
    QStringList definition;
    QString name;
    if (!getLevelInfo(index, &definition, &name)) {
        return Level();
    }

    Q_FOREACH(const QString &line, definition) {
        w = 0;
        for (auto it = line.begin(); it != line.end(); ++it) {
            switch(it->toAscii()) {
            case ' ':
                part.append(Level::Field::EMPTY);
                break;
            case '#':
                part.append(Level::Field::WALL);
                break;
            case '@':
                part.append(Level::Field::PLAYER);
                break;
            case '+':
                part.append(Level::Field::PLAYER_ON_GOAL);
                break;
            case '$':
                part.append(Level::Field::BOX);
                break;
            case '*':
                part.append(Level::Field::BOX_ON_GOAL);
                break;
            case '.':
                part.append(Level::Field::GOAL);
                break;
            default:
                qCritical() << "incorrect level description" << it->toAscii();
                return Level();
            }
            ++w;
            maxw = qMax(maxw, w);
        }
        map.append(part);
        part.clear();
    }
    for (auto it = map.begin(); it != map.end(); ++it)
        while (it->count() < maxw)
            it->append(Level::Field::EMPTY);
    return Level(map, name);
}

QString TxtParser::levelSetName()
{
    QFile file(m_file);
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_file;
        return QString();
    }
    QTextStream in(&file);
    QString name;
    if (!in.atEnd())
        name = in.readLine().mid(2);
    file.close();
    return name;
}

QString TxtParser::levelName(int index)
{
    QString name;
    if (getLevelInfo(index, NULL, &name)) {
        return name;
    }
    return QString();
}

int TxtParser::levelCount()
{
    return 1;
}
