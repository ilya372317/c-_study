//
// Author Ilya Otinov
//

#include "iostream"
#include "cstring"

using namespace std;

class Person {
private:
    char* name;
public:
    void setName() {
        cout << "Print name: ";
	char* inputName = new char [100];
	cin >> inputName;
	
	unsigned long length = strlen(inputName);
	name = new char [length + 1];
	strcpy(name, inputName);

	delete [] inputName;
    }

    void printName() {
	cout << endl << "Name: " << name << endl;
    }

    ~Person() {
        delete [] name;
    }
};

int main() {
    Person* persPtr [100];
    int n = 0;
    char choice;

    do {
        persPtr[n] = new Person;
	persPtr[n]->setName();
	n++;
	cout << "Fill next employee? [y/n]" << endl;
	cin >> choice;
    } while (choice == 'y');

    for (int i = 0; i < n; i++) {
	cout << "Information of number " << i + 1 << ": ";
       	persPtr[i]->printName();
    }
    cout << endl;

    return 0;
}
