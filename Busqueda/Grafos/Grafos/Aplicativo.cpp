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
    Digrafica<int> dri;
    dri.insertar();
    dri.imprimirGrafica(0);
    std::cout << "\nRecorrido en Amplitud\n";
    dri.buscarAmplitud(2);
    std::cout << "\nRecorrido en Profundidad\n";
    dri.buscarProfundidad(2);
}

