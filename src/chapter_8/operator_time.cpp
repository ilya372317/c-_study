//
// Created by ilya on 17.10.22.
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

    [[nodiscard]] static Time minus(Time first, Time second) {
        int newHour, newMinute, newSecond;
        newSecond =  first.second - second.second;
        newMinute = first.minute - second.minute;
        newHour = first.hour - second.hour;

        if (newSecond < 0) {
            newSecond += 60;
            newMinute--;
        }

        if (newMinute < 0) {
            newMinute += 60;
            newHour--;
        }

        if (newHour < 0) {
            newHour = 0;
            newMinute = 0;
            newSecond = 0;
        }

        return {newHour, newMinute, newSecond};
    }

    [[nodiscard]] static Time multiply(Time first, Time second) {
        int newHour, newMinute, newSecond;
        newSecond = first.second * second.second;
        newMinute = first.minute * second.minute;
        newHour = first.hour * second.hour;

        while (newSecond >= 60) {
            newMinute += 1;
            newSecond -= 60;
        }

        while (newMinute >= 60) {
            newHour += 1;
            newMinute -= 60;
        }

        return {newHour, newMinute, newSecond};
    }

    [[nodiscard]] static Time separate(Time first, Time second) {
        int newHour, newMinute, newSecond;
        newSecond = first.second / second.second;
        newMinute = first.minute / second.minute;
        newHour = first.hour / second.hour;

        while (newSecond >= 60) {
            newMinute += 1;
            newSecond -= 60;
        }

        while (newMinute >= 60) {
            newHour += 1;
            newMinute -= 60;
        }

        return {newHour, newMinute, newSecond};
    }

    Time operator+(Time t) {
        return Time::add(*this, t);
    }

    Time operator-(Time t) {
        return Time::minus(*this, t);
    }

    Time operator* (Time t) {
        return Time::multiply(*this, t);
    }

    Time operator/(Time t) {
        return Time::separate(*this, t);
    }

    void operator++() {
        ++hour;
    }

    void operator--() {
        if (hour > 1) {
            --hour;
        }

    }

    void operator++(int) {
        hour++;
    }

    void operator--(int) {
        if (hour > 1) {
            hour--;
        }
    }
};

Time getTestTime(int hour, int minute, int second);

void testAddTime();

void testIncrementsOperators();

void testDecrementsOperators();

void testMinusTime();

void testMultiplyTime();

void testSeparateTime();

void assertEqualsTime(const char* expected, Time actual);

int main() {
    testAddTime();
    testIncrementsOperators();
    testDecrementsOperators();
    testMinusTime();
    testMultiplyTime();
    testSeparateTime();
}

void testAddTime() {
    Time first = getTestTime(1, 30, 50);
    Time second = getTestTime(2, 40, 30);
    Time third = first + second;

    string expected = "4:11:20";
    assertEqualsTime(expected.c_str(), third);
}

void testIncrementsOperators() {
    string expected = "2:0:0";
    Time time = getTestTime(1, 0, 0);
    time++;
    assertEqualsTime(expected.c_str(), time);
    ++time;
    expected = "3:0:0";
    assertEqualsTime(expected.c_str(), time);
}

Time getTestTime(int hour, int minute, int second) {
    return {hour, minute, second};
}

void testDecrementsOperators() {
    Time time = getTestTime(5, 30, 10);
    time--;
    string expected = "4:30:10";
    assertEqualsTime(expected.c_str(), time);
    --time;
    expected = "3:30:10";
    assertEqualsTime(expected.c_str(), time);
}

void testMinusTime() {
    Time first(5, 50, 20), second(4, 59, 10);
    Time third = first - second;
    string expected = "0:51:10";
    assertEqualsTime(expected.c_str(), third);
    Time four = third - first;
    expected = "0:0:0";
    assertEqualsTime(expected.c_str(), four);
}

void testMultiplyTime() {
    Time first(2, 2, 4), second(40, 30, 5);
    Time third = first * second;
    string expected = "81:0:20";
    assertEqualsTime(expected.c_str(), third);
}

void testSeparateTime() {
    Time first(10, 10, 4), second(2, 2, 2);
    Time third = first / second;
    string expected = "5:5:2";
    assertEqualsTime(expected.c_str(), third);
}

void assertEqualsTime(const char* expected, Time actual) {
    cout << "expected: " << expected << ", actual: ";
    actual.display();
    cout << endl;
}