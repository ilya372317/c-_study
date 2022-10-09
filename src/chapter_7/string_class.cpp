//
// Created by ilya on 05.10.22.
//

#include "string"
#include "iostream"

using namespace std;

int main() {
    string surname_and_patronymic, first_name, about;

    char test[10];

    cout << "Print last name and patronymic: ";
    getline(cin, surname_and_patronymic);

    cout << "Print first name: ";
    cin >> first_name;

    cout << "Print information about you: ";
    getline(cin, about, '$');

    cout << endl << "Your fio is: " << first_name << " " << surname_and_patronymic << endl
    << "And this information about you: " << about << endl;
}
