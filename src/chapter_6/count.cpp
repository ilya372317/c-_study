//
// Created by ilya on 30.09.22.
//

#include "iostream"

using namespace std;

class Count {
private:
    int count;
    int test;
public:
    Count() : count(0) {
    };

    int getCount() {
        return count;
    }

    void incrementCount() {
        count++;
    }
};
