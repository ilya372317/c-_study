// Counter of call

#include <iostream>

using namespace std;

inline int counter();

int main()
{
    for (int i = 0; i < 100; i++) {
        cout << counter() << endl;
    }

    int a = 228;

    int *pA = &a;

    cout << *pA << endl;
}

inline int counter()
{
    static int counter = 0;
    counter++;

    return counter;
}
