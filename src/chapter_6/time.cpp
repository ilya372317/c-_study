//
// Created by ilya on 02.10.22.
//

#include "iostream"

using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h, int m, int s) : hour(h), minute(m), second(s) {};

    explicit Time(int h) : hour(h), minute(0), second(0) {};

    Time() : hour(0), minute(0), second(0) {};

    void display() const {
        cout << hour << ":" << minute << ":" << second << endl;
    }

    [[nodiscard]] static Time add(Time first, Time two) {
        int newHour, newMinute, newSecond;
        newSecond = first.second + two.second;
        newMinute = first.minute + two.minute;
        newHour = first.hour + two.hour;

        if (newSecond > 60) {
            newSecond -= 60;
            newMinute++;
        }

        if (newMinute > 60) {
            newMinute -= 60;
            newHour++;
        }

        return {newHour, newMinute, newSecond};
    }
};

int main() {
    int hour, minute, second;

    cout << "Print first time to add: " << endl
    << "Hour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> minute;
    cout << "Second: ";
    cin >> second;

    Time firstTime(hour, minute, second);

    cout << endl << "Print second time to add: " << endl
    << "Hour: ";
    cin >> hour;
    cout << "Minute: ";
    cin >> minute;
    cout << "Second: ";
    cin >> second;

    Time secondTime(hour, minute, second);

    Time newTime = Time::add(firstTime, secondTime);
    newTime.display();

    return 0;
}