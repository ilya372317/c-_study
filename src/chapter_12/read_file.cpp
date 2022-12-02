//
// Created by Отинов Илья on 02.12.2022.
//

#include "fstream"
#include "iostream"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream is;

    is.open(*(argv + 1));

    if (!is) {
        cerr << "Failed to open file!" << endl;
        exit(1);
    }

    char ch;

    while (is.get(ch)) {
        cout << ch;
    }
}
