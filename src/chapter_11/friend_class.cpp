//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

class Beta;

class Alpha {
private:
    int data;
public:
    Alpha(): data(3) {}

    friend int frifunc(Alpha, Beta);
};

class Beta {
private:
    int data;
public:
    Beta(): data(7) {}

    friend int frifunc(Alpha, Beta);
};

int frifunc(Alpha a, Beta b) {
    return (a.data + b.data);
}

int main() {
    Alpha a;
    Beta b;

    int result = frifunc(a,b);

    cout << "expected: 10, actual: " << result << endl; 
}

