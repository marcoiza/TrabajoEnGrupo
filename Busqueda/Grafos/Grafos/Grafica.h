#pragma once

#include <iostream>

#define MAX 20

template <class T>
class Grafica
{
private:
	T MatAdy[MAX][MAX];
	int NumVer, Vertices[MAX];
public:
	Grafica();
	void insertar();
	void Imprime();
	void Prim();
	void Kruskal();
};

template <class T>
Grafica<T>::Grafica()
{
	int Ind1, Ind2;
	for (Ind1 = 0; Ind1 < MAX; Ind1++)
		for (Ind2 = 0; Ind2 < MAX; Ind2++)
			if (Ind1 != Ind2)
				MatAdy[Ind1][Ind2] = 999;
			else
				MatAdy[Ind1][Ind2] = 0;
	NumVer = 0;
}

template <class T>
void Grafica<T>::insertar()
{
	int Aristas, Costo, Ind1, Origen, Destino;
	std::cout << "\n\nIngrese total de vértices de la gráfica : ";
	std::cin >> NumVer;
	for (Ind1 = 0; Ind1 < NumVer; Ind1++)
	{
		std::cout << "\nIngrese el nombre del vértice : ";
		std::cin >> Vertices[Ind1];
	}
	std::cout << "\n\nIngrese total de aristas de la gráfica : ";
	std::cin >> Aristas;
	Ind1 = 0;
	while (Ind1 < Aristas)
	{
		std::cout << "\nVértice origen : ";
		std::cin >> Origen;
		std::cout << "\nVértice destino : ";
		std::cin >> Destino;
		std::cout << "\nCosto de ir de " << Origen << " a " << Destino << " : ";
		std::cin >> Costo;
		MatAdy[Origen - 1][Destino - 1] = Costo;
		MatAdy[Destino - 1][Origen - 1] = Costo;
		Ind1++;
	}
}

template <class T>
void Grafica<T>::Prim()
{
	int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
	for (Ind1 = 0; Ind1 < NumVer; Ind1++)
	{
		MCosto[Ind1] = MatAdy[0][Ind1];
		VerAux[Ind1] = 0;
	}
	std::cout << "\n\n\nArcos y costos del árbol abarcador de costo mínimo\n\n";
	std::cout << "\nVértice Vértice Costo \n";
	for (Ind1 = 0; Ind1 < NumVer - 1; Ind1++)
	{
		MenCos = MCosto[1];
		VerMen = 1;
		for (Ind2 = 2; Ind2 < NumVer; Ind2++)
			if (MCosto[Ind2] < MenCos)
			{
				MenCos = MCosto[Ind2];
				VerMen = Ind2;
			}
				std::cout << "\n " << Vertices[VerMen] << " - " << Vertices[VerAux[VerMen]]
				<< " " << MatAdy[VerMen][VerAux[VerMen]];
			MCosto[VerMen] = 1000;
			for (Ind2 = 1; Ind2 < NumVer; Ind2++)
				if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
				{
					MCosto[Ind2] = MatAdy[VerMen][Ind2];
					VerAux[Ind2] = VerMen;
				}
	}
	std::cout << "\n\n";
}

template <class T>
void Grafica<T>::Kruskal()
{
}