/*****************************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE			 *
*  Autores: Kevin Chuquimarca, Marco Iza			 *
*  Fecha de creacion: 4/03/2021 					 *
*  Fecha de modificacion: 8/04/2021					 *
*  algoritmos para la resolucion del cubo rubic 4*4  *
******************************************************/

#include <iostream>

#include "Cubo.h"
#include "Matriz.h"

int main()
{
    Cubo cb;
    Matriz<char> md;
    md.imprimir(cb.getMatriz(), 16, 12);
    std::cout << std::endl;
    cb.desordenarCubo(15);
    md.imprimir(cb.getMatriz(), 16, 12);
    std::cout << std::endl;
    cb.solucion(15);
    return 0;
}
