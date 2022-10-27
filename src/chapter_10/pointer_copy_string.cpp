//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;

void copy_string(char* dest, const char* src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main() {
    char name[] = "Ilya Otinov";
    char copy_name[80]; 

    copy_string(copy_name, name);

    cout << copy_name << endl;
}
