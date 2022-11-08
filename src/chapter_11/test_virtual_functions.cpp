//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

class Base {
public:
    virtual void show() const = 0;
};

class Derv1 : public Base {
    void show() const {
	cout << "Derv 1" << endl;
    }
};

class Derv2 : public Base {
    void show() const {
	cout << "Derv 2" << endl;
    }
};

int main() {
    Base* arr[2];
    arr[0] = new Derv1();
    arr[1] = new Derv2();

    for (Base* item : arr) {
	item->show();
    }
}

