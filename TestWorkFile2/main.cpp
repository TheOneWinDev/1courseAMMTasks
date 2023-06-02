#include <iostream>
#include "books.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string filename = "books.txt";
    int n = lencounter(filename);
    book *books = new book[n];
    fillbook(filename, books, n);
    cout << "Исходный массив\n";
    printbooks(books, n);
    filterbooks(books, n);
    cout << "\nС учетом фильтра\n";
    printbooks(books, n);
    cout << "\nИтоговый результат\n";
    printfilterbooks(books, n);
    cin.get();
    return 0;
}