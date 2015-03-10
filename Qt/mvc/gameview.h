#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <iostream>
using namespace std;

#include "IView.h"

class GameView : public IView
{
public:
    GameView();
    void print();
};

#endif // GAMEVIEW_H
