//
// Created by Отинов Илья on 29.11.2022.
//

#include "iostream"
#include "fstream"

using namespace std;

const int FIO_LEN = 32;
const int MAX_EMPLOYEE = 100;

enum employee_type {
    tmanager,
    tscientist,
    tlaborer,
};

class employee {
private:
    char name[FIO_LEN];
    unsigned long number;
    static int n;
    static employee* arrap[];

public:
    virtual void get_data() {
        cin.ignore(10, '\n');
        cout << "Print surname: ";
        cin >> name;
        cout << "Print number: ";
        cin >> number;
    }

    virtual void put_data() const {
        cout << "Surname: " << name << endl
        << "Number: " << number << endl;
    }

    virtual employee_type get_type();
    virtual void read_self(ifstream& is);
    static void add();
    static void display();
    static void read();
    static void write();
};

int employee::n;
employee* employee::arrap[MAX_EMPLOYEE];

class manager : public employee {
private:
    char title[FIO_LEN];
    double dues;
public:
    manager(char t[], double d) {
        strcpy(title, t);
        dues = d;
    }

    void get_data() override {
        employee::get_data();
        cout << "Print title: ";
        cin >> title;
        cout << "Print taxes: ";
        cin >> dues;
    }

    void put_data() const override {
        employee::put_data();
        cout << "Title: " << title << endl
        << "Dues: " << dues << endl;
    }
};

class scientist : public employee{
private:
    int pubs;
public:
    void get_data() override {
        employee::get_data();
        cout << "Print count of publication: ";
        cin >> pubs;
    }

    void put_data() const override {
        employee::put_data();
        cout << "Count of publication: " << pubs << endl;
    }
};

class laborer : public employee {
    int count = 1;
};

void employee::read_self(ifstream &is) {
    is.read((char*) this, sizeof(*this));
}

void employee::add() {
    char ch;

    cout << "m - for add manager" << endl
    << "s - for add scientist" << endl
    << "l - for add laborer" << endl
    << "You choice: ";
    cin >> ch;

    switch (ch) {
        case 'm':
            arrap[n] = new manager;
            break;
        case 's':
            arrap[n] = new scientist;
            break;
        case 'l':
            arrap[n] = new laborer;
            break;
        default:
            cout << "Unknown type of employee." << endl;
            return;
    }

    arrap[n++]->get_data();
    int test = 0;
}

employee_type employee::get_type() {
    if (typeid(*this) == typeid(manager)) {
        return tmanager;
    }

    if (typeid(*this) == typeid(scientist)) {
        return tscientist;
    }

    if (typeid(*this) == typeid(laborer)) {
        return tlaborer;
    }

    cerr << "Unknown type! Fatal error." << endl;
    return tmanager;
}

void employee::display() {
    for (int i = 0; i < n; i++) {
        cout << (i + 1);
        int testn = n;
        employee* testarr[100];
        testarr[i] = arrap[i];
        switch (arrap[i]->get_type()) {
            case tmanager:
                cout << " Type manager" << endl;
                break;
            case tscientist:
                cout << " Type scientist" << endl;
                break;
            case tlaborer:
                cout << " Type laborer" << endl;
                break;
            default:
                cout << " Unknown type" << endl;
                break;
        }
        arrap[i]->put_data();
        cout << endl;
    }
}

void employee::write() {
    int size;
    employee_type etype;
    ofstream os;

    cout << "writing " << n << " emoloyee in file..." << endl;

    os.open("EMPLOYEE.DAT", ios::binary | ios::trunc);

    if (!os) {
        cerr << "Failed to open file for write" << endl;
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        etype = arrap[i]->get_type();
        os.write((char*) &etype, sizeof(etype));

        if (!os) {
            cerr << "Failed write type of employee" << endl;
            exit(1);
        }

        switch (etype) {
            case tmanager:
                size = sizeof(manager);
                break;
            case tscientist:
                size = sizeof(scientist);
                break;
            case tlaborer:
                size = sizeof(laborer);
                break;
            default:
                cerr << "Unknown type!" << endl;
                exit(1);
        }
        os.write((char*)arrap[i], size);

        if (!os) {
            cerr << "Failed write employee in file" << endl;
            exit(1);
        }
    }
}

void employee::read() {
    int size;
    ifstream is;
    employee_type etype;
    is.open("EMPLOYEE.DAT", ios::binary);

    if (!is) {
        cerr << "Failed open file for read" << endl;
        exit(1);
    }

    n = 0;

    while (true) {
        is.read((char*) &etype, sizeof(employee_type));

        if (is.eof()) {
            break;
        }

        if (!is) {
            cerr << "Failed read type from file" << endl;
            exit(1);
        }
        char test[] = "";
        auto* tempManager = new manager(test, 20.2);

        switch (etype) {
            case tmanager:
                arrap[n] = new manager;
                break;
            case tscientist:
                arrap[n] = new scientist;
                size = sizeof(scientist);
                break;
            case tlaborer:
                arrap[n] = new laborer;
                size = sizeof(laborer);
                break;
            default:
                cerr << "Unknown type" << endl;
                exit(1);
        }
        arrap[n]->read_self(is);

        if (!is) {
            cerr << "Fail read employee form file" << endl;
            exit(1);
        }

        n++;
    }

    cout << "Reading " << n << " employees" << endl;
}

int main() {
    char ch;

    while (true) {
        cout << "a - add employee" << endl
        << "d - display all employees" << endl
        << "w - write employees in file" << endl
        << "r - read employees from file" << endl
        << "x - exit from program" << endl;

        cin >> ch;

        switch (ch) {
            case 'a':
                employee::add();
                break;
            case 'd':
                employee::display();
                break;
            case 'w':
                employee::write();
                break;
            case 'r':
                employee::read();
                break;
            case 'x':
                exit(0);
            default:
                cout << "Unknown command" << endl;
        }
    }
}

