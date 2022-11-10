//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

class Distance {
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0f) {}

    Distance(float fltfeet) {
	feet = static_cast<int>(fltfeet);
	inches = 12*(fltfeet-feet);
    }

    Distance(int ft, float inc): feet(ft), inches(inc) {}

    void showdist() {
	cout << feet << "\'-" << inches << '\"';
    }

    friend Distance operator+ (Distance, Distance);

    friend float square(Distance);
};

Distance operator+(Distance d1, Distance d2) {
    int f = d1.feet + d2.feet;
    float i = d1.inches + d2.inches;
    if (i > 12.0) {
	i -= 12.0;
	f++;
    }

    return Distance(f,i);
}

float square(Distance d) {
    float fltfeet = d.feet + d.inches/12;
    float feetsqrd = fltfeet * fltfeet;
    return feetsqrd;
}

int main() {
    Distance d1(2.5f);
    Distance d2(1.25f);
    Distance d3;

    cout << endl << "d1 = ";
    d1.showdist();
    cout << endl << "d2 = ";
    d2.showdist();

    d3 = d1 + 10.0f;

    cout << endl << "d3 = ";
    d3.showdist();

    d3 = 10.1f + d1;

    cout << endl << "d3 = ";
    d3.showdist();

    cout << endl << "d3 square = " << square(d3);
}

