// function celsia converter

#include <iostream>

using namespace std;

inline float celsiaConverter(float celsia);

int main()
{
    float celsia;

    cout << "Print temprature in celsia: " << endl;

    cin >> celsia;

    cout << "Temprature in faringate: " << celsiaConverter(celsia) << endl;
}

inline float celsiaConverter(float celsia)
{
   return (celsia * 9 /5) + 32;
}
