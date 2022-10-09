//
// Created by ilya on 07.10.22.
//

#include "iostream"
#include "string"

using namespace std;

bool isNumericChar(char c);

class Money {
public:
    static double mstold(const string &str) {
        char intString[100];
        int currentIndex = 0;
        for (const auto &item: str) {
            if (isNumericChar(item)) {
                intString[currentIndex++] = item;
            }
        }

        return atof(intString);
    }
};

int main() {
    Money money{};
    char userMoneyString[100];

    cout << "Print money";
    cin.get(userMoneyString, 100);

    double moneyInt = Money::mstold(userMoneyString);

    cout << moneyInt << endl;
}

bool isNumericChar(char c) {
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'
           || c == '7' || c == '8' || c == '9';
}
