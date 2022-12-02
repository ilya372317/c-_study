//
// Created by Отинов Илья on 02.12.2022.
//

#include "iostream"
#include "iomanip"
#include "strstream"

using namespace std;

int main() {
    char buffer[80];

    strstream stream(buffer, 80);

    stream << "Ilya Otinov is programmer!"
    << setiosflags(ios::fixed) << setprecision(2) << 2.123 << endl;

    cout << buffer;
}
