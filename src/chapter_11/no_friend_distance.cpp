//
//Author Ilya Otinov
//

#include "iostream"
#include <gtest/gtest.h>

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

    void showdist() const {
	cout << feet << "\'-" << inches << '\"';
    }

    friend Distance operator+ (Distance, Distance);

    friend Distance operator* (Distance, Distance);

    friend float square(Distance);

    int getFeet() const;

    float getInches() const;
};

Distance operator+(Distance d1, Distance d2) {
    int f = d1.feet + d2.feet;
    float i = d1.inches + d2.inches;
    if (i > 12.0) {
	i -= 12.0;
	f++;
    }

    return {f,i};
}

Distance operator*(Distance d1, Distance d2) {
    int f = d1.feet * d2.feet;
    float i = d1.inches * d2.inches;

    while (i > 12.0) {
        i -= 12.0;
        f++;
    }

    return {f, i};
}

int Distance::getFeet() const {
    return feet;
}

float Distance::getInches() const {
    return inches;
}

float square(Distance d) {
    float fltfeet = d.feet + d.inches/12;
    float feetsqrd = fltfeet * fltfeet;
    return feetsqrd;
}

TEST(DistanceTest, multiply) {
    Distance d1 = 1.1 * 2.2;

    EXPECT_EQ(2, d1.getFeet());
    EXPECT_FLOAT_EQ(5.04, d1.getInches());
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

