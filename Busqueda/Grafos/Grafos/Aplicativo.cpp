
#include <iostream>

#include "Grafica.h"
#include "Digrafica.h"

int main()
{
    /*Grafica<int> gr;
    gr.Lee();
    gr.Prim();*/
    Digrafica<int> dri;
    dri.Lee();
    dri.Imprime(0);
    dri.buscarAmplitud(1);
}

