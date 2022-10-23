//
// Created by ilya on 10.10.22.
//

#include "iostream"

using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) {}

    Distance(int f, float i) : feet(f), inches(i) {}

    void setInches(float inch) {
        inches = inch;
    }

    void setFeet(int fet) {
        feet = fet;
    }

    [[nodiscard]] int getFeet() const {
        return feet;
    }

    [[nodiscard]] float getInches() const {
        return inches;
    }

    Distance operator+ (Distance first) const {
        Distance newDistance;
        int newFeet = feet + first.getFeet();
        float newInches = inches + first.getInches();

        bool inchesInvalid = true;

        while (inchesInvalid) {
            if (newInches > 100) {
                newInches -= 100;
                newFeet += 1;
            }

            if (newInches <= 100) {
                inchesInvalid = false;
            }
        }

        newDistance.setFeet(newFeet);
        newDistance.setInches(newInches);

        return newDistance;
    }

    Distance operator- (Distance first) const {
        int newFeet = feet - first.getFeet();
        float newInches = inches - first.getInches();

        bool inchesInvalid = true;

        while (inchesInvalid) {
            if (newInches > 100) {
                newInches -= 100;
                newFeet += 1;
            }

            if (newInches <= 100) {
                inchesInvalid = false;
            }
        }

        return {newFeet, newInches};
    }
};

int main() {
    Distance first, second, third;

    first.setFeet(1);
    second.setFeet(2);

    first.setInches(1.1f);
    second.setInches(2.2f);

    third = first + second;

    cout << "Third element has this parameter: " << endl
         << "Feet: " << third.getFeet() << endl
         << "Inches: " << third.getInches() << endl;
}
