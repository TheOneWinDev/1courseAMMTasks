#include <fstream>
#include <string>
using namespace std;

struct book
{
    string initials;
    string title;
    string spez;
    string publisher_city;
    string publisher;
    int year;
    int pages;
};

int getbooks(string filename);

int lencounter(string filename);

void fillbook(string filename, book *books, int n);

void printbooks(book *books, int n);

void filterbooks(book *&books, int n);

void printfilterbooks(book *books, int n);