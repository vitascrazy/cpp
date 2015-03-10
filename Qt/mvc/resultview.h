#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <iostream>
using namespace std;

#include "IView.h"

class ResultView : public IView
{
public:
    ResultView();
    void print();
};

#endif // RESULTVIEW_H
