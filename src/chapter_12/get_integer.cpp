//
// Created by Отинов Илья on 24.11.2022.
//

#include "iostream"

using namespace std;

int main() {
    int i;
    cin.unsetf(ios::skipws);

    while (true) {
        cin >> i;

        if (cin.good()) {
            cin.ignore(10, '\n');
            break;
        }

        cin.clear();
        cout << "invalid integer, try again!" << endl;
        cin.ignore(10, '\n');
    }

    cout << "You integer is " << i << endl;
}
