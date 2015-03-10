#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <iostream>
using namespace std;

#include "IView.h"

class MainMenuView : public IView
{
public:
    MainMenuView();
    void print();
};

#endif // MAINMENUVIEW_H
