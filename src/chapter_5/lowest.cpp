// Find lowest integer and zero them

#include <iostream>

using namespace std;

void zeroSmaller(int& a, int& b);

int main()
{
    int a, b;

    cout << "Print first number: ";
    cin >> a;

    cout << "Print second number: ";
    cin >> b;

    zeroSmaller(a, b);

    cout << "First number: " << a << endl
    << "Second number: " << b << endl;

    return 0;
}

void zeroSmaller(int& a, int& b)
{
    if (a < b) {
        a = 0;
    } else if (a > b) {
        b = 0;
    } 
}