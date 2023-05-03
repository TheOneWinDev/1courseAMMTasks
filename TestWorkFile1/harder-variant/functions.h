#include <fstream>
#include <string>
#include <iostream>

using namespace std;

enum Type
{
    Water,
    Stone,
    Lightning,
    Fire
};

struct Pokemon
{
    string name;
    int strenght;
    Type ability;
};

int linecount(string filename)
{
    ifstream file;
    file.open(filename);
    string word;
    int num;
    while (file >> word)
        num++;
    file.close();
    return num / 3;
}

void isfile(string filename)
{
    fstream file;
    file.open(filename);
    if (!file)
    {
        cout << "Файл не найден, выход из программы...\n";
        exit(1);
    }
    else
    {
        cout << "Файл найден, программа приступает к выполнению...\n";
    }
}

void readfile(string filename, Pokemon *mass)
{
    ifstream file;
    file.open(filename);
    int n = linecount(filename);
    for (int i = 0; i < n; i++)
    {
        string word;
        file >> mass[i].name;
        file >> mass[i].strenght;
        file >> word;
        if (word == "Water")
        {
            mass[i].ability = Water;
        }
        else if (word == "Stone")
        {
            mass[i].ability = Stone;
        }
        else if (word == "Lightning")
        {
            mass[i].ability = Lightning;
        }
        else if (word == "Fire")
        {
            mass[i].ability = Fire;
        }
    }
    file.close();
}