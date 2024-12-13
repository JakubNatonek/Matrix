#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void matrix::allocateMemory(int n) {
    data = new int*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

void matrix::deallocateMemory() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

matrix::matrix() : data(nullptr), size(0) {}

matrix::matrix(int n) : size(n) {
    allocateMemory(n);
}

matrix::matrix(int n, int* t) : size(n) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

matrix::matrix(const matrix& m) : size(m.size) {
    allocateMemory(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

matrix::~matrix() {
    if (data) {
        deallocateMemory();
    }
}

matrix& matrix::allocate(int n) {
    if (data) {
        if (size != n) {
            deallocateMemory();
            size = n;
            allocateMemory(n);
        }
    } else {
        size = n;
        allocateMemory(n);
    }
    return *this;
}

matrix& matrix::insert(int x, int y, int value) {
    data[x][y] = value;
    return *this;
}

int matrix::show(int x, int y) const {
    return data[x][y];
}

matrix& matrix::transpose() {
    matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[j][i];
        }
    }
    *this = result;
    return *this;
}

matrix& matrix::randomize() {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = rand() % 100;
        }
    }
    return *this;
}

matrix& matrix::randomize(int x) {
    srand(time(0));
    for (int i = 0; i < x; ++i) {
        int row = rand() % size;
        int col = rand() % size;
        data[row][col] = rand() % 10;
    }
    return *this;
}

matrix& matrix::diagonal(int* t) {
    for (int i = 0; i < size; ++i) {
        data[i][i] = t[i];
    }
    return *this;
}

matrix& matrix::diagonal_k(int k, int* t) {
    if (k > 0) {
        for (int i = 0; i < size - k; ++i) {
            data[i][i + k] = t[i];
        }
    } else {
        for (int i = 0; i < size + k; ++i) {
            data[i - k][i] = t[i];
        }
    }
    return *this;
}

matrix& matrix::column(int x, int* t) {
    for (int i = 0; i < size; ++i) {
        data[i][x] = t[i];
    }
    return *this;
}

matrix& matrix::row(int y, int* t) {
    for (int i = 0; i < size; ++i) {
        data[y][i] = t[i];
    }
    return *this;
}

matrix& matrix::diagonal() {
    for (int i = 0; i < size; ++i) {
        data[i][i] = 1;
    }
    return *this;
}

matrix& matrix::sub_diagonal() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            data[i][j] = 1;
        }
    }
    return *this;
}

matrix& matrix::super_diagonal() {
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            data[i][j] = 1;
        }
    }
    return *this;
}

matrix& matrix::checkerboard() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = (i + j) % 2;
        }
    }
    return *this;
}

matrix& matrix::operator+(const matrix& m) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += m.data[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator*(const matrix& m) {
    matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

matrix& matrix::operator+(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
}

matrix& matrix::operator*(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] *= a;
        }
    }
    return *this;
}

matrix& matrix::operator-(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= a;
        }
    }
    return *this;
}

matrix operator+(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a + m.data[i][j];
        }
    }
    return result;
}

matrix operator*(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a * m.data[i][j];
        }
    }
    return result;
}

matrix operator-(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a - m.data[i][j];
        }
    }
    return result;
}

matrix& matrix::operator++(int) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator--(int) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            --data[i][j];
        }
    }
    return *this;
}

matrix& matrix::operator+=(int a) {
    *this = *this + a;
    return *this;
}

matrix& matrix::operator-=(int a) {
    *this = *this - a;
    return *this;
}

matrix& matrix::operator*=(int a) {
    *this = *this * a;
    return *this;
}

matrix& matrix::operator()(double) {
    return *this;
}

std::ostream& operator<<(std::ostream& o, const matrix& m) {
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            o << m.data[i][j] << ' ';
        }
        o << std::endl;
    }
    return o;
}

bool matrix::operator==(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] != m.data[i][j]) return false;
        }
    }
    return true;
}

bool matrix::operator>(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] <= m.data[i][j]) return false;
        }
    }
    return true;
}

bool matrix::operator<(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] >= m.data[i][j]) return false;
        }
    }
    return true;
}

