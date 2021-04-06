#pragma once

#include "Lista.h"
#include "Vertice.h"

template <class T>
class Recorridos {
public:
	int buscaVertice(T , int* , int );
	Lista<T> verticesAdyacentes(int, T** , T* , int );
	Lista<Vertice<T>> buscarAmplitud(T, int**, int* ,int);
	void cambiarDato(Vertice<T>, Lista<Vertice<T>>&);
	void iniciarListaVertice(Lista<Vertice<T>>&, int*, int);
	void iniciarListaVertice(Lista<Vertice<T>>&, int);
	Lista<Vertice<T>> buscarProfundidad(int, int**, int* , int);
	void buscarBactraking(Lista<Vertice<T>>&, int**, int*, Lista<T>, Vertice<T>);
};

template <class T>
int Recorridos<T>::buscaVertice(T VertiDato, int* vertices, int numVer)
{
	int Indice = 0, Resp = -1;
	while (Indice < numVer && *(vertices + Indice) != VertiDato)
		Indice++;
	if (Indice < numVer)
		Resp = VertiDato;
	return Resp;
}

template <class T>
Lista<T> Recorridos<T>::verticesAdyacentes(int vi, T** matAdy, T* vertices, int numVer)
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

template <class T>
void Recorridos<T>::iniciarListaVertice(Lista<Vertice<T>>& vrts, int numVer)
{
	Vertice<T> vrt;
	for (int i = 0; i < 9; i++) {
		vrt = Vertice<int>(0 , 0, false);
		vrts.insertaFinal(vrt);
	}
}

template <class T>
void Recorridos<T>::iniciarListaVertice(Lista<Vertice<T>>& vrts, int* vertices, int numVer) 
{
	Vertice<T> vrt;
	for (int i = 0; i < 9; i++) {
		vrt = Vertice<int>(*(vertices + i), 0, false);
		vrts.insertaFinal(vrt);
	}
}

template<class T>
Lista<Vertice<T>> Recorridos<T>::buscarAmplitud(T vi,int**matAdy, int* vertices, int numVer) 
{
	int vf = 0, aux = vi;
	Lista<Vertice<T>> vrts;
	Lista<T> adyacentes, adyacentesAux;
	iniciarListaVertice(vrts, vertices, numVer);
	vi = buscaVertice(vi, vertices, numVer);
	adyacentes = verticesAdyacentes(vi - 1, matAdy, vertices, numVer);
	do {
		while (!adyacentes.listaVacia()) {
			vf = adyacentes.eliminarPrimero();
			if (!vrts.buscar(vf)->getInfo().getVisitado()) {
				cambiarDato(Vertice<T>(vf, vi, true), vrts);
				adyacentesAux.insertaFinal(vf);
			}
		}
		vi = adyacentesAux.eliminarPrimero();
		adyacentes = verticesAdyacentes(vi - 1, matAdy, vertices, numVer);
	} while (!adyacentesAux.listaVacia() || !adyacentes.listaVacia());
	cambiarDato(Vertice<T>(aux, 0, false), vrts);
	return vrts;
}

template <class T>
void Recorridos<T>::cambiarDato(Vertice<T> vrt, Lista<Vertice<T>>& vrts) 
{
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
Lista<Vertice<T>> Recorridos<T>::buscarProfundidad(int vi, int** matAdy, int* vertices, int numVer) 
{
	Lista<Vertice<T>> vrts;
	iniciarListaVertice(vrts, vertices, numVer);
	Vertice<T> vrt = Vertice<T>(vi, 0, true);
	cambiarDato(vrt, vrts);
	buscarBactraking(vrts, matAdy, vertices, Lista<T>(), vrt);
	return vrts;
}

template<class T>
void Recorridos<T>::buscarBactraking(Lista<Vertice<T>>& vrts, int** matAdy, int* vertices, 
	Lista<T> adyacentes, Vertice<T> vrt) 
{	
	vrt.setDato(buscaVertice(vrt.getDato(), vertices, 9));
	adyacentes = verticesAdyacentes(vrt.getDato() - 1, matAdy, vertices, 9);
	if (!adyacentes.listaVacia()) {
		vrt.setPariente(vrt.getDato());
		for (int i = 0; !adyacentes.listaVacia(); i++) {
			vrt.setDato(adyacentes.eliminarPrimero());
			if (!vrts.buscar(vrt.getDato())->getInfo().getVisitado()) {
				vrt.setVisitado(true);
				cambiarDato(vrt, vrts);
				buscarBactraking(vrts, matAdy, vertices, Lista<T>(), vrt);
			}
		}
	}
}