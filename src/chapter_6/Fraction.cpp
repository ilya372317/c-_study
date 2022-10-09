//
// Created by ilya on 04.10.22.
//

#include "iostream"

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(): numerator(0), denominator(0) {}

    Fraction(int n, int d): numerator(n), denominator(d) {}

    void getFromInput() {
        char dummChar;
        cout << "Print fraction in format [x/y]: ";
        cin >> numerator;
        cin >> dummChar;
        cin >>denominator;
    }

    void show() const {
        cout << numerator << "/" << denominator << endl;
    }

    void addToCurrent(Fraction fraction) {
        Fraction newFraction(numerator, denominator);
        newFraction = add(newFraction, fraction);
        numerator = newFraction.numerator;
        denominator = newFraction.denominator;
    }

    static Fraction add(Fraction first, Fraction second) {
        Fraction newFraction;
        newFraction.numerator = (first.numerator * first.denominator) + (second.numerator * second.denominator);
        newFraction.denominator = first.denominator * second.denominator;
        return newFraction;
    }
};

int main() {
    Fraction first, second, result;
    char needMore = 'y';

    while (needMore != 'x') {
        cout << "Print first fraction: " << endl;
        first.getFromInput();

        cout << "Print second fraction: " << endl;
        second.getFromInput();

        result = Fraction::add(first, second);
        cout << "Result: ";
        result.show();

        cout << "Calculate next? [y/x]: ";
        cin >> needMore;
    }

    return 0;
}