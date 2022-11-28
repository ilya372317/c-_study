//
// Created by Отинов Илья on 27.11.2022.
//

#include "iostream"
#include "fstream"

using namespace std;

class Person {
protected:
    char name[80]{};
    int age;
public:
    Person(): age(0){}

    Person(const char* n, int a) : age(a) {
        strcpy(name, n);
    }

    void getData();
    void showData() const;
};

void Person::showData() const {
    cout << "User name: " << name << endl;
    cout << "User age: " << age << endl;
}

void Person::getData() {
    while (true) {
        cout << "Print user name: ";
        cin.clear();
        cin.get(name, 80, '\n');
        if (cin.good()) {
            cin.ignore(80, '\n');
            break;
        }
        cout << "Invalid user name, try again!" << endl;
        cin.ignore(80, '\n');
        cin.clear();
    }

    while (true) {
       cout << "Print user age: ";
       cin >> age;
       if (cin.good()) {
           cin.ignore(10, '\n');
           break;
       }
       cout << "Age is incorrect, try again!" << endl;
       cin.clear();
       cin.ignore(10, '\n');
    }
}

void writeSeveralObject( const char* fileName);
void readPersons(const char* fileName);
void findPersonByNumber();

int main() {
//    const char* fileName = new char [] {"PERSON_DATA.txt"};
//    writeSeveralObject(fileName);
//    readPersons(fileName);



    findPersonByNumber();
    return 0;
}

void writeSeveralObject(const char* fileName) {
    ofstream fileWrite;
    fileWrite.open("PERSON_DATA.txt", ios::out | ios::app);

    char next;
    Person person;
    do {
        cout << "Print person data: " << endl;

        person.getData();

        fileWrite.write(reinterpret_cast<char*>(&person), sizeof(person));

        cout << "Next? (y/n)";
        cin >> next;
        cin.ignore(10, '\n');
        fileWrite.seekp(ios::end);
    } while (next != 'n');
    fileWrite.close();
}
void readPersons(const char* fileName) {
    ifstream fileRead;
    fileRead.open("PERSON_DATA.txt", ios::in);
    fileRead.seekg(0);
    Person person;
    fileRead.read(reinterpret_cast<char*>(&person), sizeof(person));

    while (!fileRead.eof()) {
        person.showData();
        fileRead.read(reinterpret_cast<char*>(&person), sizeof(person));
    }
    cout << endl;
}

void findPersonByNumber() {
    ifstream fileRead;
    Person person;
    fileRead.open("PERSON_DATA.txt", ios::in);
    fileRead.seekg(0, ios::end);
    long endOfPositionInFile = fileRead.tellg();
    long countOfPersonInFile = endOfPositionInFile / sizeof(person);

    cout << "File have " << countOfPersonInFile << endl;
    int n;
    while (true) {

        cout << "Print number of person :";
        cin.ignore(10, '\n');
        cin >> n;

        if (n > countOfPersonInFile) {
            cin.clear(ios::badbit);
            cin.ignore(10, '\n');
        }

        if (cin.good()) {
            cin.ignore(10, '\n');
            break;
        }

        cout << "wrong number, print number equal or less then " << countOfPersonInFile << endl;
    }

    fileRead.seekg((n - 1) * sizeof(person));

    fileRead.read(reinterpret_cast<char*>(&person), sizeof(person));

    person.showData();
}