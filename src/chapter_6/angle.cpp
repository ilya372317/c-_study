//
// Created by ilya on 03.10.22.
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

int main() {
    Angle angle(179, 55.9, 'E');
    angle.showInfo();

    while (true) {
        angle.getFromUser();
        angle.showInfo();
        char quit = 'n';
        cout << "Next? [y/n]" << endl;
        cin >> quit;
        if (quit != 'y') {
            break;
        }
    }

    return 0;
}