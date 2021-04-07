#pragma once

#include <iostream>
#include <ctime>

#include "Lista.h"
#include "Vertice.h"
#include "Vector.h"
#include "MDinamicaNew.h"

#define MAX 10

template <class T>
class Grafica
{
private:
	T** matAdy;
	int numVer,* vertices;
	MDinamicaNew md;
	Vector<T> vec;
public:
	Grafica();
	void insertar();
	void iniciarVertices();
	void insertarArista(int, int, int);
	void reservarMemoria();
	void imprimir();
	void Prim();
	void Kruskal();
	int buscaVertice(T);
	void generarAristas(int);
	int aleatorio(int);
	int getCoste(int, int);
	void setNumver(int);
	void setMatAdy(T**);
	int getNumver();
	T** getMatAdy();
	T* getVertices();
	~Grafica();
};

template <class T>
Grafica<T>::Grafica()
{
	reservarMemoria();
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (i != j)
				*(*(matAdy + i) + j) = 0;
			else
				*(*(matAdy + i) + j) = 0;
	numVer = 0;
}

template <class T>
void Grafica<T>::reservarMemoria() 
{
	matAdy = md.reservarM(matAdy, MAX);
	vertices = vec.reservar(MAX);
	vec.encerar();
}

template <class T>
void Grafica<T>::imprimir() 
{
	for (int i = 0; i < numVer; i++)
	{
		for (int j = 0; j < numVer; j++)
			std::cout << *(*(matAdy + i) + j) << "\t";
		std::cout << std::endl;
	}
}

template <class T>
void Grafica<T>::insertar()
{
	int aristas, costo, i, origen, destino;
	std::cout << "\n\nIngrese total de vértices de la gráfica : ";
	std::cin >> numVer;
	for (i = 0; i < numVer; i++)
	{
		std::cout << "\nIngrese el nombre del vértice : ";
		std::cin >> *(vertices + i);
	}
	std::cout << "\n\nIngrese total de aristas de la gráfica : ";
	std::cin >> aristas;
	i = 0;
	while (i < aristas)
	{
		std::cout << "\nVértice origen : ";
		std::cin >> origen;
		std::cout << "\nVértice destino : ";
		std::cin >> destino;
		std::cout << "\nCosto de ir de " << origen << " a " << destino << " : ";
		std::cin >> costo;
		*(*(matAdy + origen - 1) + destino - 1) = costo;
		*(*(matAdy + destino - 1) + origen - 1) = costo;
		i++;
	}
}

template <class T>
void Grafica<T>::iniciarVertices() 
{
	for (int i = 0; i < numVer; i++)
		*(vertices + i) = i + 1;
}

template <class T>
void Grafica<T>::insertarArista(int origen, int destino, int coste) 
{
	*(*(matAdy + origen - 1) + destino - 1) = coste;
	*(*(matAdy + destino - 1) + origen - 1) = coste;
}

template <class T>
void Grafica<T>::Prim()
{
	int mCosto[MAX], verAux[MAX], verMen, menCos;
	for (int i = 0; i < numVer; i++)
	{
		mCosto[i] = matAdy[0][i];
		verAux[i] = 0;
	}
	std::cout << "\n\n\nArcos y costos del árbol abarcador de costo mínimo\n\n";
	std::cout << "\nVértice Vértice costo \n";
	for (int i = 0; i < numVer - 1; i++)
	{
		menCos = mCosto[1];
		verMen = 1;
		for (int j = 2; j < numVer; j++)
			if (mCosto[j] < menCos)
			{
				menCos = mCosto[j];
				verMen = j;
			}
				std::cout << "\n " << vertices[verMen] << " - " << vertices[verAux[verMen]]
				<< " " << matAdy[verMen][verAux[verMen]];
			mCosto[verMen] = 1000;
			for (int j = 1; j < numVer; j++)
				if ((matAdy[verMen][j] < mCosto[j]) && mCosto[j] < 1000)
				{
					mCosto[j] = matAdy[verMen][j];
					verAux[j] = verMen;
				}
	}
	std::cout << "\n\n";
}

template <class T>
void Grafica<T>::Kruskal()
{
}

template <class T>
int Grafica<T>::buscaVertice(T datoVertice)
{
	int indice = 0, resp = -1;
	while (indice < numVer && *(vertices + indice) != datoVertice)
		indice++;
	if (indice < numVer)
		resp = datoVertice;
	return resp;
}

template <class T>
void Grafica<T>::generarAristas(int numAr) {
	if (numAr<=numVer && numVer > 5) {
		int aux = 0, aux2 = 0;
		for (int i = 0; i < numAr;) {	
			aux = abs(aleatorio(numVer + i) - i);
			do {
				aux2 = aleatorio(abs(numVer - i));
			} while (aux == aux2);
			if (*(*(matAdy + aux) + aux2) == 0 || *(*(matAdy + aux2) + aux) == 0) {
				*(*(matAdy + aux) + aux2) = 1;
				*(*(matAdy + aux2) + aux) = 1;
				i++;
			}
		}
	}
}

template <class T>
int Grafica<T>::aleatorio(int numAr) {
	srand(time(NULL));
	if (numAr == 0) {
		numAr = 1;
	}
	return rand() % (numAr);
}

template <class T>
int  Grafica<T>::getCoste(int origen, int destino) {
	return *(*(matAdy + origen) + destino);
}

template<class T>
void Grafica<T>::setNumver(int numVer) {
	this->numVer = numVer;
}

template<class T>
void Grafica<T>::setMatAdy(T** matAdy) {
	this->matAdy = matAdy;
}

template<class T>
int Grafica<T>::getNumver() {
	return numVer;
}

template<class T>
T** Grafica<T>::getMatAdy() {
	return matAdy;
}

template<class T>
T* Grafica<T>::getVertices() {
	return vertices;
}

template<class T>
Grafica<T>::~Grafica() {
	md.liberar(matAdy, MAX);
	delete[] vertices;
}