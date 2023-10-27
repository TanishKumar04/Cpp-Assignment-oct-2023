#include <iostream>
#include <vector>

class Matrix {

public:

    int rows, cols;
    std::vector<std::vector<int> > data;

    Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

    void set(int row, int col, int value) {
        data[row - 1][col - 1] = value;
    }

    int get(int row, int col) const {
        return data[row - 1][col - 1];
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
};

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        throw std::runtime_error("Matrix dimensions must agree.");
    }

    Matrix result(m1.rows, m1.cols);

    for (int i = 0; i < m1.rows; ++i) {
        for (int j = 0; j < m1.cols; ++j) {
            result.data[i][j] = m1.data[i][j] + m2.data[i][j];
        }
    }

    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        throw std::runtime_error("Matrix dimensions must agree.");
    }

    Matrix result(m1.rows, m1.cols);

    for (int i = 0; i < m1.rows; ++i) {
        for (int j = 0; j < m1.cols; ++j) {
            result.data[i][j] = m1.data[i][j] - m2.data[i][j];
        }
    }

    return result;
}

void print(const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            std::cout << m.get(i + 1, j + 1) << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix m1(2, 2);
    m1.set(1, 1, 2);
    m1.set(1, 2, 3);
    m1.set(2, 1, 4);
    m1.set(2, 2, 5);

    Matrix m2(2, 2);
    m2.set(1, 1, 6);
    m2.set(1, 2, 7);
    m2.set(2, 1, 8);
    m2.set(2, 2, 9);

    std::cout << "Matrix 1: " << std::endl;
    print(m1);

    std::cout << "Matrix 2: " << std::endl;
    print(m2);

    Matrix sum = m1 + m2;
    std::cout << "Sum: " << std::endl;
    print(sum);

    Matrix difference = m1 - m2;
    std::cout << "Difference: " << std::endl;
    print(difference);

    return 0;
}