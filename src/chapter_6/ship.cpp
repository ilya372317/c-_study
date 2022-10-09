//
// Created by ilya on 04.10.22.
//

#include "iostream"

using namespace std;

class Angle {
private:
    int degree;
    float minute;
    char direction;
public:
    Angle(int deg, float min, char dir) : degree(deg), minute(min), direction(dir) {}

    Angle(): degree(0), minute(0), direction(' ') {}

    void getFromUser() {
        cout << "Fill information about angle: " << endl
             << "degree: ";
        cin >> degree;

        cout << "minute: ";
        cin >> minute;

        cout << "direction: ";
        cin >> direction;
    }

    void showInfo() const {
        cout << degree << '*' << minute << '\'' << " " << direction << "." << endl;
    }
};

class Ship {
private:
    unsigned long number;
    static unsigned long count;
    Angle coordinateX;
    Angle coordinateY;
public:
    Ship() {
        count++;
        number = count;
    }

    void getCoordinateXFromUser() {
        cout << "Set up coordinate x to ship #" << number << ": " << endl;
        coordinateX.getFromUser();
    }

    void getCoordinateYFromUser() {
        cout << "Set up coordinate y to ship #" << number << ": " << endl;
        coordinateY.getFromUser();
    }

    void showInformation() const {
        cout << "Ship #" << number << " Have next coordinate: " << endl
        << "X: ";
        coordinateX.showInfo();
        cout << "Y: ";
        coordinateY.showInfo();
    }
};

unsigned long Ship::count = 0;

int main() {
    Ship firstShip, secondShip, thirdShip;

    cout << "Fill information about third ships: " << endl;
    firstShip.getCoordinateXFromUser();
    firstShip.getCoordinateYFromUser();
    secondShip.getCoordinateXFromUser();
    secondShip.getCoordinateYFromUser();
    thirdShip.getCoordinateXFromUser();
    thirdShip.getCoordinateYFromUser();

    firstShip.showInformation();
    secondShip.showInformation();
    thirdShip.showInformation();
}