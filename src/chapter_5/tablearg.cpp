// my first function in c++

#include <iostream>

using namespace std;

void repchar(char, int);

int main()
{
    char ch;
    int count;
    
    cout << "Print character: ";
    cin >> ch;
    cout << "Print count of repeting: ";
    cin >> count;
    repchar(ch, count);
}

void repchar(char ch, int count)
{
    for (int num = 0; num <= count; num++)
    {
        cout << ch;
    }
    cout << endl;
}