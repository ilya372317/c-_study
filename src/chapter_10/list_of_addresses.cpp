//
// Created by ilya on 25.10.22.
//

#include "iostream"

using namespace std;

int main() {
    int var1 = 1;
    int var2 = 2;
    int var3 = 3;

    int* var1Pointer = &var1;

    cout << "Address of var1 - " << &var1 << endl
    << "Address of var2 - " << &var2 << endl
    << "Address of var3 - " << &var3 << endl
    << "Value of var1 - " << *var1Pointer << endl;
}