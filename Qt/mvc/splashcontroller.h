#ifndef SPLASHCONTROLLER_H
#define SPLASHCONTROLLER_H

#include "IController.h"

class ControlManager;

class SplashController : public IController
{
public:
    SplashController(ControlManager*);
    void input();

private:
    int counter = 1000;
    ControlManager* _parent;
};

#endif // SPLASHCONTROLLER_H
