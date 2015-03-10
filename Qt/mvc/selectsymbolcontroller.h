#ifndef SELECTSYMBOLCONTROLLER_H
#define SELECTSYMBOLCONTROLLER_H

#include "IController.h"

class ControlManager;

class SelectSymbolController : public IController
{
public:
    SelectSymbolController(ControlManager*);
    void input();

private:
    ControlManager* _parent;
};

#endif // SELECTSYMBOLCONTROLLER_H
