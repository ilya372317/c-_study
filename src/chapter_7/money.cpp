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

    static string ldtoms(double number) {
        string startString = to_string(number);
        string resultString = "$";
        bool firstIndexWasPass = true;
        unsigned long position = 0;
        for (const auto &item: startString) {
            if (item == '.') {
                break;
            }

            if ((position % 3) == 0 && position != 0) {
                resultString.push_back(',');
            }

            if (position == 1 && firstIndexWasPass) {
                resultString.push_back(',');
                position--;
                firstIndexWasPass = false;
            }

            resultString += item;
            position++;
        }

        if (position < 3) {
            resultString.replace(2, 1, "");
        }

        resultString += '\0';

        return resultString;
    }
};

class BMoney {
private:
    double money;
public:
    BMoney() : money(0.0) {}

    explicit BMoney(const char s[]) {
        money = Money::mstold(s);
    };

    void showMoney() const {
        cout << Money::ldtoms(money) << endl;
    }

    [[nodiscard]] double getMoney() const {
        return money;
    }

    void putMoney() {
        cout << "Print money: " << endl;
        char userMoney[100];
        cin.get(userMoney, 100);

        money = Money::mstold(userMoney);

        cout << "Money was successfully save" << endl;
    }

    void addMoney(BMoney m) {
        money += m.getMoney();
    }
};

int main() {
    BMoney first, second("200$");
    first.putMoney();

    first.addMoney(second);

    cout << "First: ";
    first.showMoney();
    cout << "Second: ";
    second.showMoney();

}

bool isNumericChar(char c) {
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6'
           || c == '7' || c == '8' || c == '9';
}
