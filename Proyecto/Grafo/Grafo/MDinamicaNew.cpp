#include "MDinamicaNew.h"

void MDinamicaNew::encerar(int** mat, int dim) 
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
}

int** MDinamicaNew::reservarM(int** mat, int dim) 
{
	mat = new int* [dim];
	for (int i = 0; i < dim; i++) {
		*(mat + i) = new int[dim];
	}
	return mat;
}

void MDinamicaNew::liberar(int** mat, int dim) 
{
	for (int i = 0; i < dim; i++) {
		delete[]mat[i];
	}
	delete[]mat;
}

