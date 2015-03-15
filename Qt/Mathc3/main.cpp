#include <iostream>
#include <cstdlib>

using namespace std;

#define WIDTH 10
#define HEIGHT 10

void printArea();

// VARS
int area[WIDTH][HEIGHT];
void newItem(int, int);
void phisics();
void destroyItem(int, int);
void gravitation(int, int);
void fillNull();
void matchItems(int x, int y, int color=0);

int main()
{
    cout << "Game phisics for Match 3!" << endl;

    for (int y=0; y<HEIGHT; y++)
    {
        for (int x=0; x<WIDTH; x++)
        {
            newItem(x, y);
        }
    }

    do
    {
        //phisics();
        printArea();
        cout << "Coordinaty: ";
        int x, y;
        cin >> x >> y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        {
            cout << x << " & " << y << endl;
            //destroyItem(x, y);
            matchItems(x, y);
        }
        else
            cout << "Error coordinat!" << endl;
    }
    while (true);

    return 0;
}

void newItem(int x, int y)
{
    area[x][y] = (rand()%4)+1;
}

void printArea()
{
    for (int y=-1; y<HEIGHT; y++)
    {
        for (int x=0; x<WIDTH; x++)
        {
            //cout << area[x][y] << (x == WIDTH-1?"":", ");
            if (x == 0)
            {
                if (y < 0)
                    cout << "   ";
                else
                    cout << y << ". ";
            }
            if (y < 0)
                cout << x;
            else
            {
                char sym[] = {' ', '@', '#', '$', '%', '&', '*'};
                cout << sym[area[x][y]];
            }
        }
        cout << endl;
    }
}

void destroyItem(int x, int y)
{
    cout << "!!!destroy" << endl;
    area[x][y] = 0;
}

void phisics()
{
    cout << "Phisic" << endl;
    for (int y=HEIGHT-1; y>0; y--)
    {
        for (int x=0; x<WIDTH; x++)
        {
            if (area[x][y] == 0)
            {
                gravitation(x, y);
                /*for (int i=y; i>0; i--)
                {
                    area[x][i] = area[x][i-1];
                }*/
            }
        }
    }
}

void gravitation(int x, int y)
{
    if (y == 0)
        return;
    if (area[x][y-1] == 0)
        gravitation(x, y-1);
    else
    {
        area[x][y] = area[x][y-1];
        area[x][y-1] = 0;
    }
}

void fillNull()
{
    for (int x=0; x<WIDTH; x++)
    {
        for (int y=0; y<HEIGHT; y++)
        {
            if (area[x][y] == 0)
                newItem(x, y);
        }
    }
}

void matchItems(int x, int y, int color)
{
    if (color == 0)
        color = area[x][y];

    int d[4][2] = {
        {0, -1},
        {1, 0},
        {0, 1},
        {-1, 0}
    };

    area[x][y] = 0;
    int size = sizeof(d)/sizeof(int);
    for (int i=0; i<size; i++)
    {
        int _x = x+d[i][0];
        int _y = y+d[i][1];
        if (_x >= 0 && _x < WIDTH && _y >= 0 && _y < HEIGHT)
        {
            if (area[_x][_y] == color)
                matchItems(_x, _y, color);

        }
    }
    //area[x][y] = 0;
}
