//
// Created by Отинов Илья on 17.11.2022.
//

#include "iostream"
#include <cstdlib>
#include "gtest/gtest.h"

using namespace std;

class BigMoney {
private:
    long double money;
public:
    BigMoney(): money(0) {}

    explicit BigMoney(char* s) {
        char* copyStr = new char [strlen(s) + 1];
        char* copyStrStart = copyStr;

        while (*s != '\0') {
            if (isdigit(*s) || *s == '.') {
                *copyStr = *s;
                copyStr++;
            }
            s++;
        }

        copyStr = copyStrStart;
        copyStr += '\0';

        money = strtold(copyStr, &copyStr);

        delete [] copyStrStart;
    }

    long double getMoney() const {
        return money;
    }
};

TEST(BigM, testConstructorWithDigitString) {
    char digitString[] = "3000000000";
    auto* bigMoneyPtr = new BigMoney(digitString);

    EXPECT_DOUBLE_EQ(3000000000, bigMoneyPtr->getMoney());
}

TEST(BigM, testConstructorWithNonDigitString) {
    char nonDigitString[] = "$3000.25 #";
    auto* bigMoneyPtr = new BigMoney(nonDigitString);

    EXPECT_DOUBLE_EQ(3000.25, bigMoneyPtr->getMoney());
}

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
