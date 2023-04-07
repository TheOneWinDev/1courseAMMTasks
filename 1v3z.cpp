#include <iostream>
#include <cmath>
using namespace std;

enum colors {RED, BLUE, WHITE, BLACK, GREEN};

struct coord
{
    int coord1;
    int coord2;
};

struct sphere {
    colors color;
    coord position;
    float closetocenter;
};

int main()
{

    int n = 50;
    sphere* spheres = new sphere[n];
    for (int i = 0; i < n-40; i++)
    {
        spheres[i].color = RED;
        spheres[i].position.coord1 = rand()%5-3;
        spheres[i].position.coord2 = rand()%5-3;
        spheres[i].closetocenter = sqrt(pow(spheres[i].position.coord1, 2) + pow(spheres[i].position.coord2, 2));
    }
    for (int i = n-40; i < n-30; i++)
    {
        spheres[i].color = BLUE;
        spheres[i].position.coord1 = rand()%5-3;
        spheres[i].position.coord2 = rand()%5-3;
        spheres[i].closetocenter = sqrt(pow(spheres[i].position.coord1, 2) + pow(spheres[i].position.coord2, 2));
    }
    for (int i = n-30; i < n-20; i++)
    {
        spheres[i].color = WHITE;
        spheres[i].position.coord1 = rand()%5-3;
        spheres[i].position.coord2 = rand()%5-3;
        spheres[i].closetocenter = sqrt(pow(spheres[i].position.coord1, 2) + pow(spheres[i].position.coord2, 2));
    }
    for (int i = n-20; i < n-10; i++)
    {
        spheres[i].color = BLACK;
        spheres[i].position.coord1 = rand()%5-3;
        spheres[i].position.coord2 = rand()%5-3;
        spheres[i].closetocenter = sqrt(pow(spheres[i].position.coord1, 2) + pow(spheres[i].position.coord2, 2));
    }
    for (int i = n-10; i < n; i++)
    {
        spheres[i].color = GREEN;
        spheres[i].position.coord1 = rand()%5-2;
        spheres[i].position.coord2 = rand()%5-4;
        spheres[i].closetocenter = sqrt(pow(spheres[i].position.coord1, 2) + pow(spheres[i].position.coord2, 2));
    }

    float min = 999;
    int counter;

    for (int i = 0; i < n; i++)
    {   
        if (spheres[i].closetocenter < min)
        {
        min = spheres[i].closetocenter;
        counter = i;
        }
    }

    cout << min << endl;
    cout << counter << endl;

    cout << "Цвет ";

    switch (spheres[counter].color) {
    case RED:
        cout << "RED";
            break;
    case BLUE:
        cout << "BLUE";
            break;
    case WHITE:
        cout << "WHITE";
            break;
    case BLACK:
        cout << "BLACK";
            break;
    case GREEN:
        cout << "GREEN";
            break;
    }

    cout << "\nКоординаты " << spheres[counter].position.coord1 << ' ' << spheres[counter].position.coord2 << endl;

    delete[] spheres;
    return 0;
}