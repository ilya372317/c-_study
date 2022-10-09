//
// Created by ilya on 07.10.22.
//

#include "iostream"

using namespace std;

class SafeArray {
private:
    static const int LIMIT = 100;
    int array[LIMIT]{};
    int currentLimit = LIMIT;

    void checkIndex(int index) const {
        if (index < 0 || index > currentLimit - 1) {
            cout << "Out of bounds in array" << endl;
            exit(1);
        }
    }
public:
    void putel(int var, int index) {
        this->checkIndex(index);
        array[index] = var;
    }

    int getel(int index) {
        this->checkIndex(index);
        return array[index] ;
    }
};

int main() {
    SafeArray arr{};

    arr.putel(1, 1);

    cout << arr.getel(1);

    arr.putel(1, -1);

    arr.getel(-1);
}