
#include <iostream>

#include "Cubo.h"
#include "Matriz.h"

int main()
{
    Cubo cb;
    Matriz<char> md;
    md.imprimir(cb.getMatriz(), 16, 12);
    //cb.desordenarCubo(10);
    std::cout << std::endl;
    //md.imprimir(cb.getMatriz(), 16, 12);
    //cb.sexyMove();
    cb.opcionesGiros(5, 2);
    std::cout << std::endl;
    md.imprimir(cb.getMatriz(), 16, 12);
    return 0;
}
