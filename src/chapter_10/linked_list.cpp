//
// Author Ilya Otinov
//

#include "iostream"

using namespace std;

struct link {
    int data;
    link* next;
};

class LinkList {
private:
    link* first;
public:
    LinkList() {
	first = nullptr;
    }
    

    ~LinkList() {
        link* current = first;
        while (current) {
	    link* next = current->next;
	    cout << "delete item {" << current->data << "}" << endl;
	    delete current;
	    current = next;
        }
    }

    void addItem(int d);
    void display();
};


void LinkList::addItem(int d) {
    link* newLink = new link;
    newLink->data = d;
    newLink->next = nullptr;

    if (!first) {
        first = newLink;
    } else {
        link* current = first;
        while (current) {
            if (!current->next) {
                current->next = newLink;
                break;
            }
            current = current->next;
        }
    }
}

void LinkList::display() {
    link* current = first;
    while (current) {
	cout << current->data << endl;
	current = current->next;
    }
}

int main() {
    LinkList li;

    li.addItem(1);
    li.addItem(2);
    li.addItem(3);
    li.addItem(4);

    li.display();

    return 0;
}
