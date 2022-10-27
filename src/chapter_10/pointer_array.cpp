//
// Created by ilya on 26.10.22.
//

#include "iostream"

using namespace std;

int main() {
    // переменная array хранит адрес массива
    int array[5] = {1,2,3,4,5};
    int* pointer = array;

    for (int i = 0; i < 5; i++) {
        cout << "Value of array element: " <<  *(pointer++) << " ,address of element: " << pointer - 1 << endl;
    }

    cout << "address of array: " << array << "point to address of first element: " << *array << endl;
}
