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
	for (int i = 0; i < 16; i++) 
		list.insertarFinal(*(*(matriz + i) + y));
	girarLista(list);
	for (int i = 0; i < 16; i++) 
		*(*(matriz + i) + y) = list.eliminarPrimero();
}

void Cubo::girarAristaVerticalAbajo(int y) {
	ListaCircular<char> list;
	for (int i = 15; i >= 0; i--) 
		list.insertarFinal(*(*(matriz + i) + y));
	girarLista(list);
	for (int i = 15; i >= 0; i--) 
		*(*(matriz + i) + y) = list.eliminarPrimero();
}

void Cubo::girarAristaHorizontalIzq(int x) {
	ListaCircular<char> list;
	for (int i = 0; i < 12; i++) {
		list.insertarFinal(*(*(matriz + x) + i));
		if (i == 11)
			for (int j = 7; j >= 4; j--) 
				list.insertarFinal(*(*(matriz + 19 - x) + j));
	}
	girarLista(list);
	for (int i = 0; i < 12; i++) {
		*(*(matriz + x) + i) = list.eliminarPrimero();
		if (i == 11)
			for (int j = 7; j >= 4; j--) 
				*(*(matriz + 19 - x) + j) = list.eliminarPrimero();
	}
}

void Cubo::girarAristaHorizontalDer(int x) {
	ListaCircular<char> list;
	for (int i = 11; i >= 0; i--) {
		list.insertarFinal(*(*(matriz + x) + i));
		if(i == 0)
			for (int j = 4; j < 8; j++) 
				list.insertarFinal(*(*(matriz + 19 - x) + j));
	}
	girarLista(list);
	for (int i = 11; i >= 0; i--) {
		*(*(matriz + x) + i) = list.eliminarPrimero();
		if (i == 0)
			for (int j = 4; j < 8; j++) 
				*(*(matriz + 19 - x) + j) = list.eliminarPrimero();
	}
}

void Cubo::girarCircularIzq(int x) {    //cord 0 - 3
	ListaCircular<char> list;
	for (int i = 4; i < 8; i++) 
		list.insertarFinal(*(*(matriz + x) + i));
	for (int i = 4; i < 8; i++) 
		list.insertarFinal(*(*(matriz + i) + 11 - x));
	for (int i = 7; i >= 4; i--) 
		list.insertarFinal(*(*(matriz + 11 - x) + i));
	for (int i = 7; i >= 4; i--) 
		list.insertarFinal(*(*(matriz + i) + x));
	girarLista(list);
	for (int i = 4; i < 8; i++)
		*(*(matriz + x) + i) = list.eliminarPrimero();
	for (int i = 4; i < 8; i++)
		*(*(matriz + i) + 11 - x) = list.eliminarPrimero();
	for (int i = 7; i >= 4; i--)
		*(*(matriz + 11 - x) + i) = list.eliminarPrimero();
	for (int i = 7; i >= 4; i--)
		*(*(matriz + i) + x) = list.eliminarPrimero();
}

void Cubo::girarCircularDer(int x) {
	ListaCircular<char> list;
	for (int i = 7; i >= 4; i--)
		list.insertarFinal(*(*(matriz + x) + i));
	for (int i = 4; i < 8; i++)
		list.insertarFinal(*(*(matriz + i) + x));
	for (int i = 4; i < 8; i++)
		list.insertarFinal(*(*(matriz + 11 - x) + i));
	for (int i = 7; i >= 4; i--)
		list.insertarFinal(*(*(matriz + i) + 11 - x));
	girarLista(list);
	for (int i = 7; i >= 4; i--)
		*(*(matriz + x) + i) = list.eliminarPrimero();
	for (int i = 4; i < 8; i++)
		*(*(matriz + i) + x) = list.eliminarPrimero();
	for (int i = 4; i < 8; i++)
		*(*(matriz + 11 - x) + i) = list.eliminarPrimero();
	for (int i = 7; i >= 4; i--)
		*(*(matriz + i) + 11 - x) = list.eliminarPrimero();
}

void Cubo::opcionesGiros(int op, int cord) {	//cord 4-7
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
	case 5:
		girarCircularIzq(cord);
		break;
	case 6:
		girarCircularDer(cord);
		break;
	}
}

void Cubo::desordenarCubo(int num) {
	std::cout << "\nPor favor espere 10 segundos para desordenar el cubo\n";
	for (int i = 0; i < num; i++) {
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

void Cubo::sexyMove() {
	opcionesGiros(2, 6);	//Rw'
	opcionesGiros(2, 7);
	opcionesGiros(3, 6);	//Dw
	opcionesGiros(3, 7);
	opcionesGiros(1, 6);	//Rw
	opcionesGiros(1, 7);
	opcionesGiros(4, 6);	//Dw'
	opcionesGiros(4, 7);
}

void Cubo::permT() {
	opcionesGiros(1, 6);	//Rw
	opcionesGiros(1, 7);
	opcionesGiros(4, 4);	//U
	opcionesGiros(2, 6);	//Rw'
	opcionesGiros(2, 7);
	opcionesGiros(3, 4);	//U'
	opcionesGiros(2, 6);	//Rw'
	opcionesGiros(2, 7);
	opcionesGiros(5, 3);	//F
	opcionesGiros(1, 6);	//2Rw
	opcionesGiros(1, 7);
	opcionesGiros(1, 6);	
	opcionesGiros(1, 7);
	opcionesGiros(3, 4);	//U'
	opcionesGiros(2, 6);	//Rw'
	opcionesGiros(2, 7);
	opcionesGiros(3, 4);	//U'
	opcionesGiros(1, 6);	//Rw
	opcionesGiros(1, 7);
	opcionesGiros(4, 4);	//U
	opcionesGiros(2, 6);	//Rw'
	opcionesGiros(2, 7);
	opcionesGiros(5, 3);    //F'
}

void Cubo::comCentros() {
	opcionesGiros(1, 6);	//r
	opcionesGiros(3, 4);	//U'
	opcionesGiros(2, 4);	//l'
	opcionesGiros(4, 4);	//U
	opcionesGiros(2, 6);	//r'
	opcionesGiros(3, 4);	//U'
	opcionesGiros(1, 4);	//l
}

void Cubo::solucion(int num) {
	Archivo ach;
	ach.crearArchivo();
	for (int i = 0; i < num; i++) {
		sexyMove();
		permT();
		comCentros();
		ach.escribirArchivo(matriz);
	}
	ach.cerrarArchivo();
}

char** Cubo::getMatriz() {
	return matriz;
}

Cubo::~Cubo() {
	mat.liberar(matriz, 16, 12);
}