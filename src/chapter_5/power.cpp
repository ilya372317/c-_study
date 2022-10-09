// Power number in costume degree

#include <iostream>

using namespace std;

double power(double num, int degree);

int main(int argc, char *argv[])
{
    double num;
    int degree;

    cout << "Print number to power it: ";
    cin >> num;
    cout << "Print degree for power num: ";
    cin >> degree;

    cout << "Result: " << power(num, degree) << endl;
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