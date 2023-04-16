#include <iostream>
#define coutx2 endl << endl
using namespace std;

struct biblcard {
    string title;
    string spez;
    string city;
    string publisher;
    int pages;
};

biblcard* fill(int n)
{
    biblcard* books = new biblcard[n];
    for (int i = 0; i < n; i++)
    {
        books[i].title = "inf C++";
        books[i].spez = "inf";
        books[i].city = "Voronezh";
        books[i].publisher = "Piter";
        books[i].pages = rand()%100;
    }
    return books;
}

void output(biblcard *books, int n)
{
    if (n >= 0 && books[n].title != "" && books[n].spez != "" && books[n].city != "" && books[n].publisher != "" && books[n].pages >= 0)
    {
        cout << "-----------------------------------" << endl;
        cout << books[n].title << endl;
        cout << books[n].spez << endl;
        cout << books[n].city << endl;
        cout << books[n].publisher << endl;
        cout << books[n].pages << endl;
        cout << "-----------------------------------" << coutx2;
    }
}

int main()
{
    biblcard *books;
    int n = 10;
    books = fill(n);
    output(books, n);

    for (int i = 0; i < n; i++)
        if (books[i].spez == "inf")
            output(books, i);

    return 0;
}
