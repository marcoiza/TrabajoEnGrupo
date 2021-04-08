#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Matriz.h"
#include "Laberinto.h"
#include "Ingreso.h"

class Menu {
public:
	Menu();
	void jugar();
	int** iniciar(int**, int);
private:
	int fila, columna;
	Matriz<int> matriz;
	Laberinto<int> objLaberinto;
	Ingreso objIngrso;
};

Menu::Menu()
{
	fila = 1;
	columna = 1;
}

void Menu::jugar() {
	int** laberinto;
	int dim = objIngrso.ingresoInt("Ingrese la dimension del laberinto(entre 19 y 50): ", 19 , 50);
	bool bandera = false;
	laberinto = matriz.separarMemoria(dim);
	matriz.encerarMatriz(laberinto, dim);
	laberinto = objLaberinto.generar(laberinto, dim);
	laberinto = objLaberinto.paredes(laberinto, dim);
	laberinto = this->iniciar(laberinto, dim);
	objLaberinto.mostrarLaberinto(laberinto, dim);
	char tecla;
	while(bandera != true){
		tecla = _getch();
		if (tecla == 80) {
			if (*(*(laberinto + fila + 1) + columna) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				fila++;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila + 1) + columna) == 1) {
				system("cls");
				*(*(laberinto + fila + 1) + columna) = 5;
				fila++;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila + 1) + columna) == 3) {
				std::cout << "\tSe ha resuelto el laberinto" << std::endl;
				bandera = true;
			}
		}
		if (tecla == 72) {//arriba
			if (*(*(laberinto + fila - 1) + columna) == 1) {
				system("cls");
				*(*(laberinto + fila - 1) + columna) = 5;
				fila--;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila - 1) + columna) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				fila--;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila - 1) + columna) == 3) {
				std::cout << "\tSe ha resuelto el laberinto" << std::endl;
				bandera = true;
			}
		}
		if (tecla == 75) {//izquierda
			if (*(*(laberinto + fila) + columna - 1) == 1) {
				system("cls");
				*(*(laberinto + fila) + columna - 1) = 5;
				columna--;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna - 1) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				columna--;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna - 1) == 3) {
				std::cout << "\tSe ha resuelto el laberinto" << std::endl;
				bandera = true;
			}
		}
		if (tecla == 77) {//derecha
			if (*(*(laberinto + fila) + columna + 1) == 1) {
				system("cls");
				*(*(laberinto + fila) + columna + 1) = 5;
				columna++;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna + 1) == 5) {
				system("cls");
				*(*(laberinto + fila) + columna) = 1;
				columna++;
				objLaberinto.mostrarLaberinto(laberinto, dim);
			}
			else if (*(*(laberinto + fila) + columna + 1) == 3) {
				std::cout << "\tSe ha resuelto el laberinto" << std::endl;
				bandera = true;
			}
		}
	}
	free(laberinto);
}

int** Menu::iniciar(int** matriz, int dim) {
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