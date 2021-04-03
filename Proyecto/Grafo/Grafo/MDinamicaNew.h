#ifndef MDINAMICANEW_H_INCLUDED
#define MDINAMICANEW_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

class MDinamicaNew {
	public:
		int** reservar_m(int** mat, int dim);
		void encerar(int** mat, int dim);
		void liberar(int** mat, int dim);
};


#endif