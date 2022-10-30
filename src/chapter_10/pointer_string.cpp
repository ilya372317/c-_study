//
// Author Ilya Otinov
//

#include "iostream"
#include "cstring"
#include "cctype"

using namespace std;

class String {
private:
    char* str;
public:
    String(char* s) {
        int length = strlen(s);
	str = new char [length + 1];
	strcpy(str, s);
    }

    ~String() {
        cout << "Удаляем строку" << endl;
	delete [ ] str;
    }

    void display() const {
        cout << str << endl;
    }

    void toUpper() {
	char* newStr = new char[strlen(str)];
	for (int i = 0; i < strlen(str); i++) {
	    *(newStr + i) = toupper(*(str + i));
	}
	delete [ ] str;

	str = newStr;
    }
};

void testToUpperMethod();

int main() {
    char str[] = "My impressive string!";
    String* s1Pointer = new String(str);

    s1Pointer->display();

    testToUpperMethod();

    return 0;
}

void testToUpperMethod() {
    char str[] = "test to upper method string";

    String* myStr = new String(str);

    myStr->toUpper();
    myStr->display();
}
