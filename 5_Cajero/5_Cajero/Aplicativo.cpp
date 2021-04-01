/*********************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE   *               				     
*  Autores: Kevin Chuquimarca, Marco Iza     *
*  Fecha de creacion: 30/03/2021             *
*  Fecha de modificacion: 31/03/2021         *
*  Cambio de monedas y billetes              *
*********************************************/

#include <iostream>
#include <conio.h>
#include <math.h>

#include "Operacion.h"
#include "Lista.h"

int main()
{
    Operacion op;
    Lista<Registradora> dolares;
    float valor = 0;
    int res = 0;
    do {
        std::cout << "\nCajero";
        std::cout << "\n\nIngrese el valor: ";
        scanf_s("%f", &valor);
        op.cargarLista(dolares);
        op.operarDinero((valor + 0.001) * 100, dolares);
        std::cout << "\n\nPresione [enter] para continuar o [s] para salir: ";
        res = _getche();
    } while (res == 13);
}

