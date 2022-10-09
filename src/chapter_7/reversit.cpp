//
// Created by ilya on 06.10.22.
//

#include "iostream"
#include "cstring"
#include "climits"

using namespace std;

void revers(char str[]) {
    char newStr[strlen(str)];

    for (unsigned long i = strlen(str), k = 0; i > 0; i--, k++) {
        newStr[k] = str[i - 1];
    }

    strcpy(str, newStr);
}

int main() {
    char myStr[] = "ABC";

    revers(myStr);

    cout << myStr << endl;

    unsigned long test = 2;
    test--;
    cout << test << endl;
}