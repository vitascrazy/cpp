#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "IController.h"

class ControlManager;

class GameController : public IController
{
public:
    GameController(ControlManager*);
    void input();
private:
    ControlManager* _parent;
};

#endif // GAMECONTROLLER_H
