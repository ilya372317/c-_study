//
// Created by ilya on 23.10.22.
//

#include "iostream"

using namespace std;

class Counter {
protected:
    unsigned int count;
public:
    Counter(): count(0) {}

    explicit Counter(unsigned int c): count(c) {}

    [[nodiscard]] unsigned int get_count() const {
        return count;
    }

    Counter operator++() {
        return Counter(++count);
    }
};

class CountDn : public Counter
{
public:
    CountDn(): Counter() {}

    explicit CountDn(unsigned int i): Counter(i) {}

    Counter operator--() {
        return Counter(--count);
    }
};

class PostfixCounter : public CountDn {
public:
    PostfixCounter(): CountDn() {}

    explicit PostfixCounter(unsigned int c): CountDn(c) {}

    PostfixCounter operator++(int) {
        return PostfixCounter(count++);
    }
};

void assertEqualsInt(unsigned int expected, unsigned int actual);

int main() {
    CountDn countDn(10);
    ++countDn;
    assertEqualsInt(11, countDn.get_count());

    --countDn;
    --countDn;

    assertEqualsInt(9, countDn.get_count());

    PostfixCounter postfixCounter(10);
    postfixCounter++;

    assertEqualsInt(11, postfixCounter.get_count());
}

void assertEqualsInt(unsigned int expected, unsigned int actual) {
    cout << "expected: " << expected << ", actual: " << actual << endl << endl;
}
