#pragma once

#include "Matriz.h"
#include "Laberinto.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Menu {
public:
	Menu();
	void jugar(int**, int);
	void jugadas();
	int** inicilize(int**, int);
	int getFila(void);
	void setFila(int newFila);
	int getColumna(void);
	void setColumna(int newColumna);
private:
	int fila, columna;
};

Menu::Menu()
{
	fila = 1;
	columna = 1;
}

void Menu::jugadas() {
	Matriz<int> matriz;
	Laberinto<int> lab;
	int** laberinto;
	int dim;
	std::cout << "Ingrese la dimension del laberinto(entre 19 y 50): ";
	std::cin >> dim;
	laberinto = matriz.segmentarMemoria(dim);
	matriz.encerarMatriz(laberinto, dim);
	laberinto = lab.matrizRandom(laberinto, dim);
	laberinto = lab.paredes(laberinto, dim);
	laberinto = this->inicilize(laberinto, dim);
	matriz.imprimirMatriz(laberinto, dim);
	lab.pintarLaberinto(laberinto, dim);
	char tecla;
	for (;;) {
		tecla = _getch();
		if (tecla == 80) { //abajo
			if (*(*(laberinto + fila + 1) + columna) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				fila++;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila + 1) + columna) == 1) {
				system("cls");
				*(*(laberinto + fila + 1) + columna) = 5;
				fila++;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila + 1) + columna) == 3) {
				cout << "\tSe ha resuelto el laberinto" << endl;
				break;
			}
		}
		if (tecla == 72) {//arriba
			if (*(*(laberinto + fila - 1) + columna) == 1) {
				system("cls");
				*(*(laberinto + fila - 1) + columna) = 5;
				fila--;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila - 1) + columna) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				fila--;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila - 1) + columna) == 3) {
				cout << "Resuleto felicidades" << endl;
				break;
			}
		}
		if (tecla == 75) {//izquierda
			if (*(*(laberinto + fila) + columna - 1) == 1) {
				system("cls");
				*(*(laberinto + fila) + columna - 1) = 5;
				columna--;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna - 1) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				columna--;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna - 1) == 3) {
				cout << "Resuleto felicidades" << endl;
				break;
			}
		}
		if (tecla == 77) {//derecha
			if (*(*(laberinto + fila) + columna + 1) == 1) {
				system("cls");
				*(*(laberinto + fila) + columna + 1) = 5;
				columna++;

				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna + 1) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				columna++;
				lab.pintarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna + 1) == 3) {
				cout << "Resuleto felicidades" << endl;
				break;
			}
		}
	}
	free(laberinto);
}

int** Menu::inicilize(int** matriz, int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			if ((*(*(matriz + i) + j)) == 1) {
				this->fila = i;
				this->columna = j;
				*(*(matriz + this->fila) + this->columna) = 2;
				return matriz;
			}
		}
	}
}