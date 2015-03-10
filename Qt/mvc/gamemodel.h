#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "subject.h"

class GameModel : public Subject
{
public:
    enum SYMBOLS {
        SYMBOL_NONE = 0,
        SYMBOL_X,
        SYMBOL_Y,
    };

    enum RESULT {
        RESULT_NONE = 0,
        RESULT_DRAW,
        RESULT_WINX,
        RESULT_WINY,
    };

    enum SCREENS {
        SCREEN_SPLASH = 0,
        SCREEN_MAINMENU,
        SCREEN_SELECTSYMBOL,
        SCREEN_GAME,
        SCREEN_RESULT,
    };

private:
    SYMBOLS area[9] {SYMBOL_NONE};
    SYMBOLS symbolPlayer;
    SCREENS scene;

    RESULT checkOutVictory();
public:
    GameModel();
    void resetGame();
    void setSymbolPlayer(SYMBOLS symbol);
    void movePlayer(int pos);
    void setScene(SCREENS scene = SCREEN_SPLASH);
    void setModeScreen(SCREENS screen);
    SCREENS getModeScreen();
};

#endif // GAMEMODEL_H
