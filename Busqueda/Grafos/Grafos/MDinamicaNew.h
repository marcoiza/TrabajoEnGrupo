#ifndef MDINAMICANEW_H_INCLUDED
#define MDINAMICANEW_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

class MDinamicaNew {
	public:
		int** reservar_m(int** mat, int dim);
		void encerar(int** mat, int dim);
		void liberar(int** mat, int dim);
};


void MDinamicaNew::encerar(int** mat, int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
}

int** MDinamicaNew::reservar_m(int** mat, int dim) {
	mat = new int* [dim];
	for (int i = 0; i < dim; i++) {
		*(mat + i) = new int[dim];
	}
	return mat;
}

void MDinamicaNew::liberar(int** mat, int dim) {
	for (int i = 0; i < dim; i++) {
		delete[]mat[i];
	}
	delete[]mat;
}
#endif