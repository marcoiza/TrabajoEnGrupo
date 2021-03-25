#pragma once

#include <iostream>

#include "Lista.h"
#include "Vertice.h"

#define MAX 10


template <class T>
class Digrafica
{
private:
	T MatAdy[MAX][MAX];
	int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX];
	int VerInt[MAX][MAX]; 
public:
	Digrafica();
	void Lee();
	void Imprime(int);
	void Warshall();
	void Floyd();
	void FloydVerInt();
	void Dijkstra();
	int BuscaVertice(T);
	Lista<T>VerticesAdyacentes(int);
	void buscarAmplitud(T);
	void cambiarDato(Vertice<T>&, Lista<Vertice<T>>&);
	void iniciarListaVertice(Lista<Vertice<T>> &);
	T expansion(Lista<Vertice<T>>, Lista<T>, T);
	void imprimirListaParientes(Lista<Vertice<T>>);
};

template <class T>
Digrafica<T>::Digrafica()
{
	int Ind1, Ind2;
	for (Ind1 = 0; Ind1 < MAX; Ind1++)
	{
		DistMin[Ind1] = 0;
		for (Ind2 = 0; Ind2 < MAX; Ind2++)
		{
			if (Ind1 != Ind2)
				MatAdy[Ind1][Ind2] = 999;
			else
				MatAdy[Ind1][Ind2] = 0;
			CerTran[Ind1][Ind2] = 0;
			VerInt[Ind1][Ind2] = 0;
		}
	}
	NumVer = 0;
}


template <class T>
void Digrafica<T>::Lee()
{
	int NumArcos, Indice, Origen, Destino;
	std::cout << "\n\n Ingrese número de vértices de la gráfica dirigida : ";
	std::cin >> NumVer;
	for (Indice = 0; Indice < NumVer; Indice++) {
		std::cout << "\n\n Ingrese el vertice : ";
		std::cin >> Vertices[Indice];
	}
	std::cout << "\n\n Total de aristas de la gráfica dirigida : ";
	std::cin >> NumArcos;
	Indice = 0;
	while (Indice < NumArcos)
	{
		std::cout << "\n\n Ingrese vértice origen : ";
		std::cin >> Origen;
		std::cout << "\n\n Ingrese vértice destino : ";
		std::cin >> Destino;
		std::cout << "\n\n Distancia de origen a destino : ";
		std::cin >> MatAdy[Origen - 1][Destino - 1];
		Indice++;
	}
}

template <class T>
void Digrafica<T>::Imprime(int Opc)
{
	int Ind1, Ind2;
	switch (Opc)
	{

	case 0: 
		std::cout << "\n\n Matriz de Adyacencia o de Costos : \n\n";
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << MatAdy[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 1: 
		std::cout << "\n\n Cerradura Transitiva de la Matriz de Adyacencia : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			std::cout << Vertices[Ind1] << ": ";
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << CerTran[Ind1][Ind2] << "\t";
				std::cout << std::endl;
		}
		break;
	case 2: 
		std::cout << "\n\n Matriz de Distancias Mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			std::cout << Vertices[Ind1] << ": ";
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << MatAdy[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 3: 
		std::cout << "\n\n Vértices Intermedios para lograr distancias mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << VerInt[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 4: 
		std::cout << "\n\n Distancias mínimas a partir del vértice : " << Vertices[0] << "\n\n";
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
			std::cout << " " << DistMin[Ind1] << "\t" << std::endl;
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
int Digrafica<T>::BuscaVertice(T VertiDato)
{ 
	int Indice = 0, Resp = -1;
	while (Indice < NumVer && Vertices[Indice] != VertiDato)
		Indice++;
	if (Indice < NumVer)
		Resp = VertiDato;
	return Resp;
}

template <class T>
Lista<T> Digrafica<T>::VerticesAdyacentes(int vi)
{
	Lista<T> Adyacentes;
	for (int i = 0; i < NumVer; i++)
		if (MatAdy[vi][i] != 0 && MatAdy[vi][i] != 999) {
			Adyacentes.insertaFinal(Vertices[i]);
		}
	return Adyacentes;
}

template<class T>
void Digrafica<T>::buscarAmplitud(T vi) {
	int pos = 0, posAux = 0;
	Lista<Vertice<T>> vrts;
	Lista<T> adyacentes, adyacentesAux;
	Vertice<T> vrt;
	iniciarListaVertice(vrts);
	pos = BuscaVertice(vi);
	adyacentes = VerticesAdyacentes(pos - 1);
	do {
		while(!adyacentes.listaVacia()){
			posAux = adyacentes.eliminarPrimero();
			vrt = Vertice<T>(posAux, pos, true);
			cambiarDato(vrt, vrts);
			adyacentesAux.insertaFinal(posAux);
			
		}
		pos = adyacentesAux.eliminarPrimero();
		adyacentes = VerticesAdyacentes(pos - 1);
	} while (!adyacentesAux.listaVacia());
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

template<class T>
T Digrafica<T>::expansion(Lista<Vertice<T>> vrts, Lista<T> adyacentes, T vi) {
	adyacentes = VerticesAdyacentes(vi);
	if(adyacentes.listaVacia()){
		
	}
	else{
		expansion(vrts, adyacentes, vi);
	}
}

template <class T>
void Digrafica<T>::iniciarListaVertice(Lista<Vertice<T>> &vrts) {
	Vertice<T> vrt;
	for (int i = 0; i < NumVer; i++) {
		vrt = Vertice<int>(Vertices[i], NULL, false);
		vrts.insertaFinal(vrt);
	}
}

template <class T>
void Digrafica<T>::cambiarDato(Vertice<T> &vrt, Lista<Vertice<T>> &vrts) {
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