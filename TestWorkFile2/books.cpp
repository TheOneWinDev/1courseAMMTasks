#include <iostream>
#include "books.h"
using namespace std;

int getbooks(string filename)
{
    string books;
    ifstream file(filename);
    if (!file.is_open())
        return -1;
    getline(file, books);
    file.close();
    return stoi(books);
}

int lencounter(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
        return -1;
    string str;
    int count = 0;
    while (getline(file, str))
    {
        count++;
    }
    return count;
}

void fillbook(string filename, book *books, int n)
{
    fstream file(filename);
    for (int i = 0; i < n; i++)
    {
        file >> books[i].initials;
        file >> books[i].title;
        file >> books[i].spez;
        file >> books[i].publisher_city;
        file >> books[i].publisher;
        file >> books[i].year;
        file >> books[i].pages;
    }
}

void printbooks(book *books, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << books[i].initials << "\t"
             << books[i].title << "\t"
             << books[i].spez << "\t"
             << books[i].publisher_city << "\t"
             << books[i].publisher << "\t"
             << books[i].year << "\t"
             << books[i].pages << endl;
    }
}

void filterbooks(book *&books, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && books[i].initials == books[j].initials && books[i].title == books[j].title)
            {
                if (books[i].year > books[j].year)
                {
                    books[j].initials = "DELETED";
                }
                else
                {
                    books[i].initials = "DELETED";
                }
            }
        }
    }
}

void printfilterbooks(book *books, int n)
{
    for (int i = 0; i < n; i++)
        if (books[i].initials != "DELETED")
            cout << books[i].initials << "\t"
                 << books[i].title << "\t"
                 << books[i].spez << "\t"
                 << books[i].publisher_city << "\t"
                 << books[i].publisher << "\t"
                 << books[i].year << "\t"
                 << books[i].pages << endl;
}
