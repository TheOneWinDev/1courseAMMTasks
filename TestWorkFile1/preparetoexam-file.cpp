#include "functions.h"

int numof(string filename);

int main()
{
    fstream file;
    string filename;
    cout << "Введите путь к файлу:\n";
    cin >> filename;
    file.open(filename);

    if (!file)
    {
        cout << "no file\n";
        return 0;
    }

    int count = numof(filename);
    int *mass = new int[count];

    for (int i = 0; i < count; i++)
        file >> mass[i];

    cout << "Вывод файла:\n";

    for (int i = 0; i < count; i++)
    {
        cout << mass[i] << ' ';
    }

    cout << "\n";

    file.close();
    return 0;
}