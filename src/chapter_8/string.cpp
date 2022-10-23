//
// Created by ilya on 13.10.22.
//
// STRPLUS

#include <cstring>
#include "iostream"
#include <cstdlib>

using namespace std;

class String {
private:
    static const int MAX_LENGTH = 300;
    char str[MAX_LENGTH]{};

public:
    String() {
        strcpy(str, "");
    }

    String(char c[]) {
        strcpy(str, c);
    }

    void display() const {
        cout << str;
    }

    String operator+(String ss) {
        String tempString;

        if (strlen(str) + strlen(ss.str) < MAX_LENGTH) {
            strcpy(tempString.str, str);
            strcat(tempString.str, ss.str);
        } else {
            cout << "String is more then " << MAX_LENGTH << "!" << endl;
            exit(1);
        }

        return tempString;
    }

    void operator+= (String ss) {
        if (strlen(str) + strlen(ss.str) > MAX_LENGTH) {
            cout << "String is more then " << MAX_LENGTH << "!" << endl;
            exit(1);
        }

        strcat(str, ss.str);
    }
};

int main() {
    char strName[100] = "Ilya";
    char strSurname[100] = "Otinov";
    String name = strName;
    String surname = strSurname;

    name += surname;

    name.display();
    cout << endl;
}
