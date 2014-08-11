#include "levelmanager.h"
#include <QDebug>
#include <QDir>

LevelManager::LevelManager(QObject *parent) :
    QObject(parent),
    m_levelSetIndex(-1),
    m_levelIndex(-1)
{
    auto addPath = [](const QString &file) -> QString
    {
        return QDir::homePath().append(QDir::separator()).
               append(".sokoban").append(QDir::separator()).append("levels").
               append(QDir::separator()).append(file);
    };
    m_sets.append(new LevelSet(addPath("AKK_Informatika.txt"), this));
}

LevelManager::~LevelManager()
{
}

LevelManager& LevelManager::instance()
{
    static LevelManager instance;
    return instance;
}

bool LevelManager::selectLevel(int levelSetIndex, int levelIndex)
{
    if (levelSetIndex >= m_sets.count() || levelIndex >= m_sets.at(levelSetIndex)->count()) {
        m_selectedLevel = Level();
        m_levelSetIndex = -1;
        m_levelIndex = -1;
        emit levelSelected();
        return false;
    }

    m_levelSetIndex = levelSetIndex;
    m_levelIndex = levelIndex;
    m_selectedLevel = *(m_sets.at(levelSetIndex)->level(levelIndex));
    emit levelSelected();
    return true;
}
