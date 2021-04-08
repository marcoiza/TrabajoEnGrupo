
#include <iostream>

#include "Cubo.h"
#include "Matriz.h"

int main()
{
    Cubo cb;
    Matriz<char> md;
    md.imprimir(cb.getMatriz(), 16, 12);
    cb.desarmarCubo();
    std::cout << std::endl;
    md.imprimir(cb.getMatriz(), 16, 12);
    /*for (int i = 0; i < 10; i++) {
        std::cout<<cb.aleatorio(4, 1) <<"\t" << cb.aleatorio(7, 4)<<std::endl;
        Sleep(700);
    }*/
    return 0;
}
