//
// Created by ilya on 23.11.22.
//

#include "iostream"
#include "iomanip"

using namespace std;

int main() {
    cout.setf(ios::right);
    cout << setw(50) << hex << setfill('#') << "this is sparta!" << 40 << endl;

    char fill = cout.fill();

    cout << endl << "symbol for fill: " << fill << endl;
}
