#pragma once
#include <iostream>

using namespace std;

template <class T>
class NodoLista
{
private:
	NodoLista<T>* siguiente;
	T dato;
public:
	NodoLista();
	T regresaInfo();
	NodoLista<T>* getSiguiente();
	T getInfo();
	void setSiguiente(NodoLista<T>*);
	void setInfo(T);
};

template <class T>
NodoLista<T>::NodoLista() {
	siguiente = NULL;
}

template <class T>
T NodoLista<T>::regresaInfo() {
	return dato;
}

template <class T>
NodoLista<T>* NodoLista<T>::getSiguiente() {
	return siguiente;
}

template <class T>
T NodoLista<T>::getInfo() {
	return dato;
}

template <class T>
void NodoLista<T>::setSiguiente(NodoLista<T>* liga) {
	this->siguiente = liga;
}

template <class T>
void NodoLista<T>::setInfo(T info) {
	this->dato = info;
}

