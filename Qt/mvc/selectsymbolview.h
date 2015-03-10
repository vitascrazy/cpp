#ifndef SELECTSYMBOLVIEW_H
#define SELECTSYMBOLVIEW_H

#include <iostream>
using namespace std;

#include "IView.h"

class SelectSymbolView : public IView
{
public:
    SelectSymbolView();
    void print();
};

#endif // SELECTSYMBOLVIEW_H
