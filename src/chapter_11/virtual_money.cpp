//
// Created by Отинов Илья on 17.11.2022.
//

#include "iostream"
#include <cstdlib>
#include "gtest/gtest.h"

using namespace std;

class BigMoney {
private:
    long double money{};

    void convertStringToMoney(char* s) {
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
public:
    BigMoney(): money(0) {}

    explicit BigMoney(char* s) {
        this->convertStringToMoney(s);
    }

    BigMoney(long double m) {
        money = m;
    }

    long double getMoney() const {
        return money;
    }

    char* moneyToString() const {
        string moneyString = to_string(money);

        int positionOfDot = 0;

        for (auto& item:moneyString) {
            if (item == '.') {
                break;
            }
            positionOfDot++;
        }

        bool afterDotOnlyZeroDigits = true;

        const char* cMoneyString = moneyString.c_str();

        for (int i = 0; i < strlen(cMoneyString); i++) {
            if (i > positionOfDot && *(cMoneyString + i) != '0') {
                afterDotOnlyZeroDigits = false;
            }
        }

        if (afterDotOnlyZeroDigits) {
            auto* bufferMoneyString = new char [positionOfDot];

            for (int i = 0; i < positionOfDot; i++) {
                *(bufferMoneyString + i) = *(cMoneyString + i);
            }

            bufferMoneyString += '\0';
            cMoneyString = bufferMoneyString;
        }

        unsigned long countOfDots = (positionOfDot + 1) / 3;
        char* resultString = new char [strlen(cMoneyString) + countOfDots + 2];
        int n = 0;

        for (unsigned long i = strlen(cMoneyString), k = strlen(cMoneyString) + countOfDots;
        i > 0;
        i--, k--) {
            if ((n % 3) == 0 && i < positionOfDot) {
                *(resultString + (k - 1)) = '.';
                k--;
            }

            n++;

            *(resultString + (k - 1)) = *(cMoneyString + (i - 1));

            if (i == 1 && (k -1) > 0) {
                *(resultString + (k - 2)) = *(cMoneyString + (i - 1));
            }
        }

        resultString += '\0';

        return resultString;
    }

    static BigMoney add(BigMoney m1, BigMoney m2) {
        long double resultMoney = m1.money + m2.money;
        return {resultMoney};
    }

    static BigMoney minus(BigMoney m1, BigMoney m2) {
        long double result = m1.money - m2.money;
        return {result};
    }

    static BigMoney separate(BigMoney m1, BigMoney m2) {
        long double result = m1.money / m2.money;
        return {result};
    }

    static BigMoney multiply(BigMoney m1, BigMoney m2) {
        long double result = m1.money * m2.money;
        return {result};
    }

    friend BigMoney operator+(BigMoney, BigMoney);
    friend BigMoney operator-(BigMoney, BigMoney);
    friend BigMoney operator*(BigMoney, BigMoney);
    friend BigMoney operator/(BigMoney, BigMoney);
};

BigMoney operator+(BigMoney m1, BigMoney m2) {
    return BigMoney::add(m1, m2);
}

BigMoney operator-(BigMoney m1, BigMoney m2) {
    return BigMoney::minus(m1, m2);
}

BigMoney operator/(BigMoney m1, BigMoney m2) {
    return BigMoney::separate(m1, m2);
}

BigMoney operator*(BigMoney m1, BigMoney m2) {
    return BigMoney::multiply(m1, m2);
}

TEST(BigM, testMinusOperator) {
    BigMoney m1 = 5.0 - 2.0;
    EXPECT_DOUBLE_EQ(3.0, m1.getMoney());
}

TEST(BigM, testSeparateOpepator) {
    BigMoney m1 = 6.0 / 2.0;
    EXPECT_DOUBLE_EQ(3.0, m1.getMoney());
}

TEST(BigM, testMultiplyOperator) {
    BigMoney m1 = 2.0 * 5.0;
    EXPECT_DOUBLE_EQ(10.0, m1.getMoney());
}

TEST(BigM, testPlusOperator) {
    BigMoney m1 = 30.0 + 20.0;
    EXPECT_DOUBLE_EQ(50.0, m1.getMoney());
}

TEST(BigM, testConvertMoneyFromDotString) {
    char digitString[] = "1234654";
    auto* bigMoneyPtr = new BigMoney(digitString);
    char* moneyString = bigMoneyPtr->moneyToString();

    EXPECT_STREQ("1.234.654", moneyString);
}

TEST(BigM, testVeryLongConvert) {
    char digitString[] = "1000111222333444";
    auto* bigMoneyPtr = new BigMoney(digitString);
    char* moneyString = bigMoneyPtr->moneyToString();

    EXPECT_STREQ("1.000.111.222.333.444", moneyString);
}

TEST(BigM, testConvertMoneyToString) {
    char digitString[] = "5000";
    auto* bigMoneyPtr = new BigMoney(digitString);
    char* moneyString = bigMoneyPtr->moneyToString();

    EXPECT_STREQ("5.000", moneyString);

}

TEST(BigM, testConstructorWithDigitString) {
    char digitString[] = "3000000000";
    auto* bigMoneyPtr = new BigMoney(digitString);

    EXPECT_DOUBLE_EQ(3000000000, bigMoneyPtr->getMoney());

    delete bigMoneyPtr;
}

TEST(BigM, testConstructorWithNonDigitString) {
    char nonDigitString[] = "$3000.25 #";
    auto* bigMoneyPtr = new BigMoney(nonDigitString);

    EXPECT_DOUBLE_EQ(3000.25, bigMoneyPtr->getMoney());

    delete bigMoneyPtr;
}

TEST(BigM, testConstructorWithVeryLongString) {
    char digitString[] = "$3000000000000000";
    auto* bigMoneyPtr = new BigMoney(digitString);

    EXPECT_DOUBLE_EQ(3000000000000000, bigMoneyPtr->getMoney());
}

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
