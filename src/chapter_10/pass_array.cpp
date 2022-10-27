//
// Created by ilya on 26.10.22.
//

#include "iostream"

using namespace std;

const int MAX = 5;

void centimize(double* array);

int main() {
    double array[MAX] = {1.1, 2.2, 3.3, 4.4, 5.5};

    cout << "Value in duems: " << endl;
    for (double item : array) {
        cout << item << endl;
    }
    centimize(array);

    cout << "Value in santimeters: " << endl;
    for (double item : array) {
        cout << item << endl;
    }
}

void centimize(double* array) {
    for (int i = 0; i < MAX; i++) {
        *(array++) *= 2.54;
    }
}