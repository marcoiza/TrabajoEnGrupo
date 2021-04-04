#pragma once
#include <iostream>

template<class T>
class Vertice
{
private:
	T dato;
	T pariente;
	bool visitado;
public:
	Vertice();
	Vertice(T, T, bool);
	bool getVisitado();
	T getPariente();
	T getDato();
	void setVisitado(bool);
	void setPariente(T);
	void setDato(T);
};

template<class T>
Vertice<T>::Vertice() 
{
	this->dato = NULL;
	this->pariente = NULL;
	this->visitado = false;
}


template<class T>
Vertice<T>::Vertice(T dato, T pariente, bool visitado) 
{
	this->dato = dato;
	this->pariente = pariente;
	this->visitado = visitado;
}

template<class T>
bool Vertice<T>::getVisitado() 
{
	return visitado;
}

template<class T>
T Vertice<T>::getPariente() 
{
	return pariente;
}

template<class T>
T Vertice<T>::getDato() 
{
	return dato;
}

template<class T>
void Vertice<T>::setVisitado(bool visitado) 
{
	this->visitado = visitado;
}

template<class T>
void Vertice<T>::setPariente(T pariente) 
{
	this->pariente = pariente;
}

template<class T>
void Vertice<T>::setDato(T dato) 
{
	this->dato = dato;
}