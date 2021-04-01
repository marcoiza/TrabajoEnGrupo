#pragma once

#include "Lista.h"
#include "Registradora.h"
#include <ctime>

class Operacion
{
public:
	void cargarLista(Lista<Registradora>&);
	void operarDinero(int, Lista<Registradora>&);
	int contar(int, NodoLista<Registradora>*);
	void abrirCerradura(Lista<Registradora>&, int);
	int aleatorio();
};

