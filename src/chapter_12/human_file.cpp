//
// Created by Отинов Илья on 03.12.2022.
//

#include "fstream"
#include "iostream"

using namespace std;

class Human {
private:
    const static int MAX_NAME_LENGTH = 80;
    int age;
    int pokemonCard;
    char firstName[Human::MAX_NAME_LENGTH];
    char lastName[Human::MAX_NAME_LENGTH];
public:
    void getDataFromUser() {
        cout << "Print age: ";
        cin >> age;
        cout << "Print pokemon card: ";
        cin >> pokemonCard;
        cout << "Print first name: ";
        cin >> firstName;
        cout << "Print last name: ";
        cin >> lastName;
    }

    void showData() const {
        cout << "Age: " << age << endl
        << "Pokemon card: " << pokemonCard << endl
        << "First name: " << firstName << endl
        << "Last name: " << lastName << endl;
    }

    int humanInFileCount(ifstream&);

    friend ifstream& operator>> (ifstream& is, Human& h);
    friend ofstream& operator>> (ofstream& os, Human& h);
};

int Human::humanInFileCount(std::ifstream& is) {
    int humanSize = sizeof(*this);
    is.seekg(0, ios::end);
    return is.tellg() / humanSize;
}

ifstream& operator>> (ifstream& is, Human& h) {
    is >> h.age >> h.pokemonCard >> h.firstName >> h.lastName;
    return is;
}

ofstream& operator>> (ofstream& os, Human& h) {
    os << h.age << " " << " " <<  h.pokemonCard << " " << h.firstName << " " << h.lastName;
    return os;
}

int main(int argc, char* argv[]) {
    char fileName[] = "HUMAN_DATA.txt";
    ofstream os;
    os.open(fileName, ios::app);

    if (!os) {
        cerr << "Failed open file \"" << fileName <<  "\" for write" << endl;
        exit(1);
    }
    Human human{};

    char ch;

    do {
        human.getDataFromUser();
        os >> human;
        cout << "Print next human? [y/n] ";
        cin >> ch;
    } while (ch != 'n');

    os.close();

    ifstream is;
    is.open(fileName);

    while (!is.eof()) {
        is >> human;
        human.showData();
    }
}