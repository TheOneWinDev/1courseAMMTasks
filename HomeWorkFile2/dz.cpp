// Топ 10 букв по входимости в файл (однострочный)
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string engalph = "abcdefghijklmnopqrstuvwxyz";
string upengalph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct symbol
{
    int count;
    char name;
} symbols[26];

void countsymb(string filename, symbol *symbols, const int n)
{
    fstream file;
    if (!file)
        return;
    file.open(filename);
    string str;
    getline(file, str);
    char symb;
    int max = 0, temp = 0;
    for (int j = 0; j < engalph.length(); j++)
    {
        symb = engalph[j];
        temp = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] == engalph[j] || str[i] == upengalph[j]) && str[i] != ' ')
            {
                temp += 1;
                str[i] = ' ';
            }
            if (max < temp)
            {
                symbols[j].count = temp;
                symbols[j].name = symb;
            }
        }
        if (max == 0)
            continue;
        max = 0;
    }

    file.close();

    for (int i = 0; i < engalph.length() - 1; i++)
    {
        for (int j = 0; j < engalph.length() - i - 1; j++)
        {
            if (symbols[j].count < symbols[j + 1].count)
            {
                symbol temp = symbols[j];
                symbols[j] = symbols[j + 1];
                symbols[j + 1] = temp;
            }
        }
    }

    cout << "Топ символов: " << endl;

    for (int i = 0; i < n; i++)
    {
        if (symbols[i].count != 0)
            cout << symbols[i].name << ": " << symbols[i].count << endl;
    }
}

int main()
{
    string filename = "/home/windev/kotokdz/kotokzfile.txt";
    countsymb(filename, symbols, 10);
    return 0;
}