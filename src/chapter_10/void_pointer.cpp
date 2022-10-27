//
// Created by ilya on 26.10.22.
//

#include "iostream"

using namespace std;

int main() {
    int integerVar = 1;
    float floatVar = 1.1f;
    int* integerPointer = &integerVar;
    float* floatPointer = &floatVar;
    void* voidPointer = &integerVar;

    cout << "Integer pointer value: " << *integerPointer << endl
    << "Float pointer value: " << *floatPointer << endl
    << "Void pointer value: " << voidPointer << endl;
}
