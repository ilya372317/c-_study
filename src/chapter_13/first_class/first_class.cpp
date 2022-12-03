//
// Created by Отинов Илья on 03.12.2022.
//

#include "first_class.h"
#include "iostream"

using namespace std;

void first_class::showData() {
    cout << a << b;
}

void first_class::getData() {
    cout << "Print a: ";
    cin >> a;
    cout << "Print b: ";
    cin >> b;
}