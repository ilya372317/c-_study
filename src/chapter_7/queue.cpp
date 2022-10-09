//
// Created by ilya on 09.10.22.
//

#include "iostream"

using namespace std;

class QueueIterator;

class Queue {
private:
    static const int MAX = 100;
    int que[MAX]{};
    int first;
    int last;
public:
    Queue(): first(0), last(0) {}

    void put(int var) {
        if (last > MAX - 1) {
            last = 0;
        }

        que[last++] = var;
    }

    int get() {
        if (first > MAX - 1) {
            first = 0;
        }

        return que[first++];
    }

    [[nodiscard]] bool hasNext() const {
        if (first >= last) {
            return false;
        }

        return true;
    }

    void reset() {
        for (int q: que) {
            q = 0;
        }
        first = 0;
        last = 0;
    }

    int next() {
        return get();
    }
};

int main() {
    Queue q;

    for (int i = 0; i < 200; i++) {
        q.put(i);
    }

    while (q.hasNext()) {
        cout << q.get() << endl;
    }
}