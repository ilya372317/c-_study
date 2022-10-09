// Compare distance

#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inches;
};

Distance compareDistance(Distance first, Distance second);

int main()
{
    Distance a = {1, 1.2f};
    Distance b;

    cout << "Print feet: ";
    cin >> b.feet;
    cout << "Print inches: ";
    cin >> b.inches;

    Distance result = compareDistance(a, b);

    if (result.feet == 0 && result.inches == 0) {
        cout << "Distance is equals" << endl;
        exit(0);
    }

    cout << "Max distance equals: " << result.feet << "-" << result.inches << endl;
}

Distance compareDistance(Distance first, Distance second)
{
    if (first.feet > second.feet) {
        return first;
    } else if (first.feet < second.feet) {
        return second;
    } else {
        if (first.inches > second.inches) {
            return first;
        } else if (first.inches < second.inches) {
            return second;
        } else {
            return {0,0};
        }
    }
}
