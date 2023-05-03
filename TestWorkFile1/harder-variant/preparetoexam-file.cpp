#include "functions.h"

int main()
{
    string filename;
    cin >> filename;
    isfile(filename);
    ifstream file;
    Pokemon *mass = new Pokemon[linecount(filename)];
    file.open(filename);
    readfile(filename, mass);

    cout << mass[1].name << ' ';
    cout << mass[1].strenght << ' ';
    switch (mass[1].ability)
    {
    case Stone:
        cout << "Stone";
        break;
    case Water:
        cout << "Water";
        break;
    case Lightning:
        cout << "Lightning";
        break;
    case Fire:
        cout << "Fire";
        break;
    };

    cout << '\n';

    return 0;
}
