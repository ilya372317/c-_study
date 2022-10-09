//
// Created by ilya on 05.10.22.
//

#include "iostream"

using namespace std;

const int MAX = 80;

int main() {
    char str[MAX];
    cout << "Print a string" << endl;

    cin.get(str, MAX, '$');

    cout << "You print: " << str << endl;
}
