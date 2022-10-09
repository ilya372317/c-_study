// britan valute converter

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // old system:
    // 1 funt = 20 shilingam 
    // 1 shiling = 12 pensam
    // 1 funt = 240 pensam;

    // in new system:
    // 1 funt = 100 pensam
    // a need transform shilings in pens and multiply it in 0.466666
    const double COEF = 0.4347826987;

    int funt;
    int shiling;
    int pens;

    cout << "Print count of funt: ";
    cin >> funt;

    cout << "Print count of shilings: ";
    cin >> shiling;

    cout << "Print count of pens: ";
    cin >> pens;
 
    int totalPens = ((funt * 20 * 12) + (shiling * 12) + pens) * COEF;

    int funtResult = totalPens / 100;
    int pensResult = totalPens % 100;
    
    cout << "J" << funtResult << "." << pensResult << endl;
}