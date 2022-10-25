//
// Created by ilya on 24.10.22.
//

#include <cstring>
#include "iostream"
#include <cstdlib>

using namespace std;

class String {
protected:
    static const int MAX_LENGTH = 20;
    char str[MAX_LENGTH]{};

public:
    String() {
        strcpy(str, "");
    }

    explicit String(char c[]) {
        strcpy(str, c);
    }

    void display() const {
        cout << str;
    }

    [[nodiscard]] const char* c_str() const {
        return str;
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

class PString : public String {
public:
    PString(): String() {}

    explicit PString(char* string1) {
        if (strlen(string1) > MAX_LENGTH - 1) {
            for (int i = 0; i < MAX_LENGTH - 1; i++) {
                str[i] = string1[i];
            }
        } else {
            strcpy(str, string1);
        }
    }
};

void testVeryLongStringPut();

void testShortStringPut();

void assertStringEquals(char* expected, PString actual);

int main() {
    testVeryLongStringPut();
    testShortStringPut();
}

void testVeryLongStringPut() {
    char testString[] = "test is good. And this is very long string";
    PString pString(testString);

    char expected[] = "test is good. And t";

    assertStringEquals(expected, pString);
}

void testShortStringPut() {
    char testString[] = "This is short str";
    PString pString(testString);

    char expected[] = "This is short str";

    assertStringEquals(expected, pString);
}

void assertStringEquals(char* expected, PString actual) {
    unsigned long expectedLength = strlen(expected);
    unsigned long actualLength = strlen(actual.c_str());

    cout << "expected: " << expected << ", actual: ";
    actual.display();
    cout << endl;
    if (expectedLength == actualLength) {
        cout << "Test passed!";
    } else {
        cout << "Test failed!";
    }

    cout << endl;
}
