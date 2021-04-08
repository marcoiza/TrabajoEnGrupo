#pragma once

#include <Windows.h>
#include <ctime>

#include "Matriz.h"
#include "ListaCircular.h"
#include "Archivo.h"

class Cubo
{
private: 
	char** matriz;
	Matriz<char> mat;
public:
	Cubo();
	void girarLista(ListaCircular<char>&);
	void girarAristaVerticalArriba(int);
	void girarAristaVerticalAbajo(int);
	void girarAristaHorizontalDer(int);
	void girarAristaHorizontalIzq(int);
	void girarCircularDer(int);
	void girarCircularIzq(int);

	void opcionesGiros(int, int);
	int aleatorio(int, int);
	void desordenarCubo(int);

	void sexyMove();
	void permT();			//T permutaciones 
	void comCentros();		//comutador de centros

	void solucion(int);

	char** getMatriz();
	~Cubo();
};

