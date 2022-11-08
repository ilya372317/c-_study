//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

class Person {
protected:
    char name[40];
public:
    virtual ~Person() {
	cout << "person with name " << name << " deleted" << endl;
    }

    void getName() {
	cout << "Print name: ";
	cin >> name;
    }

    void putName() const {
	cout << "Name: " << name << endl;
    }

    virtual void getData() = 0;
    virtual bool isOutstanding() const = 0;
};

class Student : public Person {
private:
    float gpa;
public:
    void getData() {
	Person::getName();
	cout << "Avarege student point: ";
	cin >> gpa;
    }

    bool isOutstanding() const {
	return gpa > 3.5;
    }
};

class Professor : public Person {
private:
    int numPubs;
public:
    void getData() {
	Person::getName();
	cout << "Print number of publication of professor: ";
	cin >> numPubs;
    }

    bool isOutstanding() const {
	return numPubs > 100;
    }
};

int main() {
    Person* persPtr[100];	
    int n = 0;
    char choice;

    do {
	char studentOrProfessor;
	cout << "Fill information about student or professor? [s/p]" << endl;
	cin >> studentOrProfessor;
	
	if (studentOrProfessor == 's') {
	    persPtr[n] = new Student();
	} else if (studentOrProfessor == 'p') {
	    persPtr[n] = new Professor();
	} else {
	    cout << "wrong character of professor of student, try again!" << endl;
	    continue;
	}

	persPtr[n++]->getData();

	cout << "continue? [y/n]" << endl;
	cin >> choice;
	
	
    } while(choice == 'y');

    for (int i = 0; i < n; i++) {
	persPtr[i]->putName();

	if (persPtr[i]->isOutstanding()) {
	    cout << "Is outstanding human!" << endl;
	}

	delete persPtr[i];
    }
}

