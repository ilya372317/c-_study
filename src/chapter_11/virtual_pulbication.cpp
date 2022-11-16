//
// Created by Отинов Илья on 16.11.2022.
//
#include "iostream"

using namespace std;

class Publication {
protected:
    string title;
    float coast;

public:
    Publication(): coast(0.0) {}

    Publication(char* str, float coast): title(str), coast(coast) {}

    virtual void getData() {
        cout << "Print title of book: ";
        cin.ignore();
        getline(cin, title);
        cout << "Print coast of book: ";
        cin >> coast;
    }

    virtual void putData() const {
        cout << "Title: " << title.c_str() << endl;
        cout << "Coast: " << coast << endl;
    }
};

class PublicationWithDate : public Publication {
protected:
    string date{};

    PublicationWithDate(): Publication() {}

    PublicationWithDate(char* tit, float coast, char* dat) : Publication(tit, coast), date(dat) {}

    void getData() {
        Publication::getData();
        cout << "Print date of publication: ";
        cin.ignore();
        getline(cin, date);
    }

    void putData() const {
        Publication::putData();
        cout << "publication date: " << date << endl;
    }
};

class Sales {
protected:
    static const int COUNT_OF_SALES = 3;
    enum monthOfSales {
        THIS_MONTH, ONE_MONTH_AGO, TWO_MONTH_AGO
    };
    float salesForLastThreeMonths[COUNT_OF_SALES]{};
public:
    void getData() {
        cout << "Print info about sales:" << endl
        << "Two month ago: ";
        cin >> salesForLastThreeMonths[monthOfSales::TWO_MONTH_AGO];

        cout << "One month ago: ";
        cin >> salesForLastThreeMonths[monthOfSales::ONE_MONTH_AGO];

        cout << "This month: ";
        cin >> salesForLastThreeMonths[monthOfSales::THIS_MONTH];
    }

    void putData() const {
        cout << "Info about sales: " << endl
        << "This month: " << salesForLastThreeMonths[monthOfSales::THIS_MONTH] << endl
        << "Month ago: " << salesForLastThreeMonths[monthOfSales::ONE_MONTH_AGO] << endl
        << "Two month ago: " << salesForLastThreeMonths[monthOfSales::TWO_MONTH_AGO] << endl;
    }
};

class Book : public PublicationWithDate, public Sales{
private:
    int page_count;
public:
    Book(): page_count(0) {}

    Book(char* str, float c, int count, char* dat): page_count(count), PublicationWithDate(str, c, dat) {}

    void getData() {
        PublicationWithDate::getData();
        cout << "Print page count: ";
        cin >> page_count;
        Sales::getData();
    }

    void putData() const {
        PublicationWithDate::putData();
        cout << "Page count: " << page_count << endl;
        Sales::putData();
    }
};

class Type : public PublicationWithDate, public Sales{
private:
    float time_recording;
public:
    Type() : PublicationWithDate(), time_recording(0.0) {}

    Type(char* str, float c, float t, char* dat): PublicationWithDate(str, c, dat), time_recording(t) {}

    void getData() {
        PublicationWithDate::getData();
        cout << "Print time recording: ";
        cin >> time_recording;
        Sales::getData();
    }

    void putData() const {
        PublicationWithDate::putData();
        cout << "Time recording: " << time_recording << endl;
        Sales::putData();
    }
};

void testGetDataFromPublication();

void testGetDataFromType();

void testGetDataFromBook();

void testGetDataInWhile();

int main() {
//    testGetDataFromPublication();
//    testGetDataFromType();
//    testGetDataFromBook();
    testGetDataInWhile();
}

void testGetDataInWhile() {
    char stop;
    Publication* publicationArray[100];
    char bookOrTape;
    int counter = 0;

    do {
        cout << "Fill info about book or tape? [b/t] ";
        cin >> bookOrTape;

        if (bookOrTape == 'b') {
            publicationArray[counter] = new Book();
        } else if (bookOrTape == 't') {
            publicationArray[counter] = new Type();
        } else {
            cout << R"(Control character incorrect, please use "b" or "t")" << endl;
            continue;
        }

        publicationArray[counter]->getData();

        cout << "Continue? [y/n] ";
        cin >> stop;
        counter++;
    } while (stop == 'y');

    for (int i = 0; i < counter; i++) {
        publicationArray[i]->putData();
    }
}

void testGetDataFromPublication() {
    Publication publication;

    publication.getData();
    publication.putData();

    cout << endl << "Get data from publication work fine!" << endl << endl;
}

void testGetDataFromType() {
    Type type;
    type.getData();
    type.putData();

    cout << endl << "Get data from type work fine!" << endl << endl;
}

void testGetDataFromBook() {
    Book book;
    book.getData();
    book.putData();

    cout << endl << "Get data from book work fine!" << endl << endl;
}