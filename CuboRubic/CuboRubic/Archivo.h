#pragma once

#include <iostream>
#include <fstream> 

using namespace std;

class Archivo
{
public:
	fstream archivo;
	int contador;
	int n;
	
	void crearArchivo() {
		archivo.open("solucion.txt", fstream::out); //para leer in, para salir es out escribir
		archivo << "solucion " << n << "*" << n << endl << endl;
		contador = 0;
	}

	
	void escribirArchivo(char** tablero) {
		contador++;
		archivo << "Solucion N " << contador << endl;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 12; j++) {
				archivo << *(*(tablero + i) + j) << " ";
			}
			archivo << endl;
		}
		archivo << endl;
	}

	void cerrarArchivo() {
		archivo.close();
	}
};

