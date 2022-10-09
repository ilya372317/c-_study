// Part class

#include <iostream>

using namespace std;

class Part 
{
    private:
        int modelNumber;
        int partNumber;  
        float coast;

    public:
        void setpart(int modelNumber, int partNumber, float coast)
        {
            this->modelNumber = modelNumber;
            this->partNumber = partNumber;
            this->coast = coast;
        }
        void showpart()
        {
            cout << "Model number: " << this->modelNumber << endl
            << "Part number: " << this->partNumber << endl
            << "Coast: " << this->coast << endl;
        }
};

int main()
{
    Part p1, p2;
    p1.setpart(3001, 3000, 5000.12f);
    p2.setpart(2002, 2000, 200.4f);

    cout << "First part: " << endl;
    p1.showpart();

    cout << "Second part: " << endl;
    p2.showpart();
}