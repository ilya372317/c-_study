// Convert time to second

#include <iostream>

using namespace std;

struct Time 
{
    int hour;
    int minute;
    int second;
};

long hms_to_sec(const Time& time);

int main()
{
    char stop = 'y';

    while (stop != 'n') {
        Time time;
        cout << "Print hour: ";
        cin >> time.hour;

        cout << "Print minutes: ";
        cin >> time.minute;

        cout << "Print seconds: ";
        cin >> time.second;

        int result = hms_to_sec(time);

        cout << "Time in seconds: " << result << endl
        << endl << "Continue? [y/n]" << endl;

        cin >> stop;
        cout << endl;
}

    return 0;
}

inline long hms_to_sec(const Time& time)
{
    return (time.second) + (time.minute * 60) + (time.hour * 60 * 60);
}
