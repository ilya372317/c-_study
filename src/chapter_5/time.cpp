// time

#include <iostream>

using namespace std;

int times2(int a);

int main()
{
    int a = 2;

    a = times2(a);

    cout << a << endl;

    return 0;
}

int times2(int a)
{
    return a*2;
}