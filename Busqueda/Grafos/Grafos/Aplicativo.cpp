
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
    dri.buscarAmplitud();
    dri.buscarProfundo(2);
}

