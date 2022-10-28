//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

void question_1();
void question_2();
void question_4();
void question_8();
void question_13();
void question_14();
void question_18();
void question_19();
void question_22();
void question_29();

int main() {
    question_1();
    question_2();
    question_4();
    question_8();
    question_13();
    question_14();
    question_18();
    question_19();
    question_22();
    question_29();
}

void question_1() {
    int tempInt;

    cout << "Question 1 result:";

    cout << &tempInt << endl;
}

void question_2() {
    float arr[] = {1.1f, 2.2f, 3.3f};

    cout << "result of question 2:" << endl;

    for (float i : arr) {
        cout << &i << " value: " << i << endl;
    }
}

void question_4() {
    int var = 10;

    cout << "result of question 4:" << endl;
    cout << "a) " << &var << endl
    << "b) " << var << endl;
}

void question_8() {
    int var = 10;
    int* varPtr = &var;
    
    cout << "result of question 8: " << *varPtr << endl;
}

void question_13() {
    int arr[] = {1,2,3,4};

    cout << "result of question 13: " << endl
    << "value of index 3 by braces: " <<  arr[3] << endl
    << "addresses of value with index 3: " << arr + 3 << endl
    << "value of index 3 by pointer: " << *(arr + 3) << endl;
}

void question_14() {
    int intarr [77];
    int* intarrPtr = intarr;

    for (int i = 0; i < 77; i++) {
	intarr[i] = i + 1;

	cout << *intarrPtr++ << ", ";
    }

    cout << endl;

    cout << "result of question 14: " << endl;
}

void print_cstr(char* str) {
    while (*str) {
	cout << *str++;
    }
}

void question_18() {
    char str[] = "Ilya Otinov";

    cout << "result of question 18: ";

    print_cstr(str);

    cout << endl;
}

void copy_str(char* dest, char* source) {
    int counter = 0;
    while (*source) {
	*dest++ = *source++;
	counter++;

	
        if (counter >= 80) {
	    break;
	}

	*dest = '\0';
    }
}

void question_19() {
    char name[] = "Ilya";
    char copyName[80];

    copy_str(copyName, name);

    cout << "result of question 19: " << copyName << endl;
}

char* revstr(char*);

void question_22() {
    char* numptrs[3];

    char one[] = "one";
    char two[] = "two";
    char three[] = "three";
    
    numptrs[0] =  one;
    numptrs[1] = two;
    numptrs[2] = three;

    for (int i = 0; i < 3; i++) {
	cout << *(numptrs + i) << endl;
    }
}

void question_29() {
    float* arr[8];

    for (int i = 0; i < 8; i++) {
	float tempFloat = i + 0.1f;
	arr[i] = &tempFloat;
    }

    cout << "result of question 29: ";
    for (int i = 0; i < 8; i++) {
	cout << **(arr + i) << ", ";
    }
    cout << endl;
}

