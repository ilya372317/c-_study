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
        size = arr1.size;

        return *this;
    }

    ~Array() {
        delete [] ptr;
    }

    int& operator[] (int j) {
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

//TODO: write test for copy constructor

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}