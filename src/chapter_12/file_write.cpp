//
// Created by Отинов Илья on 24.11.2022.
//

#include "fstream"
#include "string"
#include "iostream"
#include "cstring"

using namespace std;

int main() {
    int buffer[80];

    for (int i = 0; i < 80; i++) {
        buffer[i] = i;
    }

    ifstream  inputFile("data.txt", ios::binary);

    int newBuffer[80];

    inputFile.read(reinterpret_cast<char*>(newBuffer), 80 * sizeof(int));

    for (int i = 0; i < 80; i++) {
        cout << *(newBuffer + i) << endl;
    }

    return 0;
}
