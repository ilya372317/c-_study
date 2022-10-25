//
// Created by ilya on 23.10.22.
//
#include "iostream"

using namespace std;

class Stack {
protected:
    static const int MAX = 3;
    int st[MAX];
    int top;
public:
    Stack(): top(-1) {}

    void push(int var) {
        st[++top] = var;
    }

    int pop () {
        return st[top--];
    }
};

class ImprovedStack : public Stack {
public:
    void push(int var) {
        if (top >= MAX - 1) {
            cout << "error, stack is full!" << endl;
            return;
        }
        Stack::push(var);
    }

    int pop() {
        if (top < 0) {
            cout << "error, stack is empty" << endl;
            return -1;
        }
        Stack::pop();
    }
};

void assertIntEquals(int expected, int actual);

void testGetFromStack();

int main() {
    testGetFromStack();
}

void assertIntEquals(int expected, int actual) {
    cout << "expected: " << expected << ", actual: " << actual << endl << endl;
}

void testGetFromStack() {
    ImprovedStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    int actual = stack.pop();
    assertIntEquals(3, actual);
    actual = stack.pop();
    assertIntEquals(2, actual);
    actual = stack.pop();
    assertIntEquals(1, actual);

    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
}
