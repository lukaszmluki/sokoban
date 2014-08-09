#include "levelmanager.h"
#include <QDebug>

LevelManager::LevelManager(QObject *parent) :
    QObject(parent)
{
    m_sets.append(new LevelSet("AKK_Informatika.txt", this));
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
    //TODO: check range
    m_levelSetIndex = levelSetIndex;
    m_levelIndex = levelIndex;
    m_selectedLevel = *(m_sets.at(levelSetIndex)->level(levelIndex));
    emit levelSelected();
    return true;
}
