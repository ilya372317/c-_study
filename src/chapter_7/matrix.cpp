//
// Created by ilya on 09.10.22.
//

#include "iostream"

using namespace std;

class Matrix {
private:
    static const int MAX_FIRST = 10;
    static const int MAX_SECOND = 10;
    int array[MAX_FIRST][MAX_SECOND];
    int row{};
    int col{};
public:
    Matrix(): row(MAX_FIRST - 1), col(MAX_SECOND - 1) {}

    Matrix(int firstSize, int secondSize) {
        row = firstSize;
        col = secondSize;
        if (row >= MAX_FIRST) {
            row = 9;
        }

        if (col >= MAX_SECOND) {
            col = 9;
        }
    }

    void putel(int firstIndex, int secondIndex, int var) {
        if (firstIndex >= row || secondIndex >= col) {
            cout << "Matrix not support number higher then 10" << endl;
            return;
        }

        array[firstIndex][secondIndex] = var;
    }

    int getel(int firstIndex, int secondIndex) {
        if (firstIndex >= row || secondIndex >= col) {
            cout << "Matrix not support number higher in row then: " << row << " and in column then: " << col << endl;
            return -1;
        }

        return array[firstIndex][secondIndex];
    }
};

int main() {
    Matrix matrix(5, 5);

    matrix.putel(1,1,1);
    cout << matrix.getel(1,1) << endl;

    matrix.putel(1,6,2);
    cout << matrix.getel(1,6) << endl;
}
