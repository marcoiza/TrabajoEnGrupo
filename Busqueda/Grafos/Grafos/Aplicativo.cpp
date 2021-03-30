/*********************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE   *
*  Grafos               				     *
*  Autores: Kevin Chuquimarca, Marco Iza     *
*  Fecha de creacion: 19/03/2021             *
*  Fecha de modificacion: 24/03/2021         *
*  Resolucion del triangulo de Pascal        *
*********************************************/

#include <iostream>

#include "Grafica.h"
#include "Digrafica.h"

int main()
{
    /*Digrafica<int> dri;
    dri.insertar();
    dri.imprimir(0);
    std::cout << "\nBusqueda en Amplitud\n";
    dri.buscarAmplitud(1);
    std::cout << "\nBusqueda en Profundidad\n";
    dri.buscarProfundidad(1);*/
    Grafica<int> ndri;
    ndri.insertar();
    ndri.imprimir();
    int aux = 0;
    do{
        std::cout << "\nIngrese el vertice: ";
        std::cin >> aux;
        std::cout << "\nBusqueda en Amplitud\n";
        ndri.buscarAmplitud(aux);
        std::cout << "\nBusqueda en Profundidad\n";
        ndri.buscarProfundidad(aux);
    } while (aux != 10);
}

