// Addition to fraction

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int a, b, c, d;
    char dummChar;

    cout << "print two fraction with this format: 1/2" << endl
    << "print first fraction" << endl;

    cin >> a >> dummChar >> b;

    cout << "print second fraction" << endl;

    cin >> c >> dummChar >> d;

    int numerator = a*d + b*c;
    int denumerator = b*d;

    cout << "result: " << numerator << "/" << denumerator << endl;
}