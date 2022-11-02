//
// Author Ilya Otinov
//

#include "iostream"
#include "string"

using namespace std;

class Person {
protected:
    string name;
    float salary;
public:
    void setData() {
        cout << "Print name: ";
	cin >> name;
	cout << "Print salary: ";
	cin >> salary;
    }

    void printData() const {
	cout << "Name: " <<  name  << endl
	<< "Salary: " << salary << endl;
    }

    string getName() const {
	return name;
    }

    float getSalary() const {
	return salary;
    }
};

void bsort(Person**, int);

void salsort(Person**, int);

void order(Person**, Person**);

int main() {
    Person* persPtr [100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
	persPtr[n]->setData();
	n++;
	cout << "Print next employee? [y/n]" << endl;
	cin >> choice;
    } while (choice == 'y');

    cout << "Not sorting list: " << endl;

    for (int i = 0; i < n; i++) {
	cout << "Employee number " << i + 1 << ": ";
	persPtr[i]->printData();
    }

    bsort(persPtr, n);

    cout << "sorting list by names: " << endl;

    for (int i = 0; i < n; i++) {
       cout << "Employee number " << i + 1 << ": ";
       persPtr[i]->printData();
    }
  
    cout << "sorting list by salary: " << endl;
    salsort(persPtr, n);

    for (int i = 0; i < n; i++) {
	(*(persPtr + i))->printData();
    }

    return 0;
}

void order(Person** pp1, Person** pp2) {
    if ( (*pp1)->getName() > (*pp2)->getName()) {
	Person* tempptr = *pp1;
	*pp1 = *pp2;
	*pp2 = tempptr;

    }
}

void bsort(Person** pp, int n) {
    for (int i = 0; i < n - 1; i++) {
	for (int k = i + 1; k < n; k++) {
	    order(pp + i, pp + k);
	}
    }
}

void salsort(Person** personPtr, int n) {
    for (int i = 0; i < n - 1; i++) {
	for (int k = i + 1; k < n; k++) {
	    if ((*(personPtr + i))->getSalary() > (*(personPtr + k))->getSalary()) {
		Person* tempPtr = *(personPtr+i);
		*(personPtr+i) = *(personPtr+k);
		*(personPtr+k) = tempPtr;
	    }
	}
    }
}
