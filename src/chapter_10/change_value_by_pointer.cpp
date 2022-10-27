//
// Created by ilya on 26.10.22.
//

#include "iostream"

using namespace std;

int main() {
    int var1, var2;

    int* pVar1 = &var1;

    *pVar1 = 10;

    var2 = *pVar1;

    cout << "expected: 10, actual: " << var2 << endl;
}
