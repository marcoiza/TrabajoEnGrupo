#pragma once

#include <iostream>
#include "Lista.h"
#include "Vertice.h"
#include "Vector.h"
#include "MDinamicaNew.h"

#define MAX 10

template <class T>
class Digrafica
{
private:
	T** matAdy;
	int numVer;
	T* vertices;
	MDinamicaNew md;
	Vector<T> vec;
public:
	Digrafica();
	void reservarMemoria();
	void insertar();
	void iniciarVertices();
	void insertarVertice(int, int, int);
	int getCoste(int, int);
	void imprimir(int);
	int buscaVertice(T);
	void generarAristas(int);
	int aleatorio(int);
	void setNumver(int);
	void setMatAdy(T**);
	int getNumver();
	T** getMatAdy();
	T* getVertices();
	~Digrafica();
};

template <class T>
Digrafica<T>::Digrafica()
{
	reservarMemoria();
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i != j)
				*(*(matAdy + i) + j) = 0;
			else
				*(*(matAdy + i) + j) = 0;
		}
	}
	numVer = 0;
}

template <class T>
void Digrafica<T>::reservarMemoria() {
	matAdy = md.reservarM(matAdy, MAX);
	vertices = vec.reservar(MAX);
	vec.encerar();
}

template <class T>
void Digrafica<T>::insertar()
{
	int numArcos, indice, origen, destino;
	std::cout << "\n\n Ingrese numero de vertices de la grafica dirigida : ";
	std::cin >> numVer;
	for (indice = 0; indice < numVer; indice++) {
		std::cout << "\n\n Ingrese el vertice : ";
		std::cin >> *(vertices + indice);
	}
	std::cout << "\n\n Ingrese el numero de aristas de la grafica : ";
	std::cin >> numArcos;
	indice = 0;
	while (indice < numArcos)
	{
		std::cout << "\n\n Ingrese vertice origen : ";
		std::cin >> origen;
		std::cout << "\n\n Ingrese vertice destino : ";
		std::cin >> destino;
		std::cout << "\n\n Distancia de origen a destino : ";
		std::cin >> *(*(matAdy + origen - 1) + destino - 1);
		indice++;
	}
}

template <class T>
void Digrafica<T>::iniciarVertices() {
	for (int indice = 0; indice < numVer; indice++) 
		*(vertices + indice) = indice + 1;
}

template <class T>
void Digrafica<T>::insertarVertice(int origen, int destino, int coste) {
	*(*(matAdy + origen - 1) + destino - 1) = coste;
}

template <class T>
int  Digrafica<T>::getCoste(int origen, int destino) {
	return *(*(matAdy + origen) + destino);
}

template <class T>
void Digrafica<T>::imprimir(int Opc)
{
	int i, j;
	switch (Opc)
	{

	case 0:
		std::cout << "\n\n Matriz de Adyacencia o de Costos : \n\n";
		for (i = 0; i < numVer; i++)
		{
			for (j = 0; j < numVer; j++)
				std::cout << *(*(matAdy + i) + j) << "\t";
			std::cout << std::endl;
		}
		break;
	case 1:
		std::cout << "\n\n Cerradura Transitiva de la Matriz de Adyacencia : " << std::endl;
		for (i = 0; i < numVer; i++)
		{
			std::cout << *(vertices + i) << ": ";
			for (j = 0; j < numVer; j++)
				std::cout << *(*(cerTran + i) + j) << "\t";
			std::cout << std::endl;
		}
		break;
	case 2:
		std::cout << "\n\n Matriz de Distancias Mínimas : " << std::endl;
		for (i = 0; i < numVer; i++)
		{
			std::cout << *(vertices + i) << ": ";
			for (j = 0; j < numVer; j++)
				std::cout << *(*(matAdy + i) + j) << "\t";
			std::cout << std::endl;
		}
		break;
	case 3:
		std::cout << "\n\n Vértices Intermedios para lograr distancias mínimas : " << std::endl;
		for (i = 0; i < numVer; i++)
		{
			for (j = 0; j < numVer; j++)
				std::cout << *(*(verInt + i) + j) << "\t";
			std::cout << std::endl;
		}
		break;
	case 4:
		std::cout << "\n\n Distancias mínimas a partir del vértice : " << vertices[0] << "\n\n";
		for (i = 0; i < numVer; i++)
			std::cout << " " << *(distMin + i) << "\t" << std::endl;
		break;
	default: break;
	}
	std::cout << std::endl;
}

template <class T>
int Digrafica<T>::buscaVertice(T datoVertice)
{
	int indice = 0, Resp = -1;
	while (indice < numVer && *(vertices + indice) != datoVertice)
		indice++;
	if (indice < numVer)
		Resp = datoVertice;
	return Resp;
}

template <class T>
void Digrafica<T>::generarAristas(int numAr) {
	if (numAr <= (numVer + (numVer/2)) && numVer > 5) {
		int aux = 0, aux2 = 0;
		for (int i = 0; i < numAr;) {
			aux = abs(aleatorio(numVer + i) - i);
			do {
				aux2 = aleatorio(abs(numVer - i));
			} while (aux == aux2);	
			if (*(*(matAdy + aux) + aux2) == 0) {
				*(*(matAdy + aux) + aux2) = 1;
				i++;
			}
			else if (*(*(matAdy + aux2) + aux) == 0) {
				*(*(matAdy + aux2) + aux) = 1;
				i++;
			}
		}
	}
}

template <class T>
int Digrafica<T>::aleatorio(int numAr) {
	if (numAr == 0) {
		numAr = 1;
	}
	srand(time(NULL));
	return rand() % (numAr);
}

template<class T>
void Digrafica<T>::setNumver(int numVer) {
	this->numVer = numVer;
}

template<class T>
void Digrafica<T>::setMatAdy(T** matAdy) {
	this->matAdy = matAdy;
}

template<class T>
int Digrafica<T>::getNumver() {
	return numVer;
}

template<class T>
T** Digrafica<T>::getMatAdy() {
	return matAdy;
}

template<class T>
T* Digrafica<T>::getVertices() {
	return vertices;
}

template<class T>
Digrafica<T>::~Digrafica() {
	md.liberar(matAdy, MAX);
	delete[] vertices;
}