#ifndef CONTROLLERMANAGER_H
#define CONTROLLERMANAGER_H

#include "IController.h"
#include "gamemodel.h"
#include "viewmanager.h"
#include "IObserver.h"

#include "splashcontroller.h"
#include "mainmenucontroller.h"
#include "selectsymbolcontroller.h"
#include "gamecontroller.h"
#include "resultcontroller.h"

class ControlManager : public IObserver
{
public:
    ControlManager(GameModel*);
    void start();
    virtual void update();
    virtual void updateScene();
    void setView(ViewManager*);
    GameModel* _model = NULL;
private:
    IController* _controller = NULL;
    ViewManager* _view = NULL;
};

#endif // CONTROLLERMANAGER_H
