#pragma once

#include <Windows.h>
#include <ctime>

#include "Matriz.h"
#include "ListaCircular.h"

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
	void opcionesGiros(int, int);
	int aleatorio(int, int);
	void desarmarCubo();
	char** getMatriz();
	~Cubo();
};

