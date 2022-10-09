// is char lower?
#include <iostream>
#include <ctype.h>

using namespace std;

int main(int argc, char *argv[]) 
{
    char userChar;
    
    cout << "Print one character to realise, is lower or upper" << endl;

    cin >> userChar;

    int isLower = islower(userChar);

    if (isLower > 0) {
        cout << "is lower" << endl;
    } else {
        cout << "is upper" << endl;
    }
}