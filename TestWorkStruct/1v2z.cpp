#include <iostream>
using namespace std;

struct param {
    int size1;
    int size2;
    int size3;
};

struct miss {
    int number;
    int height;
    int mass;
    param parameters;
};

int numwithminimanparam(miss *missarray, int n)
{
    int min = 9999;
    int counter, allmass;
    for (int i = 0; i < n; i++)
    {
        allmass = missarray[i].parameters.size1 + missarray[i].parameters.size2 + missarray[i].parameters.size3;
        if (allmass < min)
        {
            min = allmass;
            counter = i;
        }
    }
    return counter+1;
}

int main()
{
    int n = 3;
    miss* missarray = new miss [n];
    missarray[0].parameters.size1 = 10;
    missarray[0].parameters.size2 = 30;
    missarray[0].parameters.size3 = 60;
    missarray[1].parameters.size1 = 20;
    missarray[1].parameters.size2 = 90;
    missarray[1].parameters.size3 = 100;
    missarray[2].parameters.size1 = 10;
    missarray[2].parameters.size2 = 10;
    missarray[2].parameters.size3 = 10;

    cout << numwithminimanparam(missarray, n) << endl;

    cin.get();

    return 0;
}