#include<iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    int getValue(int row, int col) const {
        return data[row - 1][col - 1];
    }

    void setValue(int row, int col, int value) {
        data[row - 1][col - 1] = value;
    }

    Matrix operator*(const Matrix& m) const {
        if (cols != m.rows) {
            throw std::runtime_error("Matrices with incompatible dimensions cannot be multiplied.");
        }

        Matrix result(rows, m.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.setValue(i + 1, j + 1, 0);
                for (int k = 0; k < cols; k++) {
                    result.setValue(i + 1, j + 1, result.getValue(i + 1, j + 1) + data[i][k - 1] * m.data[k - 1][j - 1]);
                }
            }
        }

        return result;
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.setValue(j + 1, i + 1, data[i][j]);
            }
        }

        return transposed;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m);
};

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main() {
    Matrix m1(2, 3);
    m1.setValue(1, 1, 1);
    m1.setValue(1, 2, 2);
    m1.setValue(1, 3, 3);
    m1.setValue(2, 1, 4);
    m1.setValue(2, 2, 5);
    m1.setValue(2, 3, 6);

    Matrix m2(3, 2);
    m2.setValue(1, 1, 7);
    m2.setValue(1, 2, 8);
    m2.setValue(2, 1, 9);
    m2.setValue(2, 2, 10);
    m2.setValue(3, 1, 11);
    m2.setValue(3, 2, 12);

    cout << "Matrix 1: " << endl << m1 << endl;
    cout << "Matrix 2: " << endl << m2 << endl;

    Matrix product = m1 * m2;
    cout << "Product: " << endl << product << endl;

    Matrix transposed = m1.transpose();
    cout << "Transposed: " << endl << transposed << endl;

    return 0;
}