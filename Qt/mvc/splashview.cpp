#include "splashview.h"

SplashView::SplashView()
{
}

void SplashView::print()
{
    system("cls");
    int rnd = rand()%40;
    for (int i=0; i<rnd; i++)
        cout << " ";
    cout << "Splash Screen" << endl;
}
