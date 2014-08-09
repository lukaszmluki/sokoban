#ifndef LEVELSET_H
#define LEVELSET_H

#include <QObject>
#include <QString>
#include <QList>
#include "level.h"

class LevelSet : public QObject
{
    Q_OBJECT
public:
    explicit LevelSet(const QString &file, QObject *parent = 0);
    ~LevelSet();

    int count() const { return m_levels.count(); }
    QString name() const { return m_name; }
    const Level* level(int index) const { return m_levels.at(index); }

signals:

public slots:

private:
    bool load();

    QString m_file;
    QString m_name;
    QList<const Level *> m_levels;
};

#endif // LEVELSET_H
