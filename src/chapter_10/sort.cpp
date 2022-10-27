//
// Created by ilya on 27.10.22.
//
// My first sorting programm write on c++
//

#include "iostream"

using namespace std;

void order(int *first, int *second);

void bsort(int *array, int arrayLength);

void msort(int *array, int arrayLength);

const int MAX = 10;

int main() {
    int arr[MAX] = {9, 3, 2, 1, 5, 4, 3, 6, 7, 8};

    bsort(arr, MAX);

    for (int i: arr) {
        cout << i << endl;
    }

    cout << "array after msort: " << endl;

    msort(arr, MAX);

    for (int i: arr) {
        cout << i << endl;
    }

    return 0;
}

void order(int *first, int *second) {
    if (*first > *second) {
        int temp = *first;
        *first = *second;
        *second = temp;
    }
}

void msort(int *arr, int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        for (int k = i + 1; k < arrayLength; k++) {
            order(arr + k, arr + i);
        }
    }
}

void bsort(int *arr, int arrayLength) {
    for (int i = 0; i < arrayLength - 1; i++) {
        for (int k = i + 1; k < arrayLength; k++) {
            order(arr + i, arr + k);
        }
    }
}

