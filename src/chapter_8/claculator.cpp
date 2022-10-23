//
// Created by ilya on 10.10.22.
//

#include "iostream"

using namespace std;

bool isNumberCharacter(char item);

class LongCalculator {
private:
    static const int MAX_CALCULATE_LENGTH = 300;
    string calculateString;

    char findOperatorForCalc() {
        char operatorForCacl;

        for (const auto &item: calculateString) {
            if (item == '+') {
                operatorForCacl = '+';
            }

            if (item == '-') {
                operatorForCacl = '-';
            }

            if (item == '*') {
                operatorForCacl = '*';
            }

            if (item == '/') {
                operatorForCacl = '/';
            }
        }

        return operatorForCacl;
    }

    long findFirstArgument() {
        int position = 0;
        bool intIsNegative;
        char firstArgumentString[100];
        for (const auto &item: calculateString) {
            if (isNumberCharacter(item)) {
                firstArgumentString[position] = item;
            } else {
                break;
            }
            position++;
        }

        long result = atol(firstArgumentString);

        return result;
    }

    int findPositionOfOperator() {
        int position = 0;
        for (const auto &item: calculateString) {
            if (item == '+' || item == '-' || item == '*' || item == '/') {
                return position;
            }

            position++;
        }

        return -1;
    }

    long findSecondArgument() {
        int position = 0;
        int index = 0;
        int positionOfOperator = findPositionOfOperator();
        bool intIsNegative = false;
        string secondArgumentString;
        for (const auto &item: calculateString) {
            if (position > positionOfOperator) {
                if (isNumberCharacter(item)) {
                    secondArgumentString += item;
                }
            }
            position++;
        }
        long result = stol(secondArgumentString);
        return result;
    }

public:
    explicit LongCalculator(string calculateStr) {
        calculateString = calculateStr;
    }

    static long add(long first, long second) {
        return first + second;
    }

    static long minus(long first, long second) {
        return first - second;
    }

    static long multiply(long first, long second) {
        return first * second;
    }

    static long separate(long first, long second) {
        return first / second;
    }

    long calculate() {
        char operatorForCalc = findOperatorForCalc();

        long firstOperator = findFirstArgument();
        long secondOperator = findSecondArgument();

        switch (operatorForCalc) {
            case '+':
                return add(firstOperator, secondOperator);
            case '-':
                return minus(firstOperator, secondOperator);
            case '*':
                return multiply(firstOperator, secondOperator);
            case '/':
                return separate(firstOperator, secondOperator);
            default:
                cout << "invalid operator in calculate string, try again" << endl;
                throw invalid_argument("invalid operator in calculate string, try again");
        }
    }

    void setCalculateString(const char calcStr[MAX_CALCULATE_LENGTH], int length) {
        for (int i = 0; i < length; i++) {
            calculateString[i] = calcStr[i];
        }
    }
};

bool isNumberCharacter(char item) {
    return item == '0' || item == '1' || item == '2' || item == '3'
           || item == '4' || item == '5' || item == '6' || item == '7'
           || item == '8' || item == '9';
}

int main() {
    string stringForCalc;
    getline(cin, stringForCalc);

    LongCalculator calc(stringForCalc);

    cout << "Result = " << calc.calculate() << endl;
}
