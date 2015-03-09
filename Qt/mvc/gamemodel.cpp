#include "gamemodel.h"

GameModel::GameModel()
{
}

void GameModel::resetGame()
{
    for (int x=0; x<3; x++)
        for (int y=0; y<3; y++)
            area[(x*3)+y] = SYMBOL_NONE;
}
