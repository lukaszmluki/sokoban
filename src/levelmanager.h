#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QObject>
#include "levelset.h"
#include "level.h"

class LevelManager : public QObject
{
    Q_OBJECT
    explicit LevelManager(QObject *parent = 0);
    ~LevelManager();

public:
    static LevelManager& instance();
    bool selectLevel(int levelSetIndex, int levelIndex);
    const Level& selectedLevel() { return m_selectedLevel; }

signals:
    void levelSelected();

public slots:

private:
    QList<const LevelSet *> m_sets;
    Level m_selectedLevel;
    int m_levelSetIndex;
    int m_levelIndex;
};

#endif // LEVELMANAGER_H
