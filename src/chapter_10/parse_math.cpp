//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

const int LEN = 80;
const int MAX = 40;

class Stack {
private:
    char st [MAX]{};
    int top;
public:
    Stack() : top(0) {}

    void push(char var) {
	st [++top] = var;
    }

    char pop() {
	return st [top--];
    }

    int getTop() const {
	return top;
    }
};
