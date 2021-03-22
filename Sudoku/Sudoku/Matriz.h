#pragma once
#include <iostream>

template <class T>
class Matriz {
public:
	Matriz() {}
	T** inicializarMatriz(T** mat, T dim);
	void imprimirMat(T** mat, T dim);

};

template <class T>
T** Matriz<T>::inicializarMatriz(T** mat, T dim)
{
	mat = (int**)malloc(dim * sizeof(int*));
	for (int j = 0; j < dim; j++) {
		*(mat + j) = (int*)malloc(dim * sizeof(int));
	}
	int sudoku[9][9] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
				 { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
				 { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
				 { 8, 0, 0, 0, 6, 0, 0, 1, 3 },
				 { 4, 0, 0, 8, 0, 3, 0, 3, 1 },
				 { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
				 { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
				 { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
				 { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(mat + i) + j) = sudoku[i][j];
		}
	}
	return mat;
}

template <class T>
void Matriz<T>::imprimirMat(T** mat, T dim)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			std::cout << " " << *(*(mat + i) + j);
		}
		std::cout << std::endl;
	}
}
