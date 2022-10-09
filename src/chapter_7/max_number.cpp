//
// Created by ilya on 06.10.22.
//

#include "iostream"
#include "cstring"

using namespace std;

int const MAX = 100;

/**
 * @param array
 * @param countOfElement
 * @return index of max value;
 */
int max(const int array[], unsigned long countOfElement);

int main() {
    int numberArray[MAX];
    int currentIndex = 0;
    char userChar;
    int userNum;

    cout << "Print numbers with tab, when you be enough print \'q\'" << endl;
    while (true) {
        cin >> userNum;

        numberArray[currentIndex++] = userNum;

        cout << "[n/s]?";
        cin >> userChar;

        if (userChar == 's') {
            break;
        }
    }

    int indexOfMaxElement = max(numberArray, currentIndex + 1);

    cout << numberArray[indexOfMaxElement] << endl;

    return 0;
}

int max(const int array[], unsigned long countOfElement) {
    int maxElementIndex = 0;
    int maxElement = array[0];

    for(int i = 0; i < countOfElement; i++) {
        int currentElement = array[i];

        if (currentElement > maxElement) {
            maxElementIndex = i;
            maxElement = currentElement;
        }
    }

    return maxElementIndex;
}