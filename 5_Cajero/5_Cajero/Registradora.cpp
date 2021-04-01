#include "Registradora.h"

Registradora::Registradora() {
	this->monto = 0;
	this->llave = false;
}

Registradora::Registradora(int monto, bool llave) {
	this->monto = monto;
	this->llave = llave;
}

int Registradora::getMonto() {
	return monto;
}

bool Registradora::getLlave() {
	return llave;
}

void Registradora::setLlave(bool llave) {
	this->llave = llave;
}