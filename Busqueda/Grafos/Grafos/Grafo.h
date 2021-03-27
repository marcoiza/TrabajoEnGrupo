#pragma once
#include <iostream>

#include "Lista.h"
#include "Vertice.h"
#include "Vector.h"
#include "MDinamicaNew.h"

template<class T>
class Grafo
{
private:
	T** MatAdy;
	int NumVer, * Vertices;
	MDinamicaNew md;
	Vector<T> vec;
public:
	Grafo();
	void insertar();
	void reservarMemoria();
	void Imprime();

	int buscaVertice(T);
	Lista<T>verticesAdyacentes(int);
	void buscarAmplitud(T);
	void cambiarDato(Vertice<T>, Lista<Vertice<T>>&);
	void iniciarListaVertice(Lista<Vertice<T>>&);
	void buscarProfundidad(int);
	void buscarBactraking(Lista<Vertice<T>>&, Lista<T>, Vertice<T>);
	void imprimirListaParientes(Lista<Vertice<T>>);
	~Grafo();
};

