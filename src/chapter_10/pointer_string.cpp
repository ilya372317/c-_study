//
// Author Ilya Otinov
//

#include "iostream"
#include "cstring"

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
};

int main() {
    char str[] = "My impressive string!";
    String* s1Pointer = new String(str);

    s1Pointer->display();

    return 0;
}
