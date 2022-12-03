//
// Created by Отинов Илья on 03.12.2022.
//

#include "iostream"
#include "fstream"
#include <SFML/Window.hpp>

using namespace std;

class Name {
private:
    static fstream file;
    static const int NAME_LENGTH = 80;
    char first_name[NAME_LENGTH];
    char last_name[NAME_LENGTH];
    unsigned long number;
public:
    void get_data() {
        cout << "Print number: ";
        cin >> number;

        cout << "Print first name: ";
        cin >> first_name;

        cout << "Print last name: ";
        cin >> last_name;
    }

    void show_data() const {
        cout << "Number: " << number << endl
             << "First name: " << first_name << endl
             << "Last name: " << last_name << endl;
    }

    static void set_file(const char *file_name);

    static void reset_file();

    static void write(Name &name);

    static void read(Name &name);

    static Name *findNameInFile(unsigned long n);
};

fstream Name::file;

void Name::set_file(const char *file_name) {
    file.open(file_name, ios::app | ios::in | ios::out);
    if (!file) {
        cerr << "Failed open file " << file_name;
        exit(1);
    }
}

void Name::reset_file() {
    file.seekg(0);
    file.flush();
}

void Name::write(Name &name) {
    file << name.number << " " << name.first_name << " " << name.last_name << " ";
}

void Name::read(Name &name) {
    file >> name.number >> name.first_name >> name.last_name;
}

Name *Name::findNameInFile(unsigned long n) {
    auto *name = new Name();
    while (!file.eof()) {
        Name::read(*name);

        if (name->number == n) {
            return name;
        }
    }

    delete name;
    return nullptr;
}

int main(int argc, char *argv[]) {
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;

}