#pragma once

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include <time.h>
#include <string>
#include <cstdlib>
#include "Archivo.h"

using namespace std;

template<class T>
class Matriz
{
public:
	Matriz() {};
	T** segmentarMemoria(T dim);
	T** multiplicarMatriz(T** matriz, T dim, T potencia);
	void encerarMatriz(T** matriz, T dim);
	void imprimirMatriz(T** matriz, T dim);
private:
	T** matrizResult;
	T dimen;
};

template<class T>
T** Matriz<T>::segmentarMemoria(T dim)
{
	T** m, j;
	m = (T**)malloc(dim * sizeof(T*));
	matrizResult = (T**)malloc(dim * sizeof(T*));
	for (j = 0; j < dim; j++) {

		*(m + j) = (T*)malloc(dim * sizeof(T));
		*(matrizResult + j) = (T*)malloc(dim * sizeof(T));
	}
	return m;
}

template<class T>
void Matriz<T>::encerarMatriz(T** matriz, T dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			(*(*(matriz + i) + j)) = 0;
			(*(*(matrizResult + i) + j)) = 0;
		}
	}

}

template<class T>
T** Matriz<T>::multiplicarMatriz(T** matriz, T dim, T potencia)
{
	if (potencia == 1) {
		matrizResult = matriz;
	}
	else {
		while (potencia != 1) {
			for (int i = 0; i < dim; i++) {
				for (int j = 0; j < dim; j++) {
					for (int h = 0; h < dim; h++) {
						*(*(matrizResult + i) + j) = *(*(matrizResult + i) + j) + (*(*(matriz + i) + h)) * (*(*(matriz + h) + j));
					}
				}
			}
			potencia--;
		}
	}


	return matrizResult;
}

template<class T>
void Matriz<T>::imprimirMatriz(T** matriz, T dim)
{

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			cout << " " << (*(*(matriz + i) + j)) << " ";
		}
		cout << "\n";
	}
}
