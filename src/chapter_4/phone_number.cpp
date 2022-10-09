// phone number structure

#include <iostream>

using namespace std;

struct Phone 
{
    int countryCode;
    int cityCode;
    int stantionCode;
    int userCode;
};

int main()
{
    Phone ilyaPhone = {7};
    int bullshitChar;

    cout << "Print city, stantion and user code of phone number: " << endl;

    cin >> ilyaPhone.cityCode >> bullshitChar >> ilyaPhone.stantionCode >> bullshitChar >> ilyaPhone.userCode;

    cout << "Your phone is: +" << ilyaPhone.countryCode << "(" << ilyaPhone.cityCode << ") "
    << ilyaPhone.stantionCode << "-" << ilyaPhone.userCode << endl;
}