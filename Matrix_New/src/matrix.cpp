#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
* \brief Alokuje pamięć dla macierzy o rozmiarze n.
* \param n Rozmiar macierzy.
*/
void matrix::allocateMemory(int n) {
    data = new int*[n];
    for (int i = 0; i < n; ++i) {
        data[i] = new int[n]();
    }
}

/**
 * \brief Zwalnia pamięć zajmowaną przez macierz.
 */
void matrix::deallocateMemory() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

/**
 * \brief Konstruktor domyślny.
 */
matrix::matrix() : data(nullptr), size(0) {}

/**
* \brief Konstruktor tworzący macierz o rozmiarze n.
* \param n Rozmiar macierzy.
*/
matrix::matrix(int n) : size(n) {
    allocateMemory(n);
}

/**
* \brief Konstruktor tworzący macierz o rozmiarze n i inicjalizujący ją wartościami z tablicy t.
* \param n Rozmiar macierzy.
* \param t Tablica wartości do inicjalizacji macierzy.
*/
matrix::matrix(int n, int* t) : size(n) {
    allocateMemory(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i][j] = t[i * n + j];
        }
    }
}

/**
* \brief Konstruktor kopiujący.
* \param m Obiekt macierzy do skopiowania.
*/
matrix::matrix(const matrix& m) : size(m.size) {
    allocateMemory(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

/**
* \brief Destruktor.
*/
matrix::~matrix() {
    if (data) {
        deallocateMemory();
    }
}

/**
* \brief Alokuje pamięć dla macierzy o rozmiarze n.
* \param n Rozmiar macierzy.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::allocate(int n) {
    if (data != nullptr) {
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

/**
* \brief Wstawia wartość do macierzy na pozycję (x, y).
* \param x Wiersz.
* \param y Kolumna.
* \param value Wartość do wstawienia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::insert(int x, int y, int value) {
    if (x >= 0 && x < size && y >= 0 && y < size)
    {
        data[x][y] = value; 
    }
    return *this;
}

/**
* \brief Zwraca wartość z macierzy na pozycji (x, y).
* \param x Wiersz.
* \param y Kolumna.
* \return Wartość z macierzy.
*/
int matrix::show(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size)
    {
        return data[x][y];
    }
    return 0;
}

/**
* \brief Transponuje macierz.
* \return Referencja do obiektu macierzy.
*/
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

/**
* \brief Losowo wypełnia macierz wartościami od 0 do 9.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::randomize() {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = rand() % 10;
        }
    }
    return *this;
}

/**
* \brief Losowo wypełnia x elementów macierzy wartościami od 0 do 9.
* \param x Liczba elementów do wypełnienia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::randomize(int x) {
    srand(time(0));
    for (int i = 0; i < x; ++i) {
        int row = rand() % size;
        int col = rand() % size;
        data[row][col] = rand() % 10;
    }
    return *this;
}

/**
* \brief Ustawia wartości na przekątnej macierzy.
* \param t Tablica wartości do ustawienia na przekątnej.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::diagonal(int* t) {
    writeZeros();
    for (int i = 0; i < size; ++i) {
        data[i][i] = t[i];
    }
    return *this;
}

/**
* \brief Ustawia wartości na k-tej przekątnej macierzy.
* \param k Numer przekątnej.
* \param t Tablica wartości do ustawienia na przekątnej.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::diagonal_k(int k, int* t) {
    writeZeros();
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

/**
* \brief Ustawia wartości w kolumnie x.
* \param x Numer kolumny.
* \param t Tablica wartości do ustawienia w kolumnie.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::column(int x, int* t) {
    for (int i = 0; i < size; ++i) {
        data[i][x] = t[i];
    }
    return *this;
}

/**
* \brief Ustawia wartości w wierszu y.
* \param y Numer wiersza.
* \param t Tablica wartości do ustawienia w wierszu.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::row(int y, int* t) {
    for (int i = 0; i < size; ++i) {
        data[y][i] = t[i];
    }
    return *this;
}

/**
* \brief Ustawia wartości na głównej przekątnej macierzy na 1.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::diagonal() {
    writeZeros();
    for (int i = 0; i < size; ++i) {
        data[i][i] = 1;
    }
    return *this;
}

/**
* \brief Ustawia wartości na podprzekątnej macierzy na 1.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::sub_diagonal() {
    writeZeros();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= i; ++j) {
            data[i][j] = 1;
        }
    }
    return *this;
}

/**
* \brief Ustawia wartości na nadprzekątnej macierzy na 1.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::super_diagonal() {
    writeZeros();
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            data[i][j] = 1;
        }
    }
    return *this;
}

/**
* \brief Wypełnia macierz wzorem szachownicy.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::checkerboard() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = (i + j) % 2;
        }
    }
    return *this;
}

/**
* \brief Operator dodawania macierzy.
* \param m Macierz do dodania.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator+(const matrix& m) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += m.data[i][j];
        }
    }
    return *this;
}

/**
* \brief Operator mnożenia macierzy.
* \param m Macierz do pomnożenia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator*(const matrix& m) {
    if (size == m.size)
    {
        matrix result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        *this = result;
    }
    return *this;
}

/**
* \brief Operator dodawania liczby do macierzy.
* \param a Liczba do dodania.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator+(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += a;
        }
    }
    return *this;
}

/**
* \brief Operator mnożenia macierzy przez liczbę.
* \param a Liczba do pomnożenia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator*(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] *= a;
        }
    }
    return *this;
}

/**
* \brief Operator odejmowania liczby od macierzy.
* \param a Liczba do odjęcia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator-(int a) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= a;
        }
    }
    return *this;
}

/**
* \brief Operator dodawania liczby do macierzy (przyjaciel).
* \param a Liczba do dodania.
* \param m Macierz.
* \return Nowa macierz będąca wynikiem dodania.
*/
matrix operator+(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a + m.data[i][j];
        }
    }
    return result;
}

/**
* \brief Operator mnożenia liczby przez macierz (przyjaciel).
* \param a Liczba do pomnożenia.
* \param m Macierz.
* \return Nowa macierz będąca wynikiem mnożenia.
*/
matrix operator*(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a * m.data[i][j];
        }
    }
    return result;
}

/**
* \brief Operator odejmowania liczby od macierzy (przyjaciel).
* \param a Liczba do odjęcia.
* \param m Macierz.
* \return Nowa macierz będąca wynikiem odejmowania.
*/
matrix operator-(int a, const matrix& m) {
    matrix result(m.size);
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            result.data[i][j] = a - m.data[i][j];
        }
    }
    return result;
}

/**
* \brief Operator inkrementacji macierzy.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator++(int) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

/**
* \brief Operator dekrementacji macierzy.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator--(int) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            --data[i][j];
        }
    }
    return *this;
}

/**
* \brief Operator dodawania liczby do macierzy.
* \param a Liczba do dodania.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator+=(int a) {
    *this = *this + a;
    return *this;
}

/**
* \brief Operator odejmowania liczby od macierzy.
* \param a Liczba do odjęcia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator-=(int a) {
    *this = *this - a;
    return *this;
}

/**
* \brief Operator mnożenia macierzy przez liczbę.
* \param a Liczba do pomnożenia.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator*=(int a) {
    *this = *this * a;
    return *this;
}

/**
* \brief Operator dodawania wartości do wszystkich elementów macierzy.
* \param value Wartość do dodania.
* \return Referencja do obiektu macierzy.
*/
matrix& matrix::operator()(double value) {
    int intPart = static_cast<int>(value);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += intPart;
        }
    }
    return *this;
}

/**
* \brief Operator strumieniowy do wyświetlania macierzy.
* \param o Strumień wyjściowy.
* \param m Macierz do wyświetlenia.
* \return Strumień wyjściowy.
*/
std::ostream& operator<<(std::ostream& o, const matrix& m) {
    for (int i = 0; i < m.size; ++i) {
        for (int j = 0; j < m.size; ++j) {
            o << m.data[i][j] << ' ';
        }
        o << std::endl;
    }
    return o;
}

/**
* \brief Operator porównania macierzy.
* \param m Macierz do porównania.
* \return true jeśli macierze są równe, false w przeciwnym razie.
*/
bool matrix::operator==(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] != m.data[i][j]) return false;
        }
    }
    return true;
}

/**
* \brief Operator porównania macierzy.
* \param m Macierz do porównania.
* \return true jeśli macierz jest większa, false w przeciwnym razie.
*/
bool matrix::operator>(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] <= m.data[i][j]) return false;
        }
    }
    return true;
}

/**
* \brief Operator porównania macierzy.
* \param m Macierz do porównania.
* \return true jeśli macierz jest mniejsza, false w przeciwnym razie.
*/
bool matrix::operator<(const matrix& m) const {
    if (size != m.size) return false;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] >= m.data[i][j]) return false;
        }
    }
    return true;
}

/**
* \brief Wypełnia macierz zerami.
*/
void matrix::writeZeros() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0;
        }
    }
}