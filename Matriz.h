#pragma once

#include <iostream>
#include "Archivo.h"

template<class T>
class Matriz
{
public:
	Matriz() {};
	T** separarMemoria(int);
	void encerarMatriz(T** , int);
	void imprimirMatriz(T** , int);
private:
	T** matrizR;
	int dimen;
};

template<class T>
T** Matriz<T>::separarMemoria(int dim)
{
	T** matAux, j;
	matAux = (T**)malloc(dim * sizeof(T*));
	matrizR = (T**)malloc(dim * sizeof(T*));
	for (j = 0; j < dim; j++) {
		*(matAux + j) = (T*)malloc(dim * sizeof(T));
		*(matrizR + j) = (T*)malloc(dim * sizeof(T));
	}
	return matAux;
}

template<class T>
void Matriz<T>::encerarMatriz(T** matriz, int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			(*(*(matriz + i) + j)) = 0;
			(*(*(matrizR + i) + j)) = 0;
		}
	}

}

template<class T>
void Matriz<T>::imprimirMatriz(T** matriz, int dim)
{
	for (int i = 0; i < dim; i++) 
		for (int j = 0; j < dim; j++)
			std::cout << " " << (*(*(matriz + i) + j)) << " ";
		std::cout << std::endl;
}
