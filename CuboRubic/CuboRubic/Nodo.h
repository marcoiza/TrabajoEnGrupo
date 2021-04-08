#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;
template <class T>
class Nodo{
public:
	Nodo();
	Nodo(T d, Nodo* n);
	Nodo(T d, Nodo* n, Nodo* p);
	~Nodo();
	void setDato(T d);
	void setSiguiente(Nodo* n);
	void setAnterior(Nodo* p);
	T getDato();
	Nodo* getSiguiente();
	Nodo* getAnterior();
private:
	T dato;
	Nodo* siguiente;	
	Nodo* anterior;
};

template<class T>
Nodo<T>::Nodo() {this->siguiente = NULL;}

template<class T>
Nodo<T>::Nodo(T d, Nodo* n) {
	this->dato = d;
	this->siguiente = n;
}

template<class T>
Nodo<T>::Nodo(T d, Nodo* n, Nodo* p) {
	this->dato = d;
	this->siguiente = n;
	this->anterior = p;
}

template<class T>
Nodo<T>::~Nodo() {}

template<class T>
void Nodo<T>::setDato(T d)
{ 
	this->dato = d; 
}

template<class T>
void Nodo<T>::setSiguiente(Nodo* n)
{ 
	this->siguiente = n; 
}

template<class T>
void Nodo<T>::setAnterior(Nodo* p)
{ 
	this->anterior = p; 
}

template<class T>
T Nodo<T>::getDato() 
{ 
	return this->dato; 
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() 
{ 
	return this->siguiente; 
}

template<class T>
Nodo<T>* Nodo<T>::getAnterior() 
{ 
	return this->anterior; 
}

#endif
