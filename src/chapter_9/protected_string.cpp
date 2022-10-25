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
    static const char* LENGTH_ERROR_MESSAGE;
    String() {
        strcpy(str, "");
    }

    explicit String(char c[]) {
        strcpy(str, c);
    }

    void display() const {
        cout << str;
    }

    [[nodiscard]] const char *c_str() const {
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

    void operator+=(String ss) {
        if (strlen(str) + strlen(ss.str) > MAX_LENGTH) {
            cout << "String is more then " << MAX_LENGTH << "!" << endl;
            exit(1);
        }

        strcat(str, ss.str);
    }
};

const char* String::LENGTH_ERROR_MESSAGE = "Left function can`t be done. length more then string length";

class PString : public String {
public:
    PString() : String() {}

    explicit PString(const char *string1) {
        if (strlen(string1) > MAX_LENGTH - 1) {
            for (int i = 0; i < MAX_LENGTH - 1; i++) {
                str[i] = string1[i];
            }
        } else {
            strcpy(str, string1);
        }
        unsigned long strLength = strlen(str);
        str[strLength] = '\0';
    }
};

class SliceString : public PString {
public:
    static const char* POSITION_ERROR_MESSAGE;

    SliceString() : PString() {}

    explicit SliceString(char *string1) : PString(string1) {}

    void left(PString &pString, int n) {
        unsigned long baseStringLength = strlen(str);

        if (n >= baseStringLength) {
            cout << String::LENGTH_ERROR_MESSAGE << endl;
            return;
        }

        char newStr[n + 1];
        for (int i = 0; i < n; i++) {
            newStr[i] = str[i];
        }
        newStr[n] = '\0';

        PString newString(newStr);
        pString = newString;
    }

    void mid(PString &pString, int position, int n) {
        if (position >= n) {
            cout << SliceString::POSITION_ERROR_MESSAGE << endl;
            return;
        }

        unsigned long strLength = strlen(str);

        if ((position + n) > strLength) {
            cout << String::LENGTH_ERROR_MESSAGE << endl;
            return;
        }

        char newStr[n + 1];

        for (int i = position, k = 0; k < n; i++, k++) {
            newStr[k] = str[i];
        }

        newStr[n] = '\0';

        pString = PString(newStr);
    }

    void right(PString &pString, int n) {
        unsigned long baseStringLength = strlen(str);

        unsigned long positionOfStartCat = (baseStringLength) - n;

        if (n >= baseStringLength) {
            cout << String::LENGTH_ERROR_MESSAGE << endl;
            return;
        }

        char newStr[n + 1];

        for (unsigned long i = positionOfStartCat, k = 0; k < n; i++, k++) {
            newStr[k] = str[i];
        }

        newStr[n] = '\0';

        PString newString(newStr);

        pString = newString;
    }
};

const char* SliceString::POSITION_ERROR_MESSAGE = "Invalid position for slice";

void testRightMethod();

void testRightLengthError();

void testMidInvalidStartPosition();

void testMidMethod();

void testMidInvalidLength();

void testVeryLongStringPut();

void testShortStringPut();

void testLeftMethodWithExtraLength();

void testLeftMethod();

void assertStringEquals(char *expected, PString actual);

int main() {
    testVeryLongStringPut();
    testShortStringPut();
    testLeftMethod();
    testLeftMethodWithExtraLength();
    testMidInvalidLength();
    testMidInvalidStartPosition();
    testMidMethod();
    testRightMethod();
    testRightLengthError();
}

void testRightMethod() {
    char startStr[] = "Ilya Otinov";
    SliceString s1(startStr), s2;

    s1.right(s2, 6);

    char expected[] = "Otinov";

    assertStringEquals(expected, s2);
}

void testRightLengthError() {

}

void testMidInvalidStartPosition() {
    char startStr[] = "Ilya Otinov Andreevich";
    SliceString s1(startStr), s2;

    s1.mid(s2, 6, 5);

    char expected[] = "";

    assertStringEquals(expected, s2);
}

void testMidMethod() {
    char startStr[] = "Ilya Otinov Andreevich";
    SliceString s1(startStr), s2;

    s1.mid(s2, 5, 6);

    char expected[] = "Otinov";

    assertStringEquals(expected, s2);
}

void testMidInvalidLength() {
    char startStr[] = "Ilya Otinov Andreevich";
    SliceString s1(startStr), s2;

    s1.mid(s2, 20,30);

    char expected[] = "";

    assertStringEquals(expected, s2);
}

void testLeftMethod() {
    char firstStr[] = "Ilya Otinov";
    SliceString s1(firstStr), s2;

    s1.left(s2, 4);
    char expected[] = "Ilya";

    assertStringEquals(expected, s2);
}

void testLeftMethodWithExtraLength() {
    char firstStr[] = "Ilya otinov";
    SliceString s1(firstStr), s2;

    s1.left(s2, 12);
    char expected[] = "";

    assertStringEquals(expected, s2);
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

void assertStringEquals(char *expected, PString actual) {
    bool stringEquals = strcmp(expected, actual.c_str()) == 0;

    cout << "expected: " << expected << ", actual: ";
    actual.display();
    cout << endl;
    if (stringEquals) {
        cout << "Test passed!";
    } else {
        cout << "Test failed!";
    }

    cout << endl;
}
