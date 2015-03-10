#ifndef SPLASHVIEW_H
#define SPLASHVIEW_H

#include "IView.h"
#include <iostream>
using namespace std;

class SplashView : public IView
{
public:
    SplashView();
    virtual void print();
};

#endif // SPLASHVIEW_H
