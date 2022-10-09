//
// Created by ilya on 08.10.22.
//

#include "iostream"

using namespace std;

class Test {
private:
    int number;
public:
    int array[100]{};

    Test() : number(0) {}

    explicit Test(int n) : number(n) {}

    void showNumber() const {
        cout << number << endl;
    }

    void setNumber(int n) {
        number = n;
    }

    [[nodiscard]] int getNumber() const {
        return number;
    }

    void showArray() const {
        for (int i : array) {
            cout << i << endl;
        }
    }
};

Test increment(Test t);

int main() {
    Test t1, t2;

    t1.setNumber(t1.getNumber() + 1);

    for (int i = 0; i < 100; i ++) {
        t1.array[i] = i;
    }

    Test newTest = increment(t1);


    cout << "Show start array after function in main: " << endl;
    t1.showArray();

    cout << "Show array returned from function";
    newTest.showArray();
}

Test increment(Test t) {
    t.showNumber();
    cout << "Array before preaper in function first" << endl;
    t.showArray();

    for (int i = 99, k = 0; i >= 0; i--, k++) {
        t.array[k] = i;
    }

    cout << "Show changed array in function" << endl;
    t.showArray();
    return t;
}