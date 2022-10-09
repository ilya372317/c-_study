//
// Created by ilya on 05.10.22.
//

#include "iostream"
#include "cstring"

using namespace std;

const int MAX = 80;

int main() {
    char str1[] = "Wake up large country!";
    char str2[MAX];

    for (int i = 0; i < strlen(str1); i++) {
        str2[i] = str1[i];
    }

    cout << "Copy string is: " << str2 << endl;
}