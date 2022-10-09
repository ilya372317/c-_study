// check overload
#include <iostream>

using namespace std;

int bar(char a);
int bar(char a, char b);

int main()
{
    bar('1');
    bar('2', '3');
}

int bar(char a)
{
    cout << a << endl;
    return 1;
}

int bar(char a, char b)
{
    cout << a << b << endl;
    return 2;
}
