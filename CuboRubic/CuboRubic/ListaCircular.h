#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H


#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class ListaCircular {
public:
	ListaCircular();
	~ListaCircular() {		}
	void insertarInicio(T);
	void insertarFinal(T);
	bool listaVacia();
	void imprimir();
	int tamanio();
	Nodo<T>* buscar(int);
	Nodo<T>* getPrimero();
	Nodo<T>* getFinal();
	T eliminarPrimero();
private:
	Nodo<T>* primero;
	Nodo<T>* final;
};

template <class T>
ListaCircular<T>::ListaCircular(){
	this->primero= new Nodo<T>;
	this->final = new Nodo<T>;
	this->primero->setSiguiente(this->primero);
	this->final = this->primero;
}

template <class T>
void ListaCircular<T>::insertarInicio(T d){
	Nodo<T>* aux = new Nodo<T>();
 	aux->setDato(d);
	aux->setSiguiente(this->primero);
	this->final->setSiguiente(aux);
	this->primero = aux;
}

template <class T>
void ListaCircular<T>::insertarFinal(T d){
	if(this->listaVacia()){
		this->insertarInicio(d);
	}else{
		Nodo<T>* aux = this->primero;
		Nodo<T>* aux2 = new Nodo<T>();	
		while(aux!= this->final){
			aux2 = aux;
			aux = aux->getSiguiente();
		}
		Nodo<T>* aux3 = new Nodo<T>(d, aux);
		aux2->setSiguiente(aux3);	
	}
}
	
template <class T>
void ListaCircular<T>::imprimir(){
	Nodo<T>* aux = this->primero;
	int cont = 0;
 	while(aux!= this->final)
 	{
		cont++;
		std::cout << cont << aux->getDato().toString() << std::endl;
 		aux = aux->getSiguiente();
	}
}
template <class T>
bool ListaCircular<T>::listaVacia(){
	if(this->primero->getSiguiente() == this->final){
		return true;
	}else{
		return false;
	}
}

template <class T>
int ListaCircular<T>::tamanio() {
	Nodo<T>* aux = this->primero;
	int cont = 0;
	while (aux != this->final)
	{
		cont++;
		aux = aux->getSiguiente();
	}
	return cont;
}

template <class T>
Nodo<T>* ListaCircular<T>::buscar(int dato) {
	int cont = 1;
	Nodo<T>* aux = new Nodo<T>;
	aux = primero;
	while (aux != final && dato != cont) {
		aux = aux->getAnterior();
		cont++;
	}
	return aux;
}

template <class T>
Nodo<T>* ListaCircular<T>::getPrimero() {
	return primero;
}

template <class T>
Nodo<T>* ListaCircular<T>::getFinal() {
	return final;
}

template <class T>
T ListaCircular<T>::eliminarPrimero()
{
	Nodo<T>* aux;
	T resp = NULL;
	if (primero)
	{
		aux = primero;
		resp = aux->getDato();			
		primero = primero->getSiguiente();
		final->setSiguiente(primero);
		delete (aux);
	}
	else
		resp;
	return resp;
}

#endif
