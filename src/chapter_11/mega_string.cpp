//
//Author Ilya Otinov
//

#include "iostream"
#include "cstring"

using namespace std;

class StringCount {
private:
    int count;
    char* str;

    friend class String;

    StringCount(char* s) {
	int length = strlen(s);

	str = new char[length + 1];

	strcpy(str, s);
	count = 1;
    }

    ~StringCount() {
	delete[] str;
    }
};

class String {
private:
    StringCount* psc;
public:
    String() {
	char nullStr[] = "NULL";
        psc = new StringCount(nullStr);    
    }

    String(char* s) {
	psc = new StringCount(s);
    }

    String(String& S) {
	psc = S.psc;
	(psc->count)++;
    }

    ~String() {
	if (psc->count == 1) {
	    delete psc;
	} else {
	    (psc->count)--;
	}
    }

    void display() const {
	cout << psc->str;
	cout << " (addr: " << psc << ")";
    }

    String& operator = (String& S) {
	if (this == &S) {
	    return *this;
	}

	if (psc->count == 1) {
	    delete psc;
	} else {
	    (psc->count)--;
    	}
        psc = S.psc;
        (psc->count)++;

	return *this;
    }
};

int main() {
    char str[] = "This is very simple string";

    String s3 = str;

    cout << endl << "s3 = ";
    s3.display();

    String s1 = s3;
    String s2 = s1;

    cout << endl << "s1 = ";
    s1.display();

    cout << endl << "s2 = ";
    s2.display();

    cout << endl << "address s1: " << &s1
    << endl << "address s2: " << &s2 << endl;

    s3 = s2;
    s2 = s1;

    cout << endl << "s1 = ";
    s1.display();

    cout << endl << "s2 = ";
    s2.display();
}
