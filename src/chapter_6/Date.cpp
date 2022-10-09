//
// Created by ilya on 02.10.22.
//

#include "iostream"

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    Date() : year(0), month(0), day(0) {}

    void showDate() const {
        char monthString[100];
        char dayString[100];

        if (month < 10) {
            sprintf(monthString, "0%d", month);
        } else {
            sprintf(monthString, "%d", month);
        }

        if (day < 10) {
            sprintf(dayString, "0%d", day);
        } else {
            sprintf(dayString, "%d", day);
        }

        cout << year << "/" << monthString << "/" << dayString << endl;
    }

    void getDate() {
        char uselessChar;
        cout << "Print data in YYYY/mm/dd format: ";
        cin >> year;
        cin >> uselessChar;
        cin >> month;
        cin >> uselessChar;
        cin >> day;
    }
};

int main() {
    Date date;
    date.getDate();
    date.showDate();
};