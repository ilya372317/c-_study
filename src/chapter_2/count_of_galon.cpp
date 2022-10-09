// Count of valume
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	const float CUBE_METTER = 7.481;
	
	int countOfGalon;

	cout << "Print count of galon" << endl;

	cin >> countOfGalon;

	float volume = countOfGalon * CUBE_METTER;

	cout << "cube meter equals: " << volume << endl;

	return 0;
}
