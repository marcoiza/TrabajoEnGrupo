#pragma once
#include <iostream>
#include <string>

class Ingreso {
public:
	int ingresoInt(std::string, int, int);
};

int Ingreso::ingresoInt(std::string mensaje, int minimo, int maximo) {
	int numero;
	std::cout << mensaje;
	std::cin >> numero;
	while (numero < minimo || numero > maximo)
	{
		std::cout << "El valor ingresado no pertenece al rango permitido" << std::endl;
		std::cout << "Intentelo nuevamente: ";
		std::cin >> numero;
	}
	return numero;
}