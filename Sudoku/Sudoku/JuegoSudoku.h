#pragma once
#include <iostream>
#include "Matriz.h"

template <class T>
class JuegoSudoku {
public:
    JuegoSudoku();
    bool buscarFilColVacia(T**, T*, T*, T);
    bool numRepetido(T**, T, T, T, T);
    bool numRepFila(T**, T, T, T);
    bool numRepColumna(T**, T, T, T);
    bool numRepSeccion(T**, T, T, T, T);
    bool resolverSudoku(T**, T, T, T, T);
private:
    Matriz<int> matrix;
};

template <class T>
JuegoSudoku<T>::JuegoSudoku() {
}

template <class T>
bool JuegoSudoku<T>::buscarFilColVacia(T** mat, T* fil, T* col, T dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (*(*(mat + i) + j) == 0) {
                *fil = i; *col = j;
                return false;
            }
        }
    }
    return true;
}

template <class T>
bool JuegoSudoku<T>::resolverSudoku(T** mat, T fila, T columna, T dim, T num) {
    if (buscarFilColVacia(mat, &fila, &columna, dim)) {
        std::cout << "Solucion del sudoku: " << std::endl;
        matrix.imprimirMat(mat, dim);
        return true;
    }
    else {
        do {
            if (numRepetido(mat, fila, columna, num, dim)) {
                *(*(mat + fila) + columna) = num;
                if (resolverSudoku(mat, fila, columna, dim, 1))
                    return true;
                *(*(mat + fila) + columna) = 0;
            }
            num++;
        } while (num <= 9);
        return false;
    }
}

template <class T>
bool JuegoSudoku<T>::numRepetido(T** mat, T fil, T col, T num, T dim) {
    return !numRepFila(mat, fil, num, dim) && !numRepColumna(mat, col, num, dim) && !numRepSeccion(mat, fil - fil % 3, col - col % 3, num, dim);
}

template <class T>
bool JuegoSudoku<T>::numRepFila(T** mat, T fil, T num, T dim) {
    for (int j = 0; j < dim; j++)
        if (*(*(mat + fil) + j) == num)
            return true;
    return false;
}

template <class T>
bool JuegoSudoku<T>::numRepColumna(T** mat, T col, T num, T dim) {
    for (int i = 0; i < dim; i++)
        if (*(*(mat + i) + col) == num)
            return true;
    return false;
}

template <class T>
bool JuegoSudoku<T>::numRepSeccion(T** mat, T fil, T col, T num, T dim) {
    for (int i = 0; i < dim / 3; i++)
        for (int j = 0; j < dim / 3; j++)
            if (*(*(mat + i + fil) + j + col) == num)
                return true;
    return false;
}