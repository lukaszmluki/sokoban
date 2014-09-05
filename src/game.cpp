#include "game.h"

Game::Game(const Level &level) :
    m_map(level.getMap())
{
}

Level::Field Game::spot(int x, int y) const
{
    return m_map.at(y).at(x);
}
