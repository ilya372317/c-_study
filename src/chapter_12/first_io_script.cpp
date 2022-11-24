//
// Created by Отинов Илья on 21.11.2022.
//

#include "iostream"
#include "gtest/gtest.h"
#include "cstring"

using namespace std;

class A {
private:
    int data;
public:
    A(): data(0) {}

    explicit A(int d): data(d) {}

    void showData() const {
        cout << this->getData() << endl;
    }

    int getData() const {
        return data;
    }

    virtual const char* getClassData() const {
        return "null";
    };

    const char* getDataString() const {
        const char* userString = this->getClassData();
        char* tempUserString = new char [strlen(userString)];
        strcpy(tempUserString, userString);
        string dataString = to_string(this->getData());
        const char* dataCString = dataString.c_str();
        strcat(tempUserString, dataCString);

        char* result = new char [strlen(userString) + 1];
        strcpy(result, tempUserString);
        result += '\0';

        delete [] tempUserString;

        return result;
    }
};

class B : public A {
public:
    B (): A(0) {}

    explicit B (int d): A(d) {}

    const char* getClassData() const override {
        return "data in class B ";
    }
};

class C : public A {
public:
    C () : A(0) {}

    explicit C (int d): A(d) {}

    const char* getClassData() const override {
        return "data in class C ";
    }
};

TEST(IoTest, InheritTest) {
    auto* b = new B(10);
    auto* c = new C(20);

    EXPECT_EQ(10, b->getData());
    EXPECT_EQ(20, c->getData());
}

TEST(IoTest, stringTest) {
    auto* b = new B(10);
    auto* c = new C(20);
    const char* bString = b->getDataString();
    const char* cString = c->getDataString();

    EXPECT_STREQ("data in class B 10", bString);
    EXPECT_STREQ("data in class C 20", cString);

    delete [] bString;
    delete [] cString;
}

void makeNewFile();

void writeDataInFile(char*, char*);

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}

void makeNewFile() {

}

void writeDataInFile(char* destFile, char* data) {

}