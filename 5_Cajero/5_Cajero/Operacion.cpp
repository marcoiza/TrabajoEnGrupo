#include "Operacion.h"

void Operacion::cargarLista(Lista<Registradora>& dolares) {
	dolares.insertaFinal(Registradora(10000, true));
	dolares.insertaFinal(Registradora(5000, true));
	dolares.insertaFinal(Registradora(2000, true));
	dolares.insertaFinal(Registradora(1000, true));
	dolares.insertaFinal(Registradora(500, true));
	dolares.insertaFinal(Registradora(100, true));
	dolares.insertaFinal(Registradora(50, true));
	dolares.insertaFinal(Registradora(25, true));
	dolares.insertaFinal(Registradora(10, true));
	dolares.insertaFinal(Registradora(5, true));
	dolares.insertaFinal(Registradora(1, true));
}

void Operacion::operarDinero(int valor, Lista<Registradora>& dolares) {
	if (valor != 0) {
		if (valor > 99) {
			valor = contar(valor, dolares.regresaPrimero());
		}
		else {
			valor = contar(valor, dolares.buscar(7));
		}
		abrirCerradura(dolares, 20);
		operarDinero(valor, dolares);
	}
}

int Operacion::contar(int valor, NodoLista<Registradora>* nd) {
	int aux = 0, aux2 = 0;
	aux2 = nd->getInfo().getMonto();
	while (nd) {
		if (nd->getInfo().getLlave() && aux2 <= valor) {
			aux = valor % aux2;
			nd->setInfo(Registradora(aux2, false));
			valor = valor - aux;
			printf("\n $ %.2f : %d", (float)aux2/100, valor/aux2);
			return aux;
		}
		nd = nd->getSiguiente();
		aux2 = nd->getInfo().getMonto();
	}
	return valor;
}

void Operacion::abrirCerradura(Lista<Registradora>& dolares, int numCerr){
	for (int i = 0; i < numCerr; i++) 
		dolares.buscar(aleatorio())->getInfo().setLlave(true);
}

int Operacion::aleatorio() {
	srand(time(NULL));
	return rand() % (10) + 1;
}