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

GameModel::RESULT GameModel::checkOutVictory()
{
    return RESULT_NONE;
}

void GameModel::setSymbolPlayer(SYMBOLS symbol)
{
    //
}

void GameModel::movePlayer(int pos)
{
    //
}

void GameModel::setModeScreen(SCREENS screen)
{
    this->scene = screen;
}

void GameModel::setScene(SCREENS scene)
{
    this->scene = scene;
    notifyAllScenes();
}

GameModel::SCREENS GameModel::getModeScreen()
{
    return scene;
}
