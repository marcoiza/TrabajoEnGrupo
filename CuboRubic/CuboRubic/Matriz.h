#pragma once

#include <iostream>

template <class T>
class Matriz
{
public:
	T** reservarM(T**, int, int);
	void encerar(T**, int, int);
	void imprimir(T**, int, int);
	void liberar(T**, int, int);
};

template <class T>
void Matriz<T>::encerar(T** mat, int x, int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			*(*(mat + i) + j) = '0';
		}
	}
}

template<class T>
inline void Matriz<T>::imprimir(T** mat, int x, int y)
{
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			std::cout << *(*(mat + i) + j) << " ";
		}
		std::cout << std::endl;
	}
}


template <class T>
T** Matriz<T>::reservarM(T** mat, int x, int y)
{
	mat = new T * [x];
	for (int i = 0; i < x; i++) {
		*(mat + i) = new T[y];
	}
	return mat;
}

template <class T>
void Matriz<T>::liberar(T** mat, int x, int y)
{
	for (int i = 0; i < y; i++) {
		delete[]mat[i];
	}
	delete[]mat;
}