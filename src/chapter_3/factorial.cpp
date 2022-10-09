// get factorial of number

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "print number for get factorial" << endl;

    int num = 0;

    cin >> num;

    double result = 1;

    for (int i = num; i > 0; i--) {
        result *= i;
    }
    cout << result << endl;

    return 0;
}