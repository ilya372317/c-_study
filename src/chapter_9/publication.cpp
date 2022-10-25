//
// Created by ilya on 24.10.22.
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

    void getData() {
        cout << "Print title of book: ";
        cin.ignore();
        getline(cin, title);
        cout << "Print coast of book: ";
        cin >> coast;
    }

    void putData() const {
        cout << "Title: " << title.c_str() << endl;
        cout << "Coast: " << coast << endl;
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

class Book : public Publication, public Sales{
private:
    int page_count;
public:
    Book(): page_count(0) {}

    Book(char* str, float c, int count): page_count(count), Publication(str, c) {}

    void getData() {
        Publication::getData();
        cout << "Print page count: ";
        cin >> page_count;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Page count: " << page_count << endl;
        Sales::putData();
    }
};

class Type : public Publication, public Sales{
private:
    float time_recording;
public:
    Type() : Publication(), time_recording(0.0) {}

    Type(char* str, float c, float t): Publication(str, c), time_recording(t) {}

    void getData() {
        Publication::getData();
        cout << "Print time recording: ";
        cin >> time_recording;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "Time recording: " << time_recording << endl;
        Sales::putData();
    }
};

void testGetDataFromPublication();

void testGetDataFromType();

void testGetDataFromBook();

int main() {
    testGetDataFromPublication();
    testGetDataFromType();
    testGetDataFromBook();
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