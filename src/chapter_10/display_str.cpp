//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;
 
void dispstr(char* str);

int main() {
    char str[] = "Ilya Otinov";
    char secondStr[] = "Sofia Vasileva";

    dispstr(str);
    cout << endl;

    dispstr(secondStr);
    cout << endl;

    return 0;
}

void dispstr(char* str) {
    while (*str) {
        cout << *str++;
    }
}
