#include "mainmenuview.h"

#include "mainmenucontroller.h"

MainMenuView::MainMenuView()
{
}

void MainMenuView::print()
{
    system("cls");
    cout << "Main menu:" << endl;
    cout << endl;
    cout << "1. Start game" << endl;
    cout << "2. Quit game"<< endl;
}
