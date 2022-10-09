//
// Created by ilya on 30.09.22.
//

#include "iostream"

using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : inches(0), feet(0.0) {}

    Distance(int fe, float in) : inches(in), feet(fe) {}

    void getDistance() {
        cout << "Print feet: ";
        cin >> feet;

        cout << "Print inches: ";
        cin >> inches;
    }

    void showDistance() const { cout << feet << "\'-" << inches << '\"'; }

    void addDistance(Distance, Distance);
};

void Distance::addDistance(Distance dist2, Distance dist3) {
    inches = dist2.inches + dist3.inches;
    feet = 0;
    if (inches >= 12.0) {
        inches -= 12.0;
        feet++;
    }
    feet += dist2.feet + dist3.feet;
}

int main() {
    Distance dist1(11, 6.25), dist2;
    dist2.getDistance();

    cout << endl << "dist1: ";
    dist1.showDistance();

    cout << endl << "dist2: ";
    dist2.showDistance();
    cout << endl;
}
