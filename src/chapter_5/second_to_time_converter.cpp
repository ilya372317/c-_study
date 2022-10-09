//
// Created by ilya on 29.09.22.
//

#include <iostream>

using namespace std;

int main()
{
    unsigned long seconds;

    cout << "Print seconds to convert it to time: ";
    cin >> seconds;

    unsigned long hour, minute, second, remainingSeconds;

    hour = seconds / 60 / 60;
    remainingSeconds = seconds - (hour * 60 * 60);
    minute = remainingSeconds / 60;
    second = remainingSeconds - (minute * 60);

    cout << "Hours: " << hour << endl
    << "Minute: " << minute << endl
    << "Seconds: " << second << endl;

    return 0;
}
