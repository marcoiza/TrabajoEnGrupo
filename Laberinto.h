#pragma once

#include <iostream>
#include <time.h>
#include "Archivo.h"

template< class T>
class Laberinto {
public:
	Laberinto();
	void mostrarLaberinto(T**, T);
	T** paredes(T**, T);
	T** generar(T**, T);
	void resolverLaberinto(T**, T**, T, T, T, T);
	void traspaso(T**, T**, T);
private:
	T* posX;
	T* posY;
	T opt = (10 * 10 + 1);
	Archivo<int> archivoP;
};

template< class T>
Laberinto<T>::Laberinto() {

	posX = new T[4];
	posY = new T[4];
	*(posX + 0) = 1;
	*(posX + 1) = 0;
	*(posX + 2) = -1;
	*(posX + 3) = 0;
	*(posY + 0) = 0;
	*(posY + 1) = 1;
	*(posY + 2) = 0;
	*(posY + 3) = -1;
	archivoP.crearArchivo();
	srand(time(NULL));
}

template <class T>
void Laberinto<T>::mostrarLaberinto(T** matriz, T dim) {
	Archivo<string> archivoP;
	archivoP.crearArchivo();
	archivoP.mostrar(matriz, dim);
	std::cout << "\n\t\tEncuentra la salida!" << std::endl << std::endl;
	for (int i = 0; i < dim; i++) {
		std::cout << "\t\t ";
		for (int j = 0; j < dim; j++) {
			if (*(*(matriz + i) + j) == 1) {
				std::cout << " ";
				archivoP.escribir(" ");
			}
			else if (*(*(matriz + i) + j) == 0) {
				std::cout << (char)182;
				archivoP.escribir((char)182);
			}
			else if (*(*(matriz + i) + j) == 5) {
				std::cout << (char)219;
				archivoP.escribir((char)219);
			}
			else if (*(*(matriz + i) + j) == 3 || *(*(matriz + i) + j) == 2) {
				std::cout << "O";
				archivoP.escribir("O");
			}

		}
		std::cout << std::endl;
		archivoP.escribir("\n");
	}
}

template<class T>
T** Laberinto<T>::generar(T** matriz, T dim)
{
	(*(*(matriz + dim - 2) + dim - 2)) = 3;
	int num;
	for (int i = 1; i < dim - 1; i++) {
		for (int j = 1; j < dim - 1; j++) {
			if ((*(*(matriz + i) + j)) == 0) {
				num = rand() % 2;
				(*(*(matriz + i) + j)) = num;
				if (*(*(matriz + i + 1) + j) != 3) {
					(*(*(matriz + i + 1) + j)) = 1;
				}
			}
		}
	}
	return matriz;
}

template<class T>
T** Laberinto<T>::paredes(T** matriz, T dim) 
{
	for (int j = 0; j < dim; j++) {
		(*(*(matriz + dim - 1) + j)) = 0;
	}
	for (int i = 0; i < dim; i++) {
		(*(*(matriz + i) + dim - 1)) = 0;
	}
	return matriz;
}

template< class T>
void Laberinto<T>::traspaso(T** matN, T** matO, T tam)
{
	cout << "ingresa fil" << endl;
	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			(*(*(matN + j) + i)) = (*(*(matO + j) + i));
		}
	}

}

template< class T>
void Laberinto<T>::resolverLaberinto(T** mat, T** matAux, T casilla, T i, T j, T dim) {
	int k = 0;
	int posXAux, posYAux;
	while (k <= 3)
	{
		posXAux = i + *(posX + k);
		posYAux = j + *(posY + k);
		if (((*(*(mat + posXAux) + posYAux)) == 1) && (posXAux < dim && posXAux >= 0 && posYAux < dim && posYAux >= 0) && (casilla < opt))
		{
			(*(*(mat + posXAux) + posYAux)) = casilla;
			archivoP.mostrar(mat, dim);
			if (dim - 1 == posXAux && dim - 1 == posYAux)
			{
				if (casilla < opt)
				{
					traspaso(mat, matAux, dim);
					opt = casilla;
				}
			}
			resolverLaberinto(mat, matAux, casilla + 1, posXAux, posYAux, dim);
		}
		k++;
	}
	(*(*(mat + i) + j)) = 0;
}