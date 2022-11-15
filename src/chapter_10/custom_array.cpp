//
// Created by ilya on 03.11.22.
//

#include "iostream"
#include "string"

using namespace std;

class CostumeArray {
private:
    static const int MAX = 10;
    int* array[MAX]{};
public:
    CostumeArray() {
        for (int i = 0; i < MAX; i++) {
            *(array + i) = new int [MAX];
        }
    }

    [[nodiscard]] int getElement(int index) const {
        string indexString = to_string(index);
        unsigned long lengthOfIndex = indexString.length();

        if (lengthOfIndex > 2) {
            cout << "index is out of bounds" << endl;
            exit(1);
        }

        char indexOfArray = indexString[0];
        char indexOfElement = indexString[1];
        int indexOfArrayInteger = indexOfArray - '0';
        int indexOfElementInteger = indexOfElement - '0';

        if (lengthOfIndex == 1) {
            indexOfArrayInteger = 0;
            indexOfElementInteger = indexOfArray - '0';
        }

        return *(*(array+indexOfArrayInteger) + indexOfElementInteger);
    }

    void putElement(int element, int index) {
        string indexString = to_string(index);
        unsigned long lengthOfIndex = indexString.length();

        if (lengthOfIndex > 2) {
            cout << "index is out of bounds" << endl;
            exit(1);
        }

        char indexOfArray = indexString[0];
        char indexOfElement = indexString[1];
        int indexOfArrayInteger = indexOfArray - '0';
        int indexOfElementInteger = indexOfElement - '0';

        if (lengthOfIndex == 1) {
            indexOfArrayInteger = 0;
            indexOfElementInteger = indexOfArray - '0';
        }

        *(*(array + indexOfArrayInteger) + indexOfElementInteger) = element;
    }

    int operator[](int index) const {
        return this->getElement(index);
    }
};

int main() {
    auto* costumeArrayPtr = new CostumeArray;

    costumeArrayPtr->putElement(1,30);
    costumeArrayPtr->putElement(2,1);
    costumeArrayPtr->putElement(50, 50);
    CostumeArray costumeArray = *costumeArrayPtr;
    costumeArray[30];

    cout << "first element: " << costumeArray[30] << endl
    << "second element: " << costumeArrayPtr->getElement(1) << endl
    << "third element: " << costumeArrayPtr->getElement(50) << endl;
    return 0;
}
