#pragma once
#include <iostream>

class matrix {
    private:
        int** data;
        int size;
        
        void allocateMemory(int n);
        void deallocateMemory();
    public:
        matrix();
        matrix(int n);
        matrix(int n, int* t);
        matrix(const matrix& m);
        ~matrix();

        matrix& allocate(int n);
        matrix& insert(int x, int y, int value);
        int show(int x, int y) const;
        matrix& transpose();
        matrix& randomize();
        matrix& randomize(int x);
        matrix& diagonal(int* t);
        matrix& diagonal_k(int k, int* t);
        matrix& column(int x, int* t);
        matrix& row(int y, int* t);
        matrix& diagonal();
        matrix& sub_diagonal();
        matrix& super_diagonal();
        matrix& checkerboard();

        matrix& operator+(const matrix& m);
        matrix& operator*(const matrix& m);
        matrix& operator+(int a);
        matrix& operator*(int a);
        matrix& operator-(int a);
        friend matrix operator+(int a, const matrix& m);
        friend matrix operator*(int a, const matrix& m);
        friend matrix operator-(int a, const matrix& m);
        matrix& operator++(int);
        matrix& operator--(int);
        matrix& operator+=(int a);
        matrix& operator-=(int a);
        matrix& operator*=(int a);
        matrix& operator()(double);
        friend std::ostream& operator<<(std::ostream& o, const matrix& m);
        bool operator==(const matrix& m) const;
        bool operator>(const matrix& m) const;
        bool operator<(const matrix& m) const;
};
