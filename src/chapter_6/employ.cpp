//
// Created by ilya on 02.10.22.
//

#include "iostream"

using namespace std;

class Employee {
private:
    int number; float salary;
public:
    Employee() : number(0), salary(0.0) {}

    Employee(int num, float sal) : number(num), salary(sal) {}

    [[nodiscard]] int getNumber() const {
        return number;
    }

    [[nodiscard]] float getSalary() const {
        return salary;
    }

    void setNumber(int num) {
        number = num;
    }

    void setSalary(float sal) {
        salary = sal;
    }

    void showInfo() const {
        cout << "Employee #" << number << " have salary: " << salary << "$" << endl;
    }
};

Employee getEmployeeInformation();

int main() {
    Employee emp1, emp2, emp3;

    cout << "Set employee number 1: " << endl;
    emp1 = getEmployeeInformation();
    cout << "Set employee number 2" << endl;
    emp2 = getEmployeeInformation();
    cout << "Set employee number 3" << endl;
    emp3 = getEmployeeInformation();

    emp1.showInfo();
    emp2.showInfo();
    emp3.showInfo();

    return 0;
}

Employee getEmployeeInformation() {
    Employee employee;
    int number;
    float salary;
    cout << "Number: ";
    cin >> number;
    employee.setNumber(number);

    cout << "Salary: ";
    cin >> salary;
    employee.setSalary(salary);

    return employee;
}