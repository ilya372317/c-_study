//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

const int MAX = 10;

int main() {
    int* arr[MAX];

    for (int i = 0; i < MAX; i++) {
	*(arr + i) = new int [MAX];
	for (int k = 0; k < MAX; k++) {
	    *(*(arr + i) + k) = k;
	}
    }

    for (int i = 0; i < MAX; i++){
	for (int k = 0; k < MAX; k++) {
	    cout << *(*(arr + i) + k) << endl;
	}
    }
}
