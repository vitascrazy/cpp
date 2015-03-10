#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include "IObserver.h"
#include "gamemodel.h"
//#include "controlmanager.h"
#include "IView.h"

#include "splashview.h"
#include "mainmenuview.h"
#include "selectsymbolview.h"
#include "gameview.h"
#include "resultview.h"

class ControlManager;

class ViewManager : public IObserver
{
public:
    ViewManager(GameModel*, ControlManager*);
    virtual void update();
    virtual void updateScene();

private:
    GameModel* _model = NULL;
    ControlManager* _controller = NULL;
    IView* _view = NULL;
};

#endif // VIEWMANAGER_H
