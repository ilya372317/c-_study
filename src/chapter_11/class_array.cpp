//
// Created by Отинов Илья on 16.11.2022.
//

#include "iostream"
#include "gtest/gtest.h"

using namespace std;

class Array {
private:
    int* ptr;
    int size;
public:
    explicit Array(int s) {
        size = s;
        ptr = new int [s];
    }

    Array(Array& arr1) {
        ptr = new int[arr1.size];
        size = arr1.size;

        for (int i = 0; i < arr1.size; i++) {
            *(ptr + i) = *(arr1.ptr + i);
        }
    }

    Array& operator = (Array arr1) {
        if (this != &arr1) {
            delete [] ptr;
        }

        ptr = new int [arr1.size];
        for (int i = 0; i < arr1.size; i++) {
            *(ptr + i) = *(arr1.ptr + i);
        }

        size = arr1.size;

        return *this;
    }

    ~Array() {
        delete [] ptr;
    }

    int& operator[] (int j) {
        if (j >= size) {
            cout << "Out of bounds!" << endl;
            exit(1);
        }
        return *(ptr + j);
    }
};

TEST(class_array, testOperatorBrace) {
    const int ARR_SIZE = 10;
    Array arr(ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = i*i;
    }

    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[1], 1);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[3], 9);
    EXPECT_EQ(arr[4], 16);
    EXPECT_EQ(arr[5], 25);
    EXPECT_EQ(arr[6], 36);
    EXPECT_EQ(arr[7], 49);
    EXPECT_EQ(arr[8], 64);
    EXPECT_EQ(arr[9], 81);
}

TEST(classArray, copyConstructorAndAssigmentOperator) {
    Array arr1(10);
    for (int i = 0; i < 10; i++) {
        arr1[i] = i*i;
    }

    Array arr2(20);
    Array arr3 = arr2 = arr1;

    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(arr1[0], 0);
        EXPECT_EQ(arr2[1], 1);
        EXPECT_EQ(arr3[3], 9);
        EXPECT_EQ(arr3[5], 25);
    }
}

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}