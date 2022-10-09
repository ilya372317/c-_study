//
// Created by ilya on 30.09.22.
//

#include "iostream"

using namespace std;

class Integer {
private:
    int number;
public:
    Integer(): number(0) {}
    explicit Integer(int num): number(num) {}

    [[nodiscard]] int toDefaultInt() const {
        return number;
    }

    void plus(Integer num) {
        number += num.toDefaultInt();
    }

    void minus(Integer num) {
        number -= num.toDefaultInt();
    }

    void separate(Integer num) {
        number /= num.toDefaultInt();
    }

    void multiply(Integer num) {
        number *= num.toDefaultInt();
    }
};

int main()
{
    Integer a(10), b(20);
    a.plus(b);
    cout << "a + b = " << a.toDefaultInt() << endl;
    a.minus(Integer(20));
    cout << "a - 20 = " << a.toDefaultInt() << endl;
    a.multiply(Integer(10));
    cout << "a * 10 = " << a.toDefaultInt() << endl;
    a.separate(Integer(2));
    cout << "a / 2 = " << a.toDefaultInt() << endl;

    return 0;
}