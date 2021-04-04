#pragma once

#include <iostream>

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
	void Grafica<T>::insertarVertice(int, int, int);
	void reservarMemoria();
	void imprimir();
	void Prim();
	void Kruskal();

	int buscaVertice(T);
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
	for (int Ind1 = 0; Ind1 < MAX; Ind1++)
		for (int Ind2 = 0; Ind2 < MAX; Ind2++)
			if (Ind1 != Ind2)
				*(*(matAdy + Ind1) + Ind2) = 999;
			else
				*(*(matAdy + Ind1) + Ind2) = 0;
	numVer = 0;
}

template <class T>
void Grafica<T>::reservarMemoria() {
	matAdy = md.reservar_m(matAdy, MAX);
	vertices = vec.reservar(MAX);
	vec.encerar();
}

template <class T>
void Grafica<T>::imprimir() {
	for (int Ind1 = 0; Ind1 < numVer; Ind1++)
	{
		for (int Ind2 = 0; Ind2 < numVer; Ind2++)
			std::cout << *(*(matAdy + Ind1) + Ind2) << "\t";
		std::cout << std::endl;
	}
}

template <class T>
void Grafica<T>::insertar()
{
	int Aristas, Costo, Ind1, Origen, Destino;
	std::cout << "\n\nIngrese total de vértices de la gráfica : ";
	std::cin >> numVer;
	for (Ind1 = 0; Ind1 < numVer; Ind1++)
	{
		std::cout << "\nIngrese el nombre del vértice : ";
		std::cin >> *(vertices + Ind1);
	}
	std::cout << "\n\nIngrese total de aristas de la gráfica : ";
	std::cin >> Aristas;
	Ind1 = 0;
	while (Ind1 < Aristas)
	{
		std::cout << "\nVértice origen : ";
		std::cin >> Origen;
		std::cout << "\nVértice destino : ";
		std::cin >> Destino;
		std::cout << "\nCosto de ir de " << Origen << " a " << Destino << " : ";
		std::cin >> Costo;
		*(*(matAdy + Origen - 1) + Destino - 1) = Costo;
		*(*(matAdy + Destino - 1) + Origen - 1) = Costo;
		Ind1++;
	}
}

template <class T>
void Grafica<T>::iniciarVertices() {
	for (int Indice = 0; Indice < numVer; Indice++)
		*(vertices + Indice) = Indice + 1;
}

template <class T>
void Grafica<T>::insertarVertice(int origen, int destino, int coste) {
	*(*(matAdy + origen - 1) + destino - 1) = coste;
	*(*(matAdy + destino - 1) + origen - 1) = coste;
}

template <class T>
void Grafica<T>::Prim()
{
	int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
	for (Ind1 = 0; Ind1 < numVer; Ind1++)
	{
		MCosto[Ind1] = matAdy[0][Ind1];
		VerAux[Ind1] = 0;
	}
	std::cout << "\n\n\nArcos y costos del árbol abarcador de costo mínimo\n\n";
	std::cout << "\nVértice Vértice Costo \n";
	for (Ind1 = 0; Ind1 < numVer - 1; Ind1++)
	{
		MenCos = MCosto[1];
		VerMen = 1;
		for (Ind2 = 2; Ind2 < numVer; Ind2++)
			if (MCosto[Ind2] < MenCos)
			{
				MenCos = MCosto[Ind2];
				VerMen = Ind2;
			}
				std::cout << "\n " << vertices[VerMen] << " - " << vertices[VerAux[VerMen]]
				<< " " << matAdy[VerMen][VerAux[VerMen]];
			MCosto[VerMen] = 1000;
			for (Ind2 = 1; Ind2 < numVer; Ind2++)
				if ((matAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
				{
					MCosto[Ind2] = matAdy[VerMen][Ind2];
					VerAux[Ind2] = VerMen;
				}
	}
	std::cout << "\n\n";
}

template <class T>
void Grafica<T>::Kruskal()
{
}

template <class T>
int Grafica<T>::buscaVertice(T VertiDato)
{
	int Indice = 0, Resp = -1;
	while (Indice < numVer && *(vertices + Indice) != VertiDato)
		Indice++;
	if (Indice < numVer)
		Resp = VertiDato;
	return Resp;
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