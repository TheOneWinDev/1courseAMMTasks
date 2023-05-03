#include <iostream>
#include <cstring>
using namespace std;

struct biblcard {
    char* fio;
    char* title;
    char* theme;
    char* city;
    char* izd;
    int year;
    int pages;
};

int countofminpages(biblcard* anybooks, int n)
{
    int min = 99999;
    bool iscounter = 0;
    int counter;
    for (int i = 0; i < n; i++)
        if (anybooks[i].pages < min && strcmp(anybooks[i].izd, "Питер") == 0)
        {
            iscounter = 1;
            min = anybooks[i].pages;
            counter = i;
        }
        else if (i == n-1 && iscounter == 0)
            return 0;
    return counter;
}

int main()
{
    int n = 4;
    biblcard* anybooks = new biblcard[n];

    anybooks[0].fio = new char[20];
    strcpy(anybooks[0].fio, "Вячеслав Гиндин А");
    anybooks[0].title = new char[20];
    strcpy(anybooks[0].title, "Программирование C++");
    anybooks[0].theme = new char[4];
    strcpy(anybooks[0].theme, "inf");
    anybooks[0].city = new char[8];
    strcpy(anybooks[0].city, "Воронеж");
    anybooks[0].izd = new char[6];
    strcpy(anybooks[0].izd, "Питер");
    anybooks[0].year = 2004;
    anybooks[0].pages = 350;

    anybooks[1].fio = new char[18];
    strcpy(anybooks[1].fio, "Вадим Ястреб М");
    anybooks[1].title = new char[20];
    strcpy(anybooks[1].title, "Программирование C++");
    anybooks[1].theme = new char[4];
    strcpy(anybooks[1].theme, "inf");
    anybooks[1].city = new char[8];
    strcpy(anybooks[1].city, "Воронеж");
    anybooks[1].izd = new char[6];
    strcpy(anybooks[1].izd, "Питер");
    anybooks[1].year = 2008;
    anybooks[1].pages = 501;

    anybooks[2].fio = new char[20];
    strcpy(anybooks[2].fio, "Ярослав Филатов У");
    anybooks[2].title = new char[20];
    strcpy(anybooks[2].title, "Программирование C++");
    anybooks[2].theme = new char[5];
    strcpy(anybooks[2].theme, "math");
    anybooks[2].city = new char[7];
    strcpy(anybooks[2].city, "Москва");
    anybooks[2].izd = new char[6];
    strcpy(anybooks[2].izd, "Питер");
    anybooks[2].year = 2019;
    anybooks[2].pages = 403;

    anybooks[3].fio = new char[20];
    strcpy(anybooks[3].fio, "Вячеслав Гиндин А");
    anybooks[3].title = new char[20];
    strcpy(anybooks[3].title, "Программирование C++");
    anybooks[3].theme = new char[4];
    strcpy(anybooks[3].theme, "inf");
    anybooks[3].city = new char[8];
    strcpy(anybooks[3].city, "Воронеж");
    anybooks[3].izd = new char[6];
    strcpy(anybooks[3].izd, "Питер");
    anybooks[3].year = 2004;
    anybooks[3].pages = 200;

    int num = countofminpages(anybooks, n);
    cout << anybooks[num].pages << endl;
    for (int i = 0; i < n; i++) {
    delete[] anybooks[i].fio;
    delete[] anybooks[i].title;
    delete[] anybooks[i].theme;
    delete[] anybooks[i].city;
    delete[] anybooks[i].izd;
}
delete[] anybooks;

return 0;
}