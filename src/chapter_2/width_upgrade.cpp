// Upgrade width programm

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    long pop1 = 8425785, pop2 = 47, pop3 = 9761;
    cout << setfill('.') << setw(9) << "Город " << setw(12) 
    << "Население " << endl
    << setw(9) << "Москва" << setw(12) << pop1 << endl
    << setw(9) << "Киров" << setw(12) << pop2 << endl
    << setw(9) << "Угрюмовка" << setw(12) << pop3 << endl;
}