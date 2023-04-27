#include <fstream>
#include <iostream>
#include <string>

using namespace std;

enum Type { WATER, POISON, WIND, STRIKE };

struct Pokemon {
    string name;
    int strenght;
    Type type;
};

int filelen(string filename)
{
    fstream file(filename);
    int count = 0;
    string line;
    while (getline(file, line))
        count++;

    return count;
}

int main()
{
    ifstream on;
    on.open("/Users/windev/Documents/sandbox/text.txt");
    if (!on)
    {
        cout << "none";
        return -1;
    }
    int n = filelen("/Users/windev/Documents/sandbox/text.txt");
    Pokemon* pokemons = new Pokemon[n];

for (int i = 0; i < n; i++)
{
    string type_str;
    on >> pokemons[i].name >> pokemons[i].strenght;
    getline(on, type_str);
    if (type_str == "WATER") {
        pokemons[i].type = WATER;
    } else if (type_str == "POISON") {
        pokemons[i].type = POISON;
    } else if (type_str == "WIND") {
        pokemons[i].type = WIND;
    } else if (type_str == "STRIKE") {
        pokemons[i].type = STRIKE;
    }
}
    for (int i = 0; i < n; i++)
    {
        cout << pokemons[i].name << ' ';
        cout << pokemons[i].strenght << ' ';
        switch(pokemons[i].type)
        {
            case WATER:
            cout << "water";
            break;
            case POISON:
            cout << "poison";
            break;
            case WIND:
            cout << "wind";
            break;
            case STRIKE:
            cout << "strike";
            break;
        }
    cout << '\n';
}

    on.close();
    delete[] pokemons;
    return 0;
}