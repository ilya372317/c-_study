//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;

const int ARR_LENGTH = 3;

void transfer_arr(float*, float*, float*, int length);

int main() {
    float arr1[] = {1.1f, 2.2f, 3.3f};
    float arr2[] = {4.4f, 5.5f, 6.6f};
    float arr3[ARR_LENGTH];

    transfer_arr(arr1, arr2, arr3, ARR_LENGTH);

    for (int i = 0; i < ARR_LENGTH; i++) {
	cout << *(arr3 + i) << endl;
    }
}

void transfer_arr(float* first, float* second, float* dest, int length) {
    for (int i = 0; i < length; i++) {
	*(dest + i) = *(first + i) + *(second + i);
    }
}
