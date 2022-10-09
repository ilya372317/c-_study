// Celcia converter to faringate

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    float celcia;

    cout << "Print temprature in celcia to convert it to faringate" << endl;
    cin >> celcia;

    float faringate = (celcia * 9 / 5) + 32;

    cout << "Temparature in faringate equals: " << faringate << "F" << endl; 

    return 0;
}