#pragma once
#include <iostream>
#include "Operaciones.h"

class ProcesoPascal {
public:
	void dibujarTriangulo(int);
};

void ProcesoPascal::dibujarTriangulo(int filas) {
    Operaciones objOpera;
    for (int i = 0; i <= filas; i++) {
        for (int j = 0; j <= i; j++)
            std::cout << objOpera.combinacion(i, j) << "  ";
        std::cout << std::endl;
    }
}