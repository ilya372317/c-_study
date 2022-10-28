//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0f) {}

    Distance(int f, float i) : feet(f), inches(i) {}

    void getDist() {
        cout << endl << "Print feet: ";
	cin >> feet;
	cout << "Print inches: ";
	cin >> inches;
    }

    void showDist() const {
	cout << feet << "\'-" << inches << '\"';
    }
};

int main() {
    Distance dist;
    dist.getDist();
    dist.showDist();

    Distance* distPointer;
    distPointer = new Distance;
    distPointer->getDist();
    distPointer->showDist();

    Distance& distance = *(new Distance);

    distance.getDist();
    distance.showDist();
    cout << endl;


    return 0;
}
