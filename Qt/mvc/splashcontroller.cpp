#include "splashcontroller.h"

#include "controlmanager.h"

SplashController::SplashController(ControlManager* control) : _parent(control)
{
}

void SplashController::input()
{
    counter--;
    if (counter > 0)
        return;

    _parent->_model->setScene(_parent->_model->SCREEN_MAINMENU);
}
