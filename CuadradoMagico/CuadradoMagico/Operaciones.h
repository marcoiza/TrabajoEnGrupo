#pragma once
#include <iostream>
#include <queue>
#include "CuadroMagico.h"

class Operaciones {
private:
	int **matriz;
	int fila;
	int columna;
	bool hecho;
	std::queue<int> numeros;
public:
	void resolverCuadro(CuadroMagico);
	void inicializarMatriz(CuadroMagico);
	void encerarMatriz(CuadroMagico);
	void ubicarNumero(CuadroMagico);
	bool validarPosicion(CuadroMagico);
	void mostrarCuadro(CuadroMagico);
	bool cuadroValido(CuadroMagico);
	bool indiceYSumaValido(CuadroMagico, int, int);
	bool validarHorizontal(CuadroMagico, int);
	bool validarVertical(CuadroMagico, int);
	bool validarDiagonal1(CuadroMagico);
	bool validarDiagonal2(CuadroMagico);
	void sigPosicion(CuadroMagico);
	void antPosicion(CuadroMagico);
};

void Operaciones::resolverCuadro(CuadroMagico cuadro) {
	if (!cuadro.numeroValido()) {
		std::cout << " El cuadro no tiene solucion." << std::endl;
	}
	else
	{
		inicializarMatriz(cuadro);
		encerarMatriz(cuadro);
		for (int i = cuadro.getLimiteCuadro(); i > 0; i--)
			numeros.push(i);
		fila = columna = 0;
		hecho = false;
		ubicarNumero(cuadro);
		if (!hecho)
			std::cout << " No hay solucion para el cuadro. " << std::endl;
	}
	free(this->matriz);
}

void Operaciones::inicializarMatriz(CuadroMagico cuadro) {
	int i, n=cuadro.getTamano();
	this->matriz = new int* [n];
	for (i = 0; i < n; i++)
		this->matriz[i] = new int[n];
}

void Operaciones::encerarMatriz(CuadroMagico cuadro) {
	for (int i = 0; i < cuadro.getTamano(); i++) {
		for (int j = 0; j < cuadro.getTamano(); j++) {
			//*(*(matriz + i) + j) = 0;
			this->matriz[i][j] = 0;
		}
	}
}

void Operaciones::ubicarNumero(CuadroMagico cuadro) {
	int k, n, m, e;
	if ((numeros.size() > 0) && validarPosicion(cuadro)) {
		n = numeros.size();
		k = 0;
		do {
			m = numeros.front();
			numeros.pop();
			if ((e = *(*(matriz + fila) + columna)) != 0)
				numeros.push(e);
			*(*(matriz + fila) + columna) = m;
			++k;
			if (cuadroValido(cuadro)) {
				if (numeros.size() == 0) {
					hecho = true;
					mostrarCuadro(cuadro);
				}
				else
				{
					sigPosicion(cuadro);
					ubicarNumero(cuadro);
				}
			}
		} while (k < n && !hecho);

		if (!hecho) { //backtrack
			numeros.push(*(*(matriz + fila) + columna));
			*(*(matriz + fila) + columna) = 0;
			antPosicion(cuadro);
		}
	}
}

bool Operaciones::validarPosicion(CuadroMagico cuadro) {
	int n = cuadro.getTamano();
	return fila >= 0 && fila < n && columna >= 0 && columna < n;
}

void Operaciones::mostrarCuadro(CuadroMagico cuadro) {
	std::cout << "Numero magico: " << cuadro.getTamano() << std::endl;
	for (int i = 0; i < cuadro.getTamano(); i++) {
		for (int j = 0; j < cuadro.getTamano(); j++) {
			std::cout << " " <<*(*(matriz + i) + j);
		}
		std::cout << "\n";
	}
}

bool Operaciones::cuadroValido(CuadroMagico cuadro) {
	int filaAux = 0, columnaAux = 0, n = cuadro.getTamano();
	while (filaAux < n && validarHorizontal(cuadro, filaAux)) {
		++filaAux;
	}
	while (columnaAux < n && validarVertical(cuadro, columnaAux)) {
		++columnaAux;
	}
	return filaAux == n && columnaAux == n && validarDiagonal1(cuadro) && validarDiagonal2(cuadro);
}

bool Operaciones::indiceYSumaValido(CuadroMagico cuadro, int indice, int suma) {
	int n = cuadro.getTamano(), numeroMgc = cuadro.getNumeroMagico();
	return suma == 0 || (indice < n && suma < numeroMgc) || (indice == n && suma == numeroMgc);
}

bool Operaciones::validarHorizontal(CuadroMagico cuadro, int fila) {
	int columnaAux = 0, aux1, aux2 = 0;
	while (columnaAux < cuadro.getTamano() && (aux1 = *(*(matriz + fila) + columnaAux)) != 0) {
		aux2 += aux1;
		++columnaAux;
	}
	return indiceYSumaValido(cuadro, columnaAux, aux2);
}

bool Operaciones::validarVertical(CuadroMagico cuadro, int columna) {
	int filaAux = 0, aux1, aux2 = 0;
	while (filaAux < cuadro.getTamano() && (aux1 = *(*(matriz + filaAux) + columna)) != 0) {
		aux2 += aux1;
		++filaAux;
	}
	return indiceYSumaValido(cuadro, filaAux, aux2);
}

bool Operaciones::validarDiagonal1(CuadroMagico cuadro) {
	int filaAux = 0, aux1, aux2 = 0;
	while (filaAux < cuadro.getTamano() && (aux1 = *(*(matriz + filaAux) + filaAux)) != 0) {
		aux2 += aux1;
		++filaAux;
	}
	return indiceYSumaValido(cuadro, filaAux, aux2);
}

bool Operaciones::validarDiagonal2(CuadroMagico cuadro) {
	int filaAux = 0, columnaAux = 2, aux1, aux2 = 0;
	while ((filaAux < cuadro.getTamano()) && (columnaAux >= 0) && ((aux1 = *(*(matriz + filaAux) + columnaAux)) != 0)) {
		aux2 += aux1;
		++filaAux;
		--columnaAux;
	}
	return indiceYSumaValido(cuadro, filaAux, aux2);
}

void Operaciones::sigPosicion(CuadroMagico cuadro) {
	if (columna == cuadro.getTamano() - 1) {
		columna = 0;
		++fila;
	}
	else
	{
		++columna;
	}
}

void Operaciones::antPosicion(CuadroMagico cuadro) {
	if (columna == 0) {
		columna = cuadro.getTamano() - 1;
		--fila;
	}
	else
	{
		--columna;
	}
}