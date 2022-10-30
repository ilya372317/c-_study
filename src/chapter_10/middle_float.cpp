//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

const int MAX = 50;

int main() {
    float array[MAX];

    char choice;
    int n = 0;

    do {
        cout << "Print float number: ";
	cin >> *(array + n);
	n++;
	cout << "add another number? [y/n]" << endl;
	cin >> choice;
	
    } while (choice == 'y');

    float floatSum = 0.0f;
    for (int i = 0; i < n; i++) {
	floatSum += *(array + i);
    }

    float result = floatSum / n;

    cout << "result: " << result << endl;

    return 0;
}

