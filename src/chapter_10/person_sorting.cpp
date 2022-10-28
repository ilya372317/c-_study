//
// Author Ilya Otinov
//

#include "iostream"
#include "string"

using namespace std;

class Person {
protected:
    string name;
public:
    void setName() {
        cout << "Print name: ";
	cin >> name;
    }

    void printName() const {
	cout << name << endl;
    }

    string getName() const {
	return name;
    }
};

void bsort(Person**, int);

void order(Person**, Person**);

int main() {
    Person* persPtr [100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
	persPtr[n]->setName();
	n++;
	cout << "Print next employee? [y/n]" << endl;
	cin >> choice;
    } while (choice == 'y');

    cout << "Not sorting list: " << endl;

    for (int i = 0; i < n; i++) {
	cout << "Employee number " << i + 1 << ": ";
	persPtr[i]->printName();
    }

   bsort(persPtr, n);

   cout << "sorting list:" << endl;

   for (int i = 0; i < n; i++) {
       cout << "Employee number " << i + 1 << ": ";
       persPtr[i]->printName();
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
