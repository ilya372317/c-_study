//
// Created by ilya on 03.10.22.
//

#include "iostream"

using namespace std;

enum Position {
    manager,
    director,
    cleaner,
    programmer,
};

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

class Employee {
private:
    int number;
    float salary;
    Date jobStart;
    Position position;

public:
    Employee() : number(0), salary(0.0), jobStart(Date()), position(Position::cleaner) {}

    Employee(int num, float sal, Date js, Position p) : number(num), salary(sal), jobStart(js), position(p) {}

    [[nodiscard]] int getNumber() const {
        return number;
    }

    [[nodiscard]] float getSalary() const {
        return salary;
    }

    [[nodiscard]] Date getJobStart() const {
        return jobStart;
    }

    [[nodiscard]] Position getPosition() const {
        return position;
    }

    void setNumber(int num) {
        number = num;
    }

    void setSalary(float sal) {
        salary = sal;
    }

    void setJobStart(Date d) {
        jobStart = d;
    }

    void setPosition(Position p) {
        position = p;
    }

    void showInfo() const {
        cout << "Employee #" << number << " have salary: " << salary << "$" << endl
        << "He was haired on: ";
        jobStart.showDate();
        cout << "And his position is: " << position << endl;
    }

    void getInfo() {
        cout << "Let`s fill employ data: " << endl
        << "Number: ";
        cin >> number;

        cout << "Salary: ";
        cin >> salary;

        cout << "Job start: " << endl;
        jobStart.getDate();

        cout << "Position: " << endl;

        bool positionIncorrect = true;
        while (positionIncorrect) {
            char positionInput;

            cout << "Format of position: " << endl
            << "m = manager" << endl
            << "d = director" << endl
            << "c = cleaner" << endl
            << "p = programmer" << endl;

            cin >> positionInput;

            switch (positionInput) {
                case 'm':
                    position = Position::manager;
                    positionIncorrect = false;
                    break;
                case 'd':
                    position = Position::director;
                    positionIncorrect = false;
                    break;
                case 'c':
                    position = Position::cleaner;
                    positionIncorrect = false;
                    break;
                case 'p':
                    position = Position::programmer;
                    positionIncorrect = false;
                    break;
                default:
                    cout << "Incorrect employee position, try again." << endl;
                    positionIncorrect = true;
            }
        }
    }
};

int main() {
    Employee emp1, emp2, emp3;

    cout << "Fill information about first employee" << endl;
    emp1.getInfo();

    cout << "Fill information about second employee" << endl;
    emp2.getInfo();

    cout << "Fill information about third employee" << endl;
    emp3.getInfo();

    emp1.showInfo();
    emp2.showInfo();
    emp3.showInfo();
}
