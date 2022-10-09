// my first structure; 
#include <iostream>

using namespace std;

struct part
{
    int modelNumber;  
    int partNumber;
    float cost;
};



int main(int argv, char *argc[])
{
    part part;
    part.partNumber = 1;
    part.modelNumber = 2;
    part.cost = 3.33;

    cout << "Part number: " << part.partNumber << endl
    << "Model number: " << part.modelNumber << endl
    << "Coast: " << part.cost << endl;
}
