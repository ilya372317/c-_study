//
// Created by Отинов Илья on 03.12.2022.
//

#include "iostream"
#include "fstream"

using namespace std;

int main(int argc, char* argv[]) {
    ifstream is;
    is.open(*(argv + 1));
    if (!is) {
        cerr << "Failed to open file for count!" << endl;
        exit(1);
    }

    is.seekg(0, ios::end);

    unsigned long result = is.tellg();

    cout << "Size of file " << *(argv) << " is: " << result << " byte." << endl;

    return 0;
}
