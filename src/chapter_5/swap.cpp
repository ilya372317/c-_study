// swap arguments

#include <iostream>

using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
};

void swap(Time&, Time&);
Time fillTime();

int main()
{
    cout << "Fill first time: " << endl;
    Time first = fillTime();
    cout << "Fill second time: " << endl;
    Time second = fillTime();

    swap(first, second);

    cout << "Time after swap: " << endl 
    << "Firts time: h=" << first.hour << " m=" << first.minute << " s=" << first.second << endl
    << "Second time: h=" << second.hour << " m=" << second.minute << " s=" << second.second << endl;
}

void swap(Time& first, Time& second)
{
    Time dubleSecond = second;
    second = first;
    first = dubleSecond;
}

Time fillTime()
{
    Time time;
    cout << "Print hour: ";
    cin >> time.hour;

    cout << "Print minute: ";
    cin >> time.minute;

    cout << "Print second: ";
    cin >> time.second;

    return time;
}