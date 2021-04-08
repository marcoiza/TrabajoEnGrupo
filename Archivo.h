#pragma once

#include <fstream>

using namespace std;

template <class T>
class Archivo
{
public:
	Archivo() {};
	void crearArchivo();
	void mostrar(int** tablero, int n);
	void escribir(string dato);
	void escribir(char dato);
private:
	int contador;
	fstream archivo;
};

template <class T>
void Archivo<T>::crearArchivo() {
	archivo.open("Laberinto.txt", fstream::out); //para leer in, para salir es out escribir
	contador = 0;
}

template <class T>
void Archivo<T>::mostrar(int** tablero, int n) {
	contador++;
	archivo << "Laberinto " << contador << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			archivo << *(*(tablero + i) + j) << "  ";
		}
		archivo << endl;
	}
	archivo << endl;
	archivo << "Laberinto " << endl;
}

template <class T>
void Archivo<T>::escribir(char dato) {
	archivo << dato;
}

template <class T>
void Archivo<T>::escribir(string dato) {
	archivo << dato;
}