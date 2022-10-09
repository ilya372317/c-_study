// Power 2.0 programm;

#include <iostream>

using namespace std;

double power(double num, int deegree);
double power(char num, char deegre);
inline double power(int num, int degree);
inline double power(long num, long degree);

int main(int argc, char *argv[])
{
    int num;
    int degree;

    cout << "Print number to power: ";
    cin >> num;

    cout << "Print degree: ";
    cin >> degree;
 
    cout << "Result: " << power(num, degree) << endl;

    return 0;
}

double power(double num, int deegree)
{
    double result = num;
    for (int i = deegree; i > 1; i--) 
    {
         num *= result;
    }

    return num;
}

double power(char num, char degree)
{
    return power(static_cast<double>(num), static_cast<double>(degree));
}

inline double power (int num, int degree)
{
    return power(static_cast<double>(num), static_cast<double>(degree));
}

inline double power (long num, long degree)
{
    return power(static_cast<double>(num), static_cast<double>(degree));
}