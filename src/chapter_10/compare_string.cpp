//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

int compstr(char*, char*);

int compchar(char, char);

void assertIntEquals(int, int);

int main() {
    char firstStr[] = "abc";
    char secondStr[] = "abc";
    char thirdStr[] = "bca";
    char fourthStr[] = "casdw";

    int compFirstAndSecond = compstr(firstStr, secondStr);
    int compSecondAndThird = compstr(secondStr, thirdStr);
    int compThirdAndSecond = compstr(thirdStr, secondStr);
    int compFourthAndThird = compstr(fourthStr, thirdStr);

    assertIntEquals(0, compFirstAndSecond);
    assertIntEquals(-1, compThirdAndSecond);
    assertIntEquals(1, compSecondAndThird);
    assertIntEquals(-1, compFourthAndThird);

    return 0;
}

int compstr(char* first, char* second) {
    int compResult = 0;
    bool isFirstEmpty = *(first) == '\0';
    bool isSecondEmpty = *(second) == '\0';

    if (isFirstEmpty && isSecondEmpty) {
	return 0;
    }

    if (isFirstEmpty) {
	return 1;
    } 

    if (isSecondEmpty) {
        return -1;
    }

    while (*(first) && *(second)) {
	compResult = compchar(*(first), *(second));
        if (compResult != 0) {
            return compResult;
	}
	first++;
	second++;
    }

    return compResult;
}

int compchar(char first, char second) {
    if (first == second) {
	return 0;
    }

    if (first > second) {
	return -1;
    }

    return 1;
}

void assertIntEquals(int expected, int actual) {
    bool intEquals = expected == actual;

    if (intEquals) {
	cout << "Test passed!" << endl;
    } else {
	cout << "Test failed!" << endl;
    }
}
