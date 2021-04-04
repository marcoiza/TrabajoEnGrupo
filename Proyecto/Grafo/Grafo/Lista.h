#pragma once
#include <iostream>
#include "NodoLista.h"

template <class T>

class Lista
{
private:
	NodoLista<T>* primero;
public:
	Lista();
	NodoLista<T>* regresaPrimero();
	void imprimir();
	void insertaInicio(T);
	void insertaFinal(T);
	bool eliminaUnNodo(T);
	NodoLista<T>* buscar(int);
	NodoLista<T>* buscaDesordenada(T);
	int tamanio();
	T eliminarUltimo();
	T eliminarPrimero();
	bool listaVacia();
};

template <class T>
Lista<T>::Lista() 
{
	primero = NULL;
}

template <class T>
NodoLista<T>* Lista<T>::regresaPrimero() 
{
	return primero;
}

template <class T>
void Lista<T>::imprimir() 
{
	int cont = 0;
	NodoLista<T>* aux = new NodoLista<T>;
	aux = primero;
	std::cout << "\nDatos de la Lista\n\n";
	while (aux) {
		cont++;
		std::cout << cont << "._  " << aux->getInfo() << std::endl;
		aux = aux->getSiguiente();
	}
}

template <class T>
void Lista<T>::insertaInicio(T dato) 
{
	NodoLista<T>* aux = new NodoLista<T>();
	aux->setInfo(dato);
	aux->setSiguiente(primero);
	primero = aux;
}

template <class T>
void Lista<T>::insertaFinal(T dato) 
{
	NodoLista<T>* aux, * aux2;
	aux = new NodoLista<T>();
	aux->setInfo(dato);
	if (primero) {
		aux2 = primero;
		while (aux2->getSiguiente())
			aux2 = aux2->getSiguiente();
		aux2->setSiguiente(aux);
	}
	else
		primero = aux;
}

template <class T>
bool Lista<T>::eliminaUnNodo(T dato) 
{
	NodoLista<T>* aux, * aux2;
	bool resp = true;
	if (primero) {
		aux = primero;
		while ((aux->getSiguiente()) && (aux->getInfo() != dato)) {
			aux2 = aux;
			aux = aux->getSiguiente();
		}
		if (aux->getInfo != dato)
			resp = 0;
		else {
			if (primero == aux)
				primero = aux->getSiguiente();
			else
				aux2->getSiguiente(aux->getSiguiente());				
			delete (aux);
		}
	}
	else {
		resp = false;
	}
	return resp;
}

template <class T>
NodoLista<T>* Lista<T>::buscar(int dato) 
{
	NodoLista<T>* aux = new NodoLista<T>;
	int cont = 1;
	aux = primero;
	while (aux && cont != dato) {
		aux = aux->getSiguiente();
		cont++;
	}
	return aux;
}

template <class T>
int Lista<T>::tamanio() 
{
	NodoLista<T>* aux = new NodoLista<T>;
	int cont = 0;
	aux = primero;
	while (aux) {
		cont++;
		aux = aux->getSiguiente();
	}
	return cont;
}

template <class T>
T Lista<T>::eliminarPrimero() 
{
	NodoLista<T>* aux;
	int resp = - 1;
	if (primero)
	{
		aux = primero;
		resp = aux->getInfo();			//cambios del metodo 
		primero = primero->getSiguiente();
		delete (aux);
	}
	else
		resp;
	return resp;
}

template <class T>
NodoLista<T>* Lista<T>::buscaDesordenada(T referencia)
{
	NodoLista<T>* aux, * resp = NULL;
	if (primero)
	{
		aux = primero;
		while ((aux->getInfo() != referencia) && (aux->getSiguiente()))
			aux = aux->getSiguiente();
		if (aux->getInfo() == referencia)
			resp = aux;
	}
	return resp;
}

template <class T>
bool Lista<T>::listaVacia() 
{
	if (primero==NULL) {
		return true;
	}
	return false;
}

template <class T>
T Lista<T>::eliminarUltimo()
{
	NodoLista<T>* anterior, * aux;
	int resp = - 1;
	if (primero)
	{
		if (!primero->getSiguiente)
		{
			delete (primero);
			primero = NULL; 
		}
		else
		{
			aux = primero;
			while (aux->getSiguiente())
			{
				anterior = aux;
				resp = aux->getInfo();
				aux = aux->getSiguiente();
			}
			anterior->setSiguiente(NULL);
			delete (aux);
		}
	}
	else
		resp;
	return resp;
}