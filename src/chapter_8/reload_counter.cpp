//
// Created by ilya on 10.10.22.
//

#include "iostream"

using namespace std;

class Counter {
private:
    unsigned long count;
public:
    Counter(): count(0) {}

    explicit Counter(unsigned long c): count(c) {}

    [[nodiscard]] unsigned long get_count() const {
        return count;
    }

    Counter& operator++() {
        ++count;
        return *this;
    }

    Counter&  operator++(int) {
        count++;
        return *this;
    }

    Counter& operator= (unsigned long c) {
        count = c;
        return *this;
    }
};

int main() {
    Counter counter, counter2;

    Counter counter1 = ++counter;

    counter2 = 10;

    cout << counter1.get_count() << endl;
    cout << counter2.get_count() << endl;
}
