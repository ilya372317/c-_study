// My first class writing on c++

#include <iostream>

using namespace std;

class SmallJob
{
    private:
        int somedata;
    public:
        SmallJob()
        {

        }
        void setData(int d)
        {
            somedata = d;
        }
        int getData()
        {
            return somedata;
        }
};

int main()
{
    SmallJob job;
    job.setData(1);

    cout << job.getData() << endl;
}
