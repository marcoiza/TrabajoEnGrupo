#pragma once

#include <iostream>

#include "Lista.h"

#define MAX 10


template <class T>
class Digrafica
{
private:
	T MatAdy[MAX][MAX];
	int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX];
	int VerInt[MAX][MAX]; 
public:
	Digrafica();
	void Lee();
	void Imprime(int);
	void Warshall();
	void Floyd();
	void FloydVerInt();
	void Dijkstra();
	int BuscaVertice(T);
	Lista<T>VerticesAdyacentes(int);
	int buscarAmplitud();
	int buscarProfundo(int);
};

template <class T>
Digrafica<T>::Digrafica()
{
	int Ind1, Ind2;
	for (Ind1 = 0; Ind1 < MAX; Ind1++)
	{
		DistMin[Ind1] = 0;
		for (Ind2 = 0; Ind2 < MAX; Ind2++)
		{
			if (Ind1 != Ind2)
				MatAdy[Ind1][Ind2] = 999;
			else
				MatAdy[Ind1][Ind2] = 0;
			CerTran[Ind1][Ind2] = 0;
			VerInt[Ind1][Ind2] = 0;
		}
	}
	NumVer = 0;
}


template <class T>
void Digrafica<T>::Lee()
{
	int NumArcos, Indice, Origen, Destino;
	std::cout << "\n\n Ingrese número de vértices de la gráfica dirigida : ";
	std::cin >> NumVer;
	std::cout << "\n\n Ingrese los nombres de los vértices de la gráfica dirigida : ";
		for (Indice = 0; Indice < NumVer; Indice++) 
			std::cin >> Vertices[Indice];
	std::cout << "\n\n Total de aristas de la gráfica dirigida : ";
	std::cin >> NumArcos;
	Indice = 0;
	while (Indice < NumArcos)
	{
		std::cout << "\n\n Ingrese vértice origen : ";
		std::cin >> Origen;
		std::cout << "\n\n Ingrese vértice destino : ";
		std::cin >> Destino;
		std::cout << "\n\n Distancia de origen a destino : ";
		std::cin >> MatAdy[Origen - 1][Destino - 1];
		Indice++;
	}
}

template <class T>
void Digrafica<T>::Imprime(int Opc)
{
	int Ind1, Ind2;
	switch (Opc)
	{

	case 0: 
		std::cout << "\n\n Matriz de Adyacencia o de Costos : \n\n";
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			std::cout << Vertices[Ind1] << ": ";
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << MatAdy[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 1: 
		std::cout << "\n\n Cerradura Transitiva de la Matriz de Adyacencia : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			std::cout << Vertices[Ind1] << ": ";
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << CerTran[Ind1][Ind2] << "\t";
				std::cout << std::endl;
		}
		break;
	case 2: 
		std::cout << "\n\n Matriz de Distancias Mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			std::cout << Vertices[Ind1] << ": ";
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << MatAdy[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 3: 
		std::cout << "\n\n Vértices Intermedios para lograr distancias mínimas : " << std::endl;
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
		{
			for (Ind2 = 0; Ind2 < NumVer; Ind2++)
				std::cout << VerInt[Ind1][Ind2] << "\t";
			std::cout << std::endl;
		}
		break;
	case 4: 
		std::cout << "\n\n Distancias mínimas a partir del vértice : " << Vertices[0] << "\n\n";
		for (Ind1 = 0; Ind1 < NumVer; Ind1++)
			std::cout << " " << DistMin[Ind1] << "\t" << std::endl;
		break;
	default: break;
	}
	std::cout << std::endl;
}

template <class T>
void Digrafica<T>::Warshall()
{

}

template <class T>
void Digrafica<T>::Floyd()
{

}


template <class T>
void Digrafica<T>::FloydVerInt()
{

}


template <class T>
void Digrafica<T>::Dijkstra()
{

}

template <class T>
int Digrafica<T>::BuscaVertice(T VertiDato)
{ 
	int Indice = 0, Resp = -1;
	while (Indice < NumVer && Vertices[Indice] != VertiDato)
		Indice++;
	if (Indice < NumVer)
		Resp = Indice;
	return Resp;
}

template <class T>
Lista<T> Digrafica<T>::VerticesAdyacentes(int VertiDato)
{
	int Indice;
	Lista<T> Adyacentes;
	for (Indice = 0; Indice < NumVer; Indice++)
		if (MatAdy[VertiDato][Indice] != 0)
			Adyacentes.insertaFinal(Vertices[Indice]);
	return Adyacentes;
}

template <class T>
int Digrafica<T>::buscarProfundo(int NivelProf)
{
	int Indice, VisitaAux[MAX], Resp = 1, EstadoFinal = 0;
	Lista<T> Visitado, NoVisitado, ListaAux;
	T VertiX;
	for (Indice = 0; Indice < NumVer; Indice++)
		VisitaAux[Indice] = 0;
	NoVisitado.insertaFinal(Vertices[0]);
	VisitaAux[0] = 1;
	Indice = 0;
	while (!NoVisitado.listaVacia() && !EstadoFinal)
	{
		VertiX = NoVisitado.eliminar();
		if (!Visitado.BuscaDesordenada(VertiX) && Indice < NivelProf)
		{
			Visitado.insertaFinal(VertiX);
			ListaAux = VerticesAdyacentes(BuscaVertice(VertiX));
			while (!ListaAux.listaVacia() && !EstadoFinal)
			{
				VertiX = ListaAux.eliminar();
				if (BuscaVertice(VertiX) != NumVer-1 && !VisitaAux[BuscaVertice(VertiX)])
				{
					NoVisitado.insertaInicio(VertiX);
					VisitaAux[BuscaVertice(VertiX)] = 1;
				}
				else
					if (BuscaVertice(VertiX) == NumVer-1)
					{
					Visitado.insertaFinal(VertiX);
					EstadoFinal = 1;
					}
			}
			Indice++;
		}
	}
	if (EstadoFinal)
		Visitado.imprimir();
	else
		Resp = 0;
	return Resp;
}

template <class T>
int Digrafica<T>::buscarAmplitud()
{
	int Indice, EstadoFinal = 0, VisitaAux[MAX], Resp = 1;
	Lista<T> NoVisitado, Visitado, ListaAux;
	T VertiX;
	for (Indice = 0; Indice < NumVer; Indice++)
		VisitaAux[Indice] = 0;
	NoVisitado.insertaFinal(Vertices[0]);
	VisitaAux[0] = 1;
	while (!NoVisitado.listaVacia() && !EstadoFinal)		//cambios
	{
		VertiX = NoVisitado.eliminar();			//implementar
		if (!Visitado.BuscaDesordenada(VertiX))
		{
			Visitado.insertaFinal(VertiX);
			ListaAux = VerticesAdyacentes(BuscaVertice(VertiX));
			while (!ListaAux.listaVacia() && !EstadoFinal)
			{
				VertiX = ListaAux.eliminar();		//implementar
				if (BuscaVertice(VertiX) != NumVer-1 && !VisitaAux[BuscaVertice(VertiX)])
				{
					NoVisitado.insertaFinal(VertiX);
					VisitaAux[BuscaVertice(VertiX)] = 1;
				}
				else
					if (BuscaVertice(VertiX) == NumVer - 1)
					{
						Visitado.insertaFinal(VertiX);
						EstadoFinal = 1;
					}
			}
		}
	}
	if (EstadoFinal)
	{
		std::cout << "No visitado\n";
		NoVisitado.imprimir();
		std::cout << "Visitado\n";
		Visitado.imprimir();
		return 1;
	}
	else
		Resp = 0;
	return Resp;
}