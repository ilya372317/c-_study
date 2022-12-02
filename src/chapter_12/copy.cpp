//
// Created by Отинов Илья on 02.12.2022.
//

#include "fstream"
#include "iostream"
#include "cstring"

using namespace std;

const int MAX = 512;

int main(int argc, char* argv[]) {
    bool fileEquals = strcmp(*(argv + 1), *(argv + 2)) == 0;

    if (fileEquals) {
        cerr << "Not print same file to copy!" << endl;
        exit (1);
    }

    ifstream is;
    ofstream os;

    is.open(*(argv + 1));

    if (!is) {
        cerr << "Failed to open source file!" << endl;
        exit(1);
    }

    is.seekg(0, ios::end);

    unsigned long lengthOfSourceFile = is.tellg();

    if (lengthOfSourceFile == 0) {
        cerr << "File to copy is empty!" << endl;
        exit(1);
    }
    is.seekg(0);

    os.open(*(argv + 2));

    if (!os) {
        cerr << "Failed to open dest file!" << endl;
        exit(1);
    }

    char ch;

    while (is.get(ch)) {
        os.put(ch);
    }

    is.close();
    os.close();
}
