#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "IController.h"

class ControlManager;

class MainMenuController : public IController
{
public:
    MainMenuController(ControlManager*);
    void input();
private:
    ControlManager* _parent;
};

#endif // MAINMENUCONTROLLER_H
