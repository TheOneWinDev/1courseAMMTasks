#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int numof(string filename);

int main()
{
    fstream file;
    file.open("/home/windev/Documents/kotokdz/pokemon.txt");
    if (!file)
    {
        cout << "no file\n";
        return 0;
    }
    int count = numof("/home/windev/Documents/kotokdz/pokemon.txt");
    int *mass = new int[count];
    for (int i = 0; i < count; i++)
        file >> mass[i];

    for (int i = 0; i < count; i++)
    {
        cout << mass[i] << ' ';
    }
    file.close();
    return 0;
}

int numof(string filename)
{
    int num = 0;
    string word;
    fstream file;
    file.open(filename);
    while (file >> word)
        num++;
    file.close();
    return num;
}