//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;

const int DAYS = 7;

int main() {
    char mondey[] = "Mondey";
    char tuasday[] = "Tuasday";
    char wensday[] = "Wensday";
    char fourthday[] = "Fourthday";
    char friday[] = "Friday";
    char suturday[] = "Sutarday";
    char sunday[] = "Sunday";
    char* days[DAYS] = {
        mondey,
	tuasday,
	wensday,
        fourthday,
	friday,
	suturday,
	sunday
    };

    for (int i = 0; i < DAYS; i++) {
        cout << days[i] << endl;
    }
}
