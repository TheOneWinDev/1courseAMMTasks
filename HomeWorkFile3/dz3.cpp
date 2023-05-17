#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream in("Data.txt");
    char symbol;
    int counters[26] = {};
    while (in.get(symbol))
        if (tolower(symbol) >= 97 && tolower(symbol) <= 122)
        {
            counters[tolower(symbol) - 97]++;
        }

    int max = 0, counter = 0;
    for (int i = 0; i <= 26; i++)
    {
        if (counters[i] >= max)
        {
            max = counters[i];
            counter = i;
        }
    }
    cout << "The most popular symbol in file is: " << (char)(97 + counter) << endl;
    return 0;
}