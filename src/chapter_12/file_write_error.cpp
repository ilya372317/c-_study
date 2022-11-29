//
// Created by Отинов Илья on 28.11.2022.
//

#include "iostream"
#include "fstream"

using namespace std;

int main() {
    const int MAX = 100;
    int buffer[MAX];

    for (int i = 0; i < MAX; i++) {
        buffer[i] = i;
    }

    ofstream os;
    os.open("BUFFER_DATA.txt", ios::trunc | ios::binary);

    if (!os) {
        cerr << "Failed to open file BUFFER_DATA.txt for writing" << endl;
        exit(1);
    }

    cout << "writing ..." << endl;

    os.write(reinterpret_cast<char*>(buffer), 100 * sizeof(int));

    if (!os) {
        cerr << "Writing in file not possible" << endl;
        exit(1);
    }

    os.close();

    for (int & i : buffer) {
        i = 0;
    }

    ifstream is;
    is.open("BUFFER_DATA.txt", ios::binary);

    if (!is) {
        cerr << "Failed to open file BUFFER_DATA.txt for reading" << endl;
        exit(1);
    }

    cout << "Reading..." << endl;
    is.read(reinterpret_cast<char*>(buffer), MAX * sizeof(int));

    if (!is) {
        cerr << "failed read from BUFFER_DATA.txt" << endl;
        exit(1);
    }

    cout << "Reading data: " << endl;

    for (int i = 0; i < MAX; i++) {
        cout << *(buffer + i) << ", ";
    }

    cout << endl;
}