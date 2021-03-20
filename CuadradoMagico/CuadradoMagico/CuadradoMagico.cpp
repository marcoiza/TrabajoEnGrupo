/*********************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE   *
*  Cuadrado magico               			 *
*  Autores: Kevin Chuquimarca, Marco Iza     *
*  Fecha de creacion: 19/03/2021             *
*  Fecha de modificacion: 19/03/2021         *
*  Resolución del cuadrado magico            *
*********************************************/

#include <iostream>
#include "CuadroMagico.h"
#include "Operaciones.h"

int main()
{
    CuadroMagico cuadro1(4);
    Operaciones operar;
    operar.resolverCuadro(cuadro1);
    system("pause");
}
