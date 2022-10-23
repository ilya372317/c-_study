//
// Created by ilya on 19.10.22.
//

#include "iostream"

using namespace std;

class Integer {
private:
    int integer;
public:
    Integer(): integer(0) {}

    explicit Integer(int i): integer(i) {}

    Integer& operator=(int i) {
        integer = i;
        return *this;
    }

    Integer operator+(Integer integer1) const {
        int resultInt = integer + integer1.integer;

        return Integer(resultInt);
    }

    Integer operator-(Integer integer1) const {
        int resultInt = integer - integer1.integer;

        return Integer(resultInt);
    }

    Integer operator*(Integer integer1) const {
        int resultInt = integer * integer1.integer;

        return Integer(resultInt);
    }

    Integer operator/(Integer integer1) const {
        int resultInt = integer / integer1.integer;

        return Integer(resultInt);
    }

    void operator++() {
        integer++;
    }

    void operator++(int) {
        ++integer;
    }

    void operator--() {
        integer--;
    }

    void operator--(int) {
        --integer;
    }

    void operator+=(Integer integer1) {
        integer += integer1.integer;
    }

    void operator-=(Integer integer1) {
        integer -= integer1.integer;
    }

    void operator/=(Integer integer1) {
        integer /= integer1.integer;
    }

    void operator*=(Integer integer1) {
        integer *= integer1.integer;
    }

    [[nodiscard]] int getDefaultInt() const {
        return integer;
    }
};

void resetValue(Integer& integer);

int main() {
    cout << "Test Integer class: " << endl;

    Integer a, b, c;

    cout << "Operator+" << endl;
    a = 1;
    b = 2;

    c = a + b;
    cout << "expected 3, actual: " << c.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test Operator-" << endl;

    a = 3;
    b = 1;
    c = a - b;

    cout << "expected 2, actual: " << c.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test Operator*" << endl;

    a = 2;
    b = 5;
    c = a * b;

    cout << "expected 10, actual: " << c.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator/" << endl;

    a = 10;
    b = 2;
    c = a / b;

    cout << "expected 5, actual: " << c.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator++" << endl;

    a++;
    cout << "expected 1, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator--" << endl;

    a = 3;
    a--;
    cout << "expected 2, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator+=" << endl;
    a = 2;
    b = 1;

    a += b;

    cout << "expected 3, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator-=" << endl;
    a = 10;
    b = 1;
    a -= b;

    cout << "expected 9, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator*=" << endl;

    a = 3;
    b = 3;
    a *= b;

    cout << "expected 9, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test operator/=" << endl;

    a = 15;
    b = 3;
    a /= b;

    cout << "expected 5, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test --operator" << endl;

    a = 7;
    --a;

    cout << "expected 6, actual: " << a.getDefaultInt() << endl;

    resetValue(a);
    resetValue(b);
    resetValue(c);

    cout << endl;
    cout << "Test ++operator" << endl;

    a = 7;
    ++a;

    cout << "expected 8, actual: " << a.getDefaultInt() << endl;

}

void resetValue(Integer& integer) {
    integer = 0;
}