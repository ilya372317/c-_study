// divido

#include <iostream>

using namespace std;

int main(int argv, char *argc[])
{
    long dividor, divisor;
    char response;
    do {
        cout << "Print dividor: ";
        cin >> dividor;

        cout << "Print divisor: ";
        cin >> divisor;

        cout << "Private = " << dividor / divisor << endl
        << "Modulo = " << dividor % divisor 
        << endl << endl << "Do it againg? [y/n]" << endl;

        cin >> response;

    } while (response != 'n');
    {
        return 0;
    }
}