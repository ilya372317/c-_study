// foo

#include <iostream>

using namespace std;

void foo(int& test);

int main()
{
    int test = 0;
    foo(test);
    
    foo(test);
}

void foo(int& test)
{
    cout << "foo" << endl;
    cout << test << endl;
    test += 1;
}