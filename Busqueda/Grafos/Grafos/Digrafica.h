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
	T** matAdy, ** verInt, ** cerTran;
	int numVer;
	T* vertices, *distMin;
	MDinamicaNew md;
	Vector<T> vec, vec2;
public:
	Digrafica();
	void reservarMemoria();
	void insertar();
	void imprimir(int);
	void Warshall();
	void Floyd();
	void FloydVerInt();
	void Dijkstra();
	int buscaVertice(T);
	Lista<T>verticesAdyacentes(int);
	void buscarAmplitud(T);
	void cambiarDato(Vertice<T>, Lista<Vertice<T>>&);
	void iniciarListaVertice(Lista<Vertice<T>> &);
	void buscarProfundidad(int);
	void buscarBactraking(Lista<Vertice<T>>&, Lista<T>, Vertice<T>);
	void imprimirListaParientes(Lista<Vertice<T>>);
	~Digrafica();
};

template <class T>
Digrafica<T>::Digrafica()
{
	reservarMemoria();
	for (int Ind1 = 0; Ind1 < MAX; Ind1++)
	{
		*(distMin + Ind1) = 0;
		for (int Ind2 = 0; Ind2 < MAX; Ind2++)
		{
			if (Ind1 != Ind2)
				*(*(matAdy + Ind1) + Ind2) = 999;
			else
				*(*(matAdy + Ind1) + Ind2) = 0;
			*(*(cerTran + Ind1) + Ind2) = 0;
			*(*(verInt + Ind1) + Ind2) = 0;
		}
	}
	numVer = 0;
}

template <class T>
void Digrafica<T>::reservarMemoria() {
	matAdy = md.reservar_m(matAdy, MAX);
	cerTran = md.reservar_m(cerTran, MAX);
	verInt = md.reservar_m(verInt, MAX);
	vertices = vec.reservar(MAX);
	distMin = vec2.reservar(MAX);
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
void Digrafica<T>::Warshall()
{

}

template <class T>
void Digrafica<T>::Floyd()
{

}


template <class T>
void Digrafica<T>::FloydVerInt()
{

}


template <class T>
void Digrafica<T>::Dijkstra()
{

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

template <class T>
Lista<T> Digrafica<T>::verticesAdyacentes(int vi)
{
	Lista<T> Adyacentes;
	if (vi >= 0) {
		for (int i = 0; i < numVer; i++)
			if (*(*(matAdy + vi) + i) != 0 && *(*(matAdy + vi) + i) != 999) {
				Adyacentes.insertaFinal(*(vertices + i));
			}
	}
	return Adyacentes;
}

template<class T>
void Digrafica<T>::buscarAmplitud(T vi) {
	int vf = 0, aux = vi;
	Lista<Vertice<T>> vrts;
	Lista<T> adyacentes, adyacentesAux;
	iniciarListaVertice(vrts);
	vi = buscaVertice(vi);
	adyacentes = verticesAdyacentes(vi - 1);
	do {
		while(!adyacentes.listaVacia()){
			vf = adyacentes.eliminarPrimero();
			if (!vrts.buscar(vf)->getInfo().getVisitado()) {
				cambiarDato(Vertice<T>(vf, vi, true), vrts);
				adyacentesAux.insertaFinal(vf);
			}
		}
		vi = adyacentesAux.eliminarPrimero();
		adyacentes = verticesAdyacentes(vi - 1);
	} while (!adyacentesAux.listaVacia() || !adyacentes.listaVacia());
	cambiarDato(Vertice<T>(aux, 0, false), vrts);
	imprimirListaParientes(vrts);
}

template<class T>
void Digrafica<T>::imprimirListaParientes(Lista<Vertice<T>> vrts) {
	int cont = 0;
	NodoLista<Vertice<T>>* aux = new NodoLista<Vertice<T>>;
	Vertice<T> vrt;
	aux = vrts.regresaPrimero();
	std::cout << "\nDatos de la Lista\n\n";
	while (aux) {
		cont++;
		vrt = aux->getInfo();
		std::cout << cont << "._  " << vrt.getDato() << "  " << vrt.getPariente() << "  " << vrt.getVisitado() << std::endl;
		aux = aux->getSiguiente();
	}
}

template <class T>
void Digrafica<T>::iniciarListaVertice(Lista<Vertice<T>> &vrts) {
	Vertice<T> vrt;
	for (int i = 0; i < numVer; i++) {
		vrt = Vertice<int>(*(vertices + i), 0, false);
		vrts.insertaFinal(vrt);
	}
}

template <class T>
void Digrafica<T>::cambiarDato(Vertice<T> vrt, Lista<Vertice<T>> &vrts) {
	NodoLista<Vertice<T>>* aux;
	Vertice<T> vrtAux;
	aux = vrts.regresaPrimero();
	while (aux) {
		vrtAux = aux->getInfo();
		if (vrt.getDato() == vrtAux.getDato()) {
			aux->setInfo(vrt);
		}
		aux = aux->getSiguiente();
	}
}

template <class T>
void Digrafica<T>::buscarProfundidad(int vi) {
	Lista<Vertice<T>> vrts;
	iniciarListaVertice(vrts);
	Vertice<T> vrt = Vertice<T>(vi, 0, true);
	cambiarDato(vrt, vrts);
	buscarBactraking(vrts, Lista<T>(), vrt);
	imprimirListaParientes(vrts);
}

template<class T>
void Digrafica<T>::buscarBactraking(Lista<Vertice<T>>& vrts, Lista<T> adyacentes, Vertice<T> vrt) {
	vrt.setDato(buscaVertice(vrt.getDato()));
	adyacentes = verticesAdyacentes(vrt.getDato() - 1);
	if (!adyacentes.listaVacia()) {
		vrt.setPariente(vrt.getDato());
		for (int i = 0; !adyacentes.listaVacia(); i++) {
			vrt.setDato(adyacentes.eliminarPrimero());
			if (!vrts.buscar(vrt.getDato())->getInfo().getVisitado()) {
				vrt.setVisitado(true);
				cambiarDato(vrt, vrts);
				buscarBactraking(vrts, Lista<T>(), vrt);
			}
		}
	}
}

template<class T>
Digrafica<T>::~Digrafica() {
	md.liberar(matAdy, MAX);
	md.liberar(cerTran, MAX);
	md.liberar(verInt, MAX);
	delete[] vertices;
	delete[] distMin;
}