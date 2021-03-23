/*********************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE   *
*  Triangulo de Pascal     				     *
*  Autores: Kevin Chuquimarca, Marco Iza     *
*  Fecha de creacion: 19/03/2021             *
*  Fecha de modificacion: 19/03/2021         *
*  Resolucion del triangulo de Pascal        *
*********************************************/

#include <iostream>
#include "ProcesoPascal.h"

int main()
{
    ProcesoPascal objPascal;
    int numFilas;
    std::cout << "Ingresar el número de filas para el triangulo de Pascal: ";
    std::cin >> numFilas;
    objPascal.dibujarTriangulo(numFilas);
    system("pause");
}

