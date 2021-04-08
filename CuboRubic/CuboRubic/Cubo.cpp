#include "Cubo.h"

Cubo::Cubo() {
	matriz = mat.reservarM(matriz, 16, 12);
	mat.encerar(matriz, 16, 12);
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 12; j++) {
			*(*(matriz + i) + j) = ' ';
			if ((i >= 0 && i <= 3) && (j >= 4 && j <= 7))
				*(*(matriz + i) + j) = 'G';
			if ((i >= 4 && i <= 7) && (j >= 4 && j <= 7))
				*(*(matriz + i) + j) = 'R';
			if ((i >= 8 && i <= 11) && (j >= 4 && j <= 7))
				*(*(matriz + i) + j) = 'B';
			if ((i >= 12 && i <= 15) && (j >= 4 && j <= 7))
				*(*(matriz + i) + j) = 'O';
			if ((i >= 4 && i <= 7) && (j >= 0 && j <= 3))
				*(*(matriz + i) + j) = 'Y';
			if ((i >= 4 && i <= 7) && (j >= 8 && j <= 11))
				*(*(matriz + i) + j) = 'W';
		}
	}
}

void Cubo::girarLista(ListaCircular<char>& list) {
	ListaCircular<char> listAux;
	Nodo<char> *aux = list.getPrimero();
	for (int i = 0; i < 4; i++) {
		list.insertarFinal(aux->getDato());
		aux = aux->getSiguiente();
		list.eliminarPrimero();
	}
}

void Cubo::girarAristaVerticalArriba(int y) {
	ListaCircular<char> list;
	for (int i = 0; i < 16; i++) {
		list.insertarFinal(*(*(matriz + i) + y));
	}
	girarLista(list);
	for (int i = 0; i < 16; i++) {
		*(*(matriz + i) + y) = list.eliminarPrimero();
	}
}

void Cubo::girarAristaVerticalAbajo(int y) {
	ListaCircular<char> list;
	for (int i = 15; i >= 0; i--) {
		list.insertarFinal(*(*(matriz + i) + y));
	}
	girarLista(list);
	for (int i = 15; i >= 0; i--) {
		*(*(matriz + i) + y) = list.eliminarPrimero();
	}
}

void Cubo::girarAristaHorizontalDer(int x) {
	ListaCircular<char> list;
	for (int i = 0; i < 12; i++) {
		list.insertarFinal(*(*(matriz + x) + i));
	}
	girarLista(list);
	for (int i = 0; i < 12; i++) {
		*(*(matriz + x) + i) = list.eliminarPrimero();
	}
}

void Cubo::girarAristaHorizontalIzq(int x) {
	ListaCircular<char> list;
	for (int i = 11; i >= 0; i--) {
		list.insertarFinal(*(*(matriz + x) + i));
	}
	girarLista(list);
	for (int i = 11; i >= 0; i--) {
		*(*(matriz + x) + i) = list.eliminarPrimero();
	}
}

void Cubo::opcionesGiros(int op, int cord) {	//cord>3 y cord<8
	switch (op) {
	case 1:
		girarAristaVerticalArriba(cord);
		break;
	case 2:
		girarAristaVerticalAbajo(cord);
		break;
	case 3:
		girarAristaHorizontalDer(cord);
		break;
	case 4:
		girarAristaHorizontalIzq(cord);
		break;
	}
}

void Cubo::desarmarCubo() {
	std::cout << "\nPor favor espere 15 segundos para desarmar el cubo\n";
	for (int i = 0; i < 20; i++) {
		opcionesGiros(aleatorio(4,1), aleatorio(7, 4));
		Sleep(700);
	}
}

int Cubo::aleatorio(int valf, int vali) {
	int aux = 0;
	if (valf == 0) {
		valf = 1;
	}
	srand(time(NULL));
	aux = (rand() % valf) + vali;
	if (aux < vali) {
		return aux * 2;
	}
	else if(aux > valf){
		return aux / 2;
	}
	return aux;
}

char** Cubo::getMatriz() {
	return matriz;
}

Cubo::~Cubo() {
	mat.liberar(matriz, 16, 12);
}