//
// Created by ilya on 03.10.22.
//

#include "iostream"

using namespace std;

class Counter {
private:
    unsigned long number;
    static unsigned long count;
public:
    Counter() {
        count++;
        number = count;
    }

    void showNumber() const {
        cout << number << endl;
    }
};

unsigned long Counter::count = 0;

int main() {
    Counter counter1, counter2, counter3;

    counter1.showNumber();
    counter2.showNumber();
    counter3.showNumber();

    return 0;
}