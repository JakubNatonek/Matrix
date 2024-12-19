#pragma once
#include <iostream>

/**
 * \class matrix
 * \brief Klasa reprezentująca macierz.
 */
class matrix {
    private:
        int** data;  ///< Wskaźnik na dane macierzy.
        int size; ///< Rozmiar macierzy.

        /**
        * \brief Alokuje pamięć dla macierzy o rozmiarze n.
        * \param n Rozmiar macierzy.
        */
        void allocateMemory(int n);
    
        /**
         * \brief Zwalnia pamięć zajmowaną przez macierz.
         */
        void deallocateMemory();
    public:
    
        /**
         * \brief Konstruktor domyślny.
         */
        matrix();
    
        /**
         * \brief Konstruktor tworzący macierz o rozmiarze n.
         * \param n Rozmiar macierzy.
         */
        matrix(int n);
    
        /**
         * \brief Konstruktor tworzący macierz o rozmiarze n i inicjalizujący ją wartościami z tablicy t.
         * \param n Rozmiar macierzy.
         * \param t Tablica wartości do inicjalizacji macierzy.
         */
        matrix(int n, int* t);

        /**
         * \brief Konstruktor kopiujący.
         * \param m Obiekt macierzy do skopiowania.
         */
        matrix(const matrix& m);
    
        /**
         * \brief Destruktor.
         */
        ~matrix();

        /**
         * \brief Alokuje pamięć dla macierzy o rozmiarze n.
         * \param n Rozmiar macierzy.
         * \return Referencja do obiektu macierzy.
         */
        matrix& allocate(int n);

        /**
         * \brief Wstawia wartość do macierzy na pozycję (x, y).
         * \param x Wiersz.
         * \param y Kolumna.
         * \param value Wartość do wstawienia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& insert(int x, int y, int value);

        /**
         * \brief Zwraca wartość z macierzy na pozycji (x, y).
         * \param x Wiersz.
         * \param y Kolumna.
         * \return Wartość z macierzy.
         */
        int show(int x, int y) const;

        /**
         * \brief Transponuje macierz.
         * \return Referencja do obiektu macierzy.
         */
        matrix& transpose();

        /**
         * \brief Losowo wypełnia macierz wartościami od 0 do 9.
         * \return Referencja do obiektu macierzy.
         */
        matrix& randomize();

        /**
         * \brief Losowo wypełnia x elementów macierzy wartościami od 0 do 9.
         * \param x Liczba elementów do wypełnienia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& randomize(int x);

        /**
         * \brief Ustawia wartości na przekątnej macierzy.
         * \param t Tablica wartości do ustawienia na przekątnej.
         * \return Referencja do obiektu macierzy.
         */
        matrix& diagonal(int* t);

        /**
         * \brief Ustawia wartości na k-tej przekątnej macierzy.
         * \param k Numer przekątnej.
         * \param t Tablica wartości do ustawienia na przekątnej.
         * \return Referencja do obiektu macierzy.
         */
        matrix& diagonal_k(int k, int* t);

        /**
         * \brief Ustawia wartości w kolumnie x.
         * \param x Numer kolumny.
         * \param t Tablica wartości do ustawienia w kolumnie.
         * \return Referencja do obiektu macierzy.
         */
        matrix& column(int x, int* t);

        /**
         * \brief Ustawia wartości w wierszu y.
         * \param y Numer wiersza.
         * \param t Tablica wartości do ustawienia w wierszu.
         * \return Referencja do obiektu macierzy.
         */
        matrix& row(int y, int* t);
    
        /**
         * \brief Ustawia wartości na głównej przekątnej macierzy na 1.
         * \return Referencja do obiektu macierzy.
         */
        matrix& diagonal();
    
        /**
         * \brief Ustawia wartości na podprzekątnej macierzy na 1.
         * \return Referencja do obiektu macierzy.
         */
        matrix& sub_diagonal();

        /**
        * \brief Ustawia wartości na nadprzekątnej macierzy na 1.
        * \return Referencja do obiektu macierzy.
        */
        matrix& super_diagonal();

        /**
         * \brief Wypełnia macierz wzorem szachownicy.
         * \return Referencja do obiektu macierzy.
         */
        matrix& checkerboard();

    
        /**
         * \brief Operator dodawania macierzy.
         * \param m Macierz do dodania.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator+(const matrix& m);

        /**
         * \brief Operator mnożenia macierzy.
         * \param m Macierz do pomnożenia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator*(const matrix& m);

        /**
         * \brief Operator dodawania liczby do macierzy.
         * \param a Liczba do dodania.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator+(int a);

        /**
         * \brief Operator mnożenia macierzy przez liczbę.
         * \param a Liczba do pomnożenia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator*(int a);
    
        /**
         * \brief Operator odejmowania liczby od macierzy.
         * \param a Liczba do odjęcia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator-(int a);

        /**
         * \brief Operator dodawania liczby do macierzy (przyjaciel).
         * \param a Liczba do dodania.
         * \param m Macierz.
         * \return Nowa macierz będąca wynikiem dodania.
         */
        friend matrix operator+(int a, const matrix& m);

        /**
         * \brief Operator mnożenia liczby przez macierz (przyjaciel).
         * \param a Liczba do pomnożenia.
         * \param m Macierz.
         * \return Nowa macierz będąca wynikiem mnożenia.
         */
        friend matrix operator*(int a, const matrix& m);

        /**
         * \brief Operator odejmowania liczby od macierzy (przyjaciel).
         * \param a Liczba do odjęcia.
         * \param m Macierz.
         * \return Nowa macierz będąca wynikiem odejmowania.
         */
        friend matrix operator-(int a, const matrix& m);

        /**
         * \brief Operator inkrementacji macierzy.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator++(int);
    
        /**
         * \brief Operator dekrementacji macierzy.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator--(int);

        /**
         * \brief Operator dodawania liczby do macierzy.
         * \param a Liczba do dodania.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator+=(int a);

        /**
         * \brief Operator odejmowania liczby od macierzy.
         * \param a Liczba do odjęcia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator-=(int a);

        /**
         * \brief Operator mnożenia macierzy przez liczbę.
         * \param a Liczba do pomnożenia.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator*=(int a);

        /**
         * \brief Operator dodawania wartości do wszystkich elementów macierzy.
         * \param value Wartość do dodania.
         * \return Referencja do obiektu macierzy.
         */
        matrix& operator()(double);

        /**
         * \brief Operator strumieniowy do wyświetlania macierzy.
         * \param o Strumień wyjściowy.
         * \param m Macierz do wyświetlenia.
         * \return Strumień wyjściowy.
         */
        friend std::ostream& operator<<(std::ostream& o, const matrix& m);

        /**
         * \brief Operator porównania macierzy.
         * \param m Macierz do porównania.
         * \return true jeśli macierze są równe, false w przeciwnym razie.
         */
        bool operator==(const matrix& m) const;

        /**
         * \brief Operator porównania macierzy.
         * \param m Macierz do porównania.
         * \return true jeśli macierz jest większa, false w przeciwnym razie.
         */
        bool operator>(const matrix& m) const;

        /**
         * \brief Operator porównania macierzy.
         * \param m Macierz do porównania.
         * \return true jeśli macierz jest mniejsza, false w przeciwnym razie.
         */
        bool operator<(const matrix& m) const;

        /**
         * \brief Wypełnia macierz zerami.
         */
        void writeZeros();
};
