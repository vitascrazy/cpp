#include "viewmanager.h"
#include "controlmanager.h"

ViewManager::ViewManager(GameModel* model, ControlManager* controller) : _model(model), _controller(controller)
{
    _model->init(this);
    _controller->setView(this);
}

void ViewManager::update()
{
    if(_view != NULL)
        _view->print();
}

void ViewManager::updateScene()
{
    if (_view != NULL)
        delete _view;

    switch (_model->getModeScreen())
    {
    case _model->SCREENS::SCREEN_SPLASH:
        _view = new SplashView();
        break;

    case _model->SCREENS::SCREEN_MAINMENU:
        _view = new MainMenuView();
        break;

    case _model->SCREENS::SCREEN_SELECTSYMBOL:
        _view = new SelectSymbolView();
        break;

    case _model->SCREENS::SCREEN_GAME:
        _view = new GameView();
        break;

    case _model->SCREENS::SCREEN_RESULT:
        _view = new ResultView();
        break;
    }
}
