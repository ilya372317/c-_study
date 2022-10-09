//
// Created by ilya on 04.10.22.
//

#include "iostream"

using namespace std;

class Stack {
private:
    static const int MAX = 10;
    int st[MAX]{};
    int top;
public:
    Stack(): top(0){}

    void push(int var) {
        st[++top] = var;
    }

    int pop() {
        return st[top--];
    }
};

int main() {
    Stack s1;

    s1.push(1);
    s1.push(2);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s1.push(23);
    s1.push(43);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}