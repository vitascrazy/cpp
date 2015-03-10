#include "controlmanager.h"

ControlManager::ControlManager(GameModel* model) : _model(model)
{
    _model->init(this);
}

void ControlManager::setView(ViewManager* view)
{
    _view = view;
}

void ControlManager::start()
{
    _model->setScene();
    do
    {
        _model->notifyAllObservers();
    }
    while (true);
}

void ControlManager::update()
{
    if (_controller != NULL)
        _controller->input();
}

void ControlManager::updateScene()
{
    if (_controller != NULL)
        delete _controller;

    switch (_model->getModeScreen())
    {
    case _model->SCREENS::SCREEN_SPLASH:
        _controller = new SplashController(this);
        break;

    case _model->SCREENS::SCREEN_MAINMENU:
        _controller = new MainMenuController(this);
        break;

    case _model->SCREENS::SCREEN_SELECTSYMBOL:
        _controller = new SelectSymbolController(this);
        break;

    case _model->SCREENS::SCREEN_GAME:
        _controller = new GameController(this);
        break;

    case _model->SCREENS::SCREEN_RESULT:
        _controller = new ResultController(this);
        break;
    }
}
