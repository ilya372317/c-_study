//
// Created by Отинов Илья on 03.12.2022.
//

#include "iostream"

using namespace std;

class Time {
private:
    int second;
    int minute;
    int hour;
public:
    void get_time() {
        // get seconds
        while (true) {
            cout << "Print seconds: ";
            cin >> second;

            if (second > 59) {
                cin.setstate(ios::failbit);
            }

            if (cin.good()) {
                cin.ignore(10, '\n');
                break;
            }

            cout << "Invalid second, try again" << endl;
            cin.ignore(10, '\n');
            cin.clear();
        }

        // Get minute
        while (true) {
            cout << "Print minute: ";
            cin >> minute;

            if (minute > 59) {
                cin.setstate(ios::failbit);
            }

            if (cin.good()) {
                cin.ignore(10, '\n');
                break;
            }
            cout << "Invalid minute, try again" << endl;
            cin.ignore(10, '\n');
            cin.clear();
        }

        while (true) {
            cout << "Print hour: ";
            cin >> hour;

            if (hour > 23) {
                cin.setstate(ios::failbit);
            }

            if (cin.good()) {
                cin.ignore(10, '\n');
                break;
            }

            cout << "Invalid hour, try again";
            cin.ignore(10, '\n');
            cin.clear();
        }
    }

    void put_time() const {
        cout << hour << ":" << minute << ":" << second;
    }
};

int main(int argc, char* argv[]) {
    Time t{};
    t.get_time();
    t.put_time();
    cout << endl;
}
