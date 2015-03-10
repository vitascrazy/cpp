#ifndef RESULTCONTROLLER_H
#define RESULTCONTROLLER_H

#include "IController.h"

class ControlManager;

class ResultController : public IController
{
public:
    ResultController(ControlManager*);
    void input();

private:
    ControlManager* _parent;
};

#endif // RESULTCONTROLLER_H
