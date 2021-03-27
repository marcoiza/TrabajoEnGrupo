#pragma once

#include <iostream>

#include "Lista.h"
#include "Vertice.h"
#include "Vector.h"
#include "MDinamicaNew.h"

#define MAX 20

template <class T>
class Grafica
{
private:
	T** MatAdy;
	int NumVer,* Vertices;
	MDinamicaNew md;
	Vector<T> vec;
public:
	Grafica();
	void insertar();
	void reservarMemoria();
	void Imprime();
	void Prim();
	void Kruskal();

	int buscaVertice(T);
	Lista<T>verticesAdyacentes(int);
	void buscarAmplitud(T);
	void cambiarDato(Vertice<T>, Lista<Vertice<T>>&);
	void iniciarListaVertice(Lista<Vertice<T>>&);
	void buscarProfundidad(int);
	void buscarBactraking(Lista<Vertice<T>>&, Lista<T>, Vertice<T>);
	void imprimirListaParientes(Lista<Vertice<T>>);
	~Grafica();
};

template <class T>
Grafica<T>::Grafica()
{
	reservarMemoria();
	for (int Ind1 = 0; Ind1 < MAX; Ind1++)
		for (int Ind2 = 0; Ind2 < MAX; Ind2++)
			if (Ind1 != Ind2)
				*(*(MatAdy + Ind1) + Ind2) = 999;
			else
				*(*(MatAdy + Ind1) + Ind2) = 0;
	NumVer = 0;
}

template <class T>
void Grafica<T>::reservarMemoria() {
	MatAdy = md.reservar_m(MatAdy, MAX);
	Vertices = vec.reservar(MAX);
}

template <class T>
void Grafica<T>::Imprime() {
	for (int Ind1 = 0; Ind1 < NumVer; Ind1++)
	{
		for (int Ind2 = 0; Ind2 < NumVer; Ind2++)
			std::cout << *(*(MatAdy + Ind1) + Ind2) << "\t";
		std::cout << std::endl;
	}
}

template <class T>
void Grafica<T>::insertar()
{
	int Aristas, Costo, Ind1, Origen, Destino;
	std::cout << "\n\nIngrese total de v�rtices de la gr�fica : ";
	std::cin >> NumVer;
	for (Ind1 = 0; Ind1 < NumVer; Ind1++)
	{
		std::cout << "\nIngrese el nombre del v�rtice : ";
		std::cin >> *(Vertices + Ind1);
	}
	std::cout << "\n\nIngrese total de aristas de la gr�fica : ";
	std::cin >> Aristas;
	Ind1 = 0;
	while (Ind1 < Aristas)
	{
		std::cout << "\nV�rtice origen : ";
		std::cin >> Origen;
		std::cout << "\nV�rtice destino : ";
		std::cin >> Destino;
		std::cout << "\nCosto de ir de " << Origen << " a " << Destino << " : ";
		std::cin >> Costo;
		*(*(MatAdy + Origen - 1) + Destino - 1) = Costo;
		*(*(MatAdy + Destino - 1) + Origen - 1) = Costo;
		Ind1++;
	}
}

template <class T>
void Grafica<T>::Prim()
{
	int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
	for (Ind1 = 0; Ind1 < NumVer; Ind1++)
	{
		MCosto[Ind1] = MatAdy[0][Ind1];
		VerAux[Ind1] = 0;
	}
	std::cout << "\n\n\nArcos y costos del �rbol abarcador de costo m�nimo\n\n";
	std::cout << "\nV�rtice V�rtice Costo \n";
	for (Ind1 = 0; Ind1 < NumVer - 1; Ind1++)
	{
		MenCos = MCosto[1];
		VerMen = 1;
		for (Ind2 = 2; Ind2 < NumVer; Ind2++)
			if (MCosto[Ind2] < MenCos)
			{
				MenCos = MCosto[Ind2];
				VerMen = Ind2;
			}
				std::cout << "\n " << Vertices[VerMen] << " - " << Vertices[VerAux[VerMen]]
				<< " " << MatAdy[VerMen][VerAux[VerMen]];
			MCosto[VerMen] = 1000;
			for (Ind2 = 1; Ind2 < NumVer; Ind2++)
				if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
				{
					MCosto[Ind2] = MatAdy[VerMen][Ind2];
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
	while (Indice < NumVer && *(Vertices + Indice) != VertiDato)
		Indice++;
	if (Indice < NumVer)
		Resp = VertiDato;
	return Resp;
}

template <class T>
Lista<T> Grafica<T>::verticesAdyacentes(int vi)
{
	Lista<T> Adyacentes;
	if (vi >= 0) {
		for (int i = 0; i < NumVer; i++)
			if (*(*(MatAdy + vi) + i) != 0 && *(*(MatAdy + vi) + i) != 999) {
				Adyacentes.insertaFinal(*(Vertices + i));
			}
	}
	return Adyacentes;
}

template<class T>
void Grafica<T>::buscarAmplitud(T vi) {
	int vf = 0, aux = vi;
	Lista<Vertice<T>> vrts;
	Lista<T> adyacentes, adyacentesAux;
	iniciarListaVertice(vrts);
	vi = buscaVertice(vi);
	adyacentes = verticesAdyacentes(vi - 1);
	do {
		while (!adyacentes.listaVacia()) {
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
void Grafica<T>::imprimirListaParientes(Lista<Vertice<T>> vrts) {
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
void Grafica<T>::iniciarListaVertice(Lista<Vertice<T>>& vrts) {
	Vertice<T> vrt;
	for (int i = 0; i < NumVer; i++) {
		vrt = Vertice<int>(*(Vertices + i), 0, false);
		vrts.insertaFinal(vrt);
	}
}

template <class T>
void Grafica<T>::cambiarDato(Vertice<T> vrt, Lista<Vertice<T>>& vrts) {
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
void Grafica<T>::buscarProfundidad(int vi) {
	Lista<Vertice<T>> vrts;
	Vertice<T> vrt = Vertice<T>(vi, 0, false);
	iniciarListaVertice(vrts);
	buscarBactraking(vrts, Lista<T>(), vrt);
	cambiarDato(vrt, vrts);
	imprimirListaParientes(vrts);
}

template<class T>
void Grafica<T>::buscarBactraking(Lista<Vertice<T>>& vrts, Lista<T> adyacentes, Vertice<T> vrt) {
	vrt.setDato(buscaVertice(vrt.getDato()));
	adyacentes = verticesAdyacentes(vrt.getDato() - 1);
	if (!adyacentes.listaVacia()) {
		vrt.setPariente(vrt.getDato());
		for (int i = 0; !adyacentes.listaVacia(); i++) {
			vrt.setDato(adyacentes.eliminarPrimero());
			if (!vrts.buscar(vrt.getDato())->getInfo().getVisitado()) {
				vrt.setVisitado(true);
				cambiarDato(vrt, vrts);
				buscarBactraking(vrts, adyacentes, vrt);
			}
		}
	}
}

template<class T>
Grafica<T>::~Grafica() {
	md.liberar(MatAdy, MAX);
	delete[] Vertices;
}