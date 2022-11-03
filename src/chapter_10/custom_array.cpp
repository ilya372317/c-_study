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
    int currentArrayIndex;
public:
    CostumeArray(): currentArrayIndex(0) {
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

        return *(*(array+indexOfArray) + indexOfElement);
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

        *(*(array + indexOfArray) + indexOfElement) = element;
    }
};

int main() {
    auto* costumeArrayPtr = new CostumeArray;

    costumeArrayPtr->putElement(1,30);

    cout << "result: " << costumeArrayPtr->getElement(30);
    return 0;
}
