#include <iostream>
using namespace std;

struct biblcard {
    string fio;
    string title;
    string theme;
    string city;
    string izd;
    int year;
    int pages;
};

int countofminpages(biblcard *anybooks, int n)
{
    int min = 99999;
    bool iscounteru = 0; // Использовать глобальную переменную
    int counter;
    for (int i = 0; i < n; i++)
        if (anybooks[i].pages < min && anybooks[i].izd == "Питер" && anybooks[i].theme == "inf")
        {
            iscounteru = 1; // Обновить значение глобальной переменной
            min = anybooks[i].pages;
            counter = i;
        }
    if (!iscounteru)
        return -1;
    return counter;
}

int main()
{
    int n = 4;
    biblcard* anybooks = new biblcard[n];

    anybooks[0].fio = "Вячеслав Гиндин А";
    anybooks[0].title = "Программирование C++";
    anybooks[0].theme = "inf";
    anybooks[0].city = "Воронеж";
    anybooks[0].year = 2004;
    anybooks[0].izd = "Питер";
    anybooks[0].pages = 350;
    anybooks[1].fio = "Вадим Ястреб М";
    anybooks[1].title = "Программирование C++";
    anybooks[1].theme = "inf";
    anybooks[1].city = "Воронеж";
    anybooks[1].year = 2008;
    anybooks[1].izd = "Питер";
    anybooks[1].pages = 501;
    anybooks[2].fio = "Ярослав Филатов У";
    anybooks[2].title = "Программирование C++";
    anybooks[2].theme = "math";
    anybooks[2].city = "Москва";
    anybooks[2].year = 2019;
    anybooks[2].izd = "Питер";
    anybooks[2].pages = 403;
    anybooks[3].fio = "Вячеслав Гиндин А";
    anybooks[3].title = "Программирование C++";
    anybooks[3].theme = "inf";
    anybooks[3].city = "Воронеж";
    anybooks[3].year = 2004;
    anybooks[3].izd = "Питер";
    anybooks[3].pages = 200;

    int num = countofminpages(anybooks, n);
    if (num == -1) {
           cout << "Книга не найдена" << endl;
           return 0;
    }
    cout << anybooks[num].pages << endl;

    delete[] anybooks;

    return 0;

}