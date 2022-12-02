//
// Created by Отинов Илья on 02.12.2022.
//

#include "iostream"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Count of arguments: " << argc - 1 << endl;

    cout << "Name of command: " << argv[0] << endl;

    cout << "List of argument: " << endl;



    for (int i = 1; i < argc; i++) {
        cout << "--- " << "Argument #" << i << " equals: " << *(argv + i) << endl;
    }

    cout << endl;
}
