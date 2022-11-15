//
//Author Ilya Otinov
//

#include "iostream"

using namespace std;

class gamma {
private:
    static int total;
    int id;
public:
    gamma() {
	total++;
	id = total;
    }

    ~gamma() {
	total--;
	cout << "Deletign ID: " << id << endl;
    }

    static void showtotal() {
        cout << "Total object count: " << total << endl;
    }

    void showid() const {
	cout << "object ID: " << id << endl;
    }
};

int gamma::total = 0;

int main() {
    gamma g1;
    gamma::showtotal();

    gamma* g2Ptr =  new gamma();

    gamma::showtotal();
    g2Ptr->showid();
    delete g2Ptr;
}
