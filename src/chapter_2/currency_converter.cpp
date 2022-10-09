// Currency converter

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const double FUNT_STERLINGOV = 1.487;
    const double FRANK = 0.172;
    const double GERMANY_MARK = 0.584;
    const double JAPAN_YEN = 0.00955;

    double userDollars;

    cout << "Print how many $ you have, to convert them" << endl;
    
    cin >> userDollars;

    double funtSterlingov = userDollars * FUNT_STERLINGOV;
    double frank = userDollars * FRANK;
    double germanyMark = userDollars * GERMANY_MARK;
    double japanYen = userDollars * JAPAN_YEN;

    cout << "converted currencies: " << endl
        << "funt sterlingov: " << funtSterlingov << endl
        << "frank: " << frank << endl
        << "germany mark: " << germanyMark << endl
        << "japan yen: " << japanYen << endl;

    return 0;
}