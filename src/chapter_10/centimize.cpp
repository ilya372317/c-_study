//
// Created by ilya on 26.10.22.
//

#include "iostream"

using namespace std;

void centimize(double* v);

int main() {
    double var = 10.0;

    cout << "var = " << var << "дюймов" << endl;

    centimize(&var);

    cout << "var = " << var << "santimetrov" << endl;
}

void centimize(double* v) {
    *v *= 2.54;
}
