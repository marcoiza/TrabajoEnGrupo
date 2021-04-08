#pragma once

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include "Archivo.h"

using namespace std;

template< class T>
class Laberinto {
public:
	Laberinto();
	void pintarLaberinto(T** mat, T dim);
	T** paredes(T** matriz, T dim);
	T** matrizRandom(T** matriz, T dim);
	void resolverLaberinto(T** mat, T** matAux, T casilla, T i, T j, T dim);
	void traspaso(T** matN, T** matO, T tam);
private:
	T indexI;
	T indexJ;
	T* movi;
	T* movj;
	T opt = (10 * 10 + 1);
	Archivo<int> archivoP;
};

template< class T>
Laberinto<T>::Laberinto() {

	movi = new T[4];
	movj = new T[4];

	*(movi + 0) = 1;
	*(movi + 1) = 0;
	*(movi + 2) = -1;
	*(movi + 3) = 0;

	*(movj + 0) = 0;
	*(movj + 1) = 1;
	*(movj + 2) = 0;
	*(movj + 3) = -1;

	archivoP.crearArchivo();
}

template <class T>
void Laberinto<T>::pintarLaberinto(T** matriz, T dim) {
	Archivo<string> archivoP;
	archivoP.crearArchivo();
	archivoP.mostrar(matriz, dim);
	cout << endl << "Laberinto" << endl << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if (*(*(matriz + i) + j) == 1) {
				cout << " ";
				archivoP.escribir(" ");
			}
			else if (*(*(matriz + i) + j) == 0) {
				cout << (char)197;
				archivoP.escribir((char)197);
			}
			else if (*(*(matriz + i) + j) == 5) {
				cout << "*";
				archivoP.escribir("*");
			}
			else if (*(*(matriz + i) + j) == 3 || *(*(matriz + i) + j) == 2) {
				cout << "+";
				archivoP.escribir("+");
			}

		}
		cout << endl;
		archivoP.escribir("\n");
	}
}

template<class T>
T** Laberinto<T>::matrizRandom(T** matriz, T dim)
{
	(*(*(matriz + dim - 2) + dim - 2)) = 3;
	int num;
	srand(time(NULL));
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
	int j, i;
	cout << "ingresa fil" << endl;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			(*(*(matN + j) + i)) = (*(*(matO + j) + i));
		}
	}

}

template< class T>
void Laberinto<T>::resolverLaberinto(T** mat, T** matAux, T casilla, T i, T j, T dim) {
	int k = 0;
	int newx, newy;
	while (k <= 3)
	{
		newx = i + *(movi + k);
		newy = j + *(movj + k);

		if (((*(*(mat + newx) + newy)) == 1) && (newx < dim && newx >= 0 && newy < dim && newy >= 0) && (casilla < opt))
		{

			(*(*(mat + newx) + newy)) = casilla;
			archivoP.mostrar(mat, dim);

			if (dim - 1 == newx && dim - 1 == newy)
			{

				if (casilla < opt)
				{
					traspaso(mat, matAux, dim);
					opt = casilla;
				}
			}

			resolverLaberinto(mat, matAux, casilla + 1, newx, newy, dim);
		}
		k++;
	}
	(*(*(mat + i) + j)) = 0;

}