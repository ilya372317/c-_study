//
// Created by ilya on 30.09.22.
//
// Small class

#include <iostream>

using namespace std;

class SmallJob {
private:
    int data;
public:
    void setData(int d)
    {
        this->data = d;
    }
    void showData()
    {
        cout << "Data is: " << this->data;
    }
};

int main()
{
    SmallJob job;

    job.setData(101);
    job.showData();
}
