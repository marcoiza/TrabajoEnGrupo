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
	Vector<T> vec, vec2;
public:
	Digrafica();
	void reservarMemoria();
	void insertar();
	void iniciarVertices();
	void insertarVertice(int, int, int);
	int getCoste(int, int);
	void imprimir(int);
	int buscaVertice(T);
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
	for (int Ind1 = 0; Ind1 < MAX; Ind1++)
	{
		for (int Ind2 = 0; Ind2 < MAX; Ind2++)
		{
			if (Ind1 != Ind2)
				*(*(matAdy + Ind1) + Ind2) = 999;
			else
				*(*(matAdy + Ind1) + Ind2) = 0;
		}
	}
	numVer = 0;
}

template <class T>
void Digrafica<T>::reservarMemoria() {
	matAdy = md.reservar_m(matAdy, MAX);
	vertices = vec.reservar(MAX);
	vec.encerar();
}

template <class T>
void Digrafica<T>::insertar()
{
	int NumArcos, Indice, Origen, Destino;
	std::cout << "\n\n Ingrese numero de vertices de la grafica dirigida : ";
	std::cin >> numVer;
	for (Indice = 0; Indice < numVer; Indice++) {
		std::cout << "\n\n Ingrese el vertice : ";
		std::cin >> *(vertices + Indice);
	}
	std::cout << "\n\n Ingrese el numero de aristas de la grafica : ";
	std::cin >> NumArcos;
	Indice = 0;
	while (Indice < NumArcos)
	{
		std::cout << "\n\n Ingrese vertice origen : ";
		std::cin >> Origen;
		std::cout << "\n\n Ingrese vertice destino : ";
		std::cin >> Destino;
		std::cout << "\n\n Distancia de origen a destino : ";
		std::cin >> *(*(matAdy + Origen - 1) + Destino - 1);
		Indice++;
	}
}

template <class T>
void Digrafica<T>::iniciarVertices() {
	for (int Indice = 0; Indice < numVer; Indice++) 
		*(vertices + Indice) = Indice + 1;
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
	int Ind1, Ind2;
	switch (Opc)
	{

	case 0:
		std::cout << "\n\n Matriz de Adyacencia o de Costos : \n\n";
		for (Ind1 = 0; Ind1 < numVer; Ind1++)
		{
			for (Ind2 = 0; Ind2 < numVer; Ind2++)
				std::cout << *(*(matAdy + Ind1) + Ind2) << "\t";
			std::cout << std::endl;
		}
		break;
	case 1:
		std::cout << "\n\n Cerradura Transitiva de la Matriz de Adyacencia : " << std::endl;
		for (Ind1 = 0; Ind1 < numVer; Ind1++)
		{
			std::cout << *(vertices + Ind1) << ": ";
			for (Ind2 = 0; Ind2 < numVer; Ind2++)
				std::cout << *(*(cerTran + Ind1) + Ind2) << "\t";
			std::cout << std::endl;
		}
		break;
	case 2:
		std::cout << "\n\n Matriz de Distancias Mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < numVer; Ind1++)
		{
			std::cout << *(vertices + Ind1) << ": ";
			for (Ind2 = 0; Ind2 < numVer; Ind2++)
				std::cout << *(*(matAdy + Ind1) + Ind2) << "\t";
			std::cout << std::endl;
		}
		break;
	case 3:
		std::cout << "\n\n Vértices Intermedios para lograr distancias mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < numVer; Ind1++)
		{
			for (Ind2 = 0; Ind2 < numVer; Ind2++)
				std::cout << *(*(verInt + Ind1) + Ind2) << "\t";
			std::cout << std::endl;
		}
		break;
	case 4:
		std::cout << "\n\n Distancias mínimas a partir del vértice : " << vertices[0] << "\n\n";
		for (Ind1 = 0; Ind1 < numVer; Ind1++)
			std::cout << " " << *(distMin + Ind1) << "\t" << std::endl;
		break;
	default: break;
	}
	std::cout << std::endl;
}

template <class T>
int Digrafica<T>::buscaVertice(T VertiDato)
{
	int Indice = 0, Resp = -1;
	while (Indice < numVer && *(vertices + Indice) != VertiDato)
		Indice++;
	if (Indice < numVer)
		Resp = VertiDato;
	return Resp;
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