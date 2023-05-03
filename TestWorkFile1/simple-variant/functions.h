#include <iostream>
#include <fstream>
using namespace std;

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
