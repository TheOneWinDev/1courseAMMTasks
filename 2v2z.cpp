#include <iostream>
using namespace std;

struct midsessionmark
{
    int math;
    int phys;
    int inf;
    int alg;
    bool allisdone() {
        if (this->math != 2 && this->phys != 2 && this->inf != 2 && this->alg != 2)
            return 1;
        else
            return 0; 
    }
};

struct sessionmark
{
    int math;
    int rus;
    int inf;
    int alg;
};

struct student
{
    string fio;
    int grade;
    string faculty;
    sessionmark marks1;
    midsessionmark marks2;
};

void fillmass(int n, student *students)
{   for (int i = 0; i < n; i++)
    {
        students[i].fio = "Student_" + to_string(i);
        students[i].marks2.math = 2+(rand()%4);
        students[i].marks2.phys = 2+(rand()%4);
        students[i].marks2.inf = 2+(rand()%4);
        students[i].marks2.alg = 2+(rand()%4);
    }
}

void output(int n, student *students)
{
    int i = n;
    cout << students[i].fio << endl;
    cout << students[i].marks2.math << endl;
    cout << students[i].marks2.phys << endl;
    cout << students[i].marks2.inf << endl;
    cout << students[i].marks2.alg << endl;
    cout << students[i].marks2.allisdone() << endl;
}

void outputifdone(int n, student *students)
{
    for (int i = 0; i < n; i++)
        if (students[i].marks2.allisdone())
            {
                cout << students[i].fio << endl;
                cout << students[i].marks2.math << endl;
                cout << students[i].marks2.phys << endl;
                cout << students[i].marks2.inf << endl;
                cout << students[i].marks2.alg << endl << endl;
            }
}

int main()
{
    student students[10];

    fillmass(10, students);

    outputifdone(10, students);

    return 0;
}