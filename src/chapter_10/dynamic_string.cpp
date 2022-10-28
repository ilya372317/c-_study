//
// Author Ilya Otinov
//

#include "iostream"
#include "cstring" 

using namespace std;

int main() {
    char str[] = "This is string for copy";
    int len = strlen(str);

    char* pstr;
    pstr = new char[len + 1];

    strcpy(pstr, str);

    cout << pstr << endl;

    return 0;

    delete [] pstr;
}
