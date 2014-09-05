#ifndef GAME_H
#define GAME_H

#include "level.h"

class Game
{
public:
    Game(const Level &level);

    Level::Field spot(int x, int y) const;

private:
    Level::LevelMap m_map;
};

#endif // GAME_H
