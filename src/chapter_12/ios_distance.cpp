//
// Created by Отинов Илья on 24.11.2022.
//

#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

bool isFeet(string);

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}

    Distance(int f, float i) : feet(f), inches(i) {}

    void showDist() const {
        cout << feet << "\'-" << inches << '\"';
    }

    void getDist();
};

void Distance::getDist() {
    string instr;

    while (true) {
        cout << endl << "Print feet: ";
        cin.unsetf(ios::skipws);

        cin >> instr;
        if (isFeet(instr)) {
            cin.ignore(10, '\n');
            feet = atoi(instr.c_str());
            break;
        }

        cin.ignore(10, '\n');

        cout << "feet need to be integer!" << endl;
    }

    while (true) {
        float tempInches;
        cout << endl << "Print inches: ";
        cin.unsetf(ios::skipws);
        cin >> tempInches;

        if (tempInches >= 12 || tempInches < 0.0) {
            cout << "Inches need to be between 11.99 and 0.0";
            cin.clear(ios::failbit);
        }

        if (cin.good()) {
            inches = tempInches;
            cin.ignore(10, '\n');
            break;
        }

        cout << "Inches is incorrect, try again!" << endl;
        cin.clear();
        cin.ignore(10, '\n');
    }
}

bool isFeet(string str) {
    int strLen = str.size();
    if (strLen == 0 || strLen > 5) {
        return false;
    }

    for (int i = 0; i < strLen; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-') {
            return false;
        }
    }

    double n = strtod(str.c_str(), nullptr);

    if (n < -999.0 || n > 999.0) {
        return false;
    }

    return true;
}

int main() {
    auto* distancePtr = new Distance;
    char ans;

    do {
        distancePtr->getDist();
        cout << "Distance equals: ";
        distancePtr->showDist();
        cout << endl << "One more? (y/n) ";
        cin >> ans;
        cin.ignore(10, '\n');
    } while (ans != 'n');

    delete distancePtr;

    return 0;
}