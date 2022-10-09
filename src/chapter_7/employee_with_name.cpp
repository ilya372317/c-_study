//
// Created by ilya on 06.10.22.
//

#include "iostream"
#include "string"

using namespace std;

class Employee {
private:
    string name;
    long number;
    static long count;
public:
    Employee() {
        number = ++count;
    }

    void  getData() {
        cout << "Print employee name: ";
        getline(cin, name);
    }

    void putData() const {
        cout << "Employee #" << number << " have name: " << name << endl;
    }
};

long Employee::count = 0;

int main() {
    Employee employee1, employee2;

    employee1.getData();
    employee2.getData();
    employee1.putData();
    employee2.putData();

    return 0;
}
