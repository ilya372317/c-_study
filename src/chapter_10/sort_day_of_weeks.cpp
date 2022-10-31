//
//Author Ilya Otinov
//

#include "iostream"
#include "cstring"

using namespace std;

const int DAY_OF_WEEK_COUNT = 7;

void order_string(char**, char**);

void ssort(char **, int);

int main() {
    char mondey[] = "Mondey";
    char tuasday[] = "Tuasday";
    char wensday[] = "Wensday";
    char thursday[] = "Thursday";
    char friday[] = "Friday";
    char suturday[] = "Suturday";
    char sunday[] = "Sunday";

    char *days_of_week[DAY_OF_WEEK_COUNT] = {tuasday, mondey, wensday, thursday, friday, suturday, sunday};

    ssort(days_of_week, DAY_OF_WEEK_COUNT);

    for (int i = 0; i < DAY_OF_WEEK_COUNT; i++) {
        cout << *(days_of_week + i) << endl;
    }
}

void order_string(char **first, char **second) {
    bool first_more_then_second = strcmp(*first, *second) == 1;

    if (first_more_then_second) {
        char *tempStr = *first;
        *first = *second;
        *second = tempStr;
    }
}

void ssort(char **first, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int k = i + 1; k < length; k++) {
            order_string(first + i, first + k);
        }
    }
}
