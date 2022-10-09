//
// Created by ilya on 02.10.22.
//

#include "iostream"
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

using namespace std;

class TollBooth {
private:
    unsigned int carCount;
    double revenue;
public:
    TollBooth() : carCount(0), revenue(0) {}

    void payingCar() {
        carCount++;
        revenue += 0.50;
    }

    void noPayCar() {
        carCount++;
    }

    void display() const {
        cout << "Total car was passed: " << carCount << endl
             << "Total revenue: " << revenue << endl;
    }
};

int main() {
    TollBooth tollBooth;
    char control;

    cout << "When car passing, type one of symbols: " << endl
         << "When car payment, type: [p]" << endl
         << "When car not pay, type [f]" << endl
         << "If you want exit and view result, type [q]" << endl;
    while (true) {
        cout << "Car pay for pass: ";
        cin >> control;

        if (control == 'p') {
            tollBooth.payingCar();
        } else if (control == 'f') {
            tollBooth.noPayCar();
        } else if (control == 'q') {
            break;
        } else {
            cout << "Wrong symbol. Use only p/f" << endl;
        }
    }
    tollBooth.display();
    return 0;
}
