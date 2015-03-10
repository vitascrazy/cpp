#include <iostream>

using namespace std;

#include "gamemodel.h"
#include "controlmanager.h"
#include "viewmanager.h"

int main()
{
    cout << "Hello World!" << endl;

    GameModel* model = new GameModel();
    ControlManager* controller = new ControlManager(model);
    ViewManager* view = new ViewManager(model, controller);

    controller->start();


    return 0;
}

