#pragma once

#include "VentanaGrafo.h"

#include <string>

class IngresoDeDatos {
public:
	static bool validarTXB(System::String^ a) {
		std::string aux = convertTostring(a);
		if (aux > "0" && aux <= "9") 
			return true;
		return false;
	}

	static int convertToInt(System::String^ a) {
		std::string aux;
		for (int i = 0; i < a->Length; i++) 
			aux += a[i];
		return stoi(aux);
	}

	static std::string convertTostring(System::String^ a) {
		std::string aux;
		for (int i = 0; i < a->Length; i++) 
			aux += a[i];
		return aux;
	}

	static System::String^ convertToString(std::string a) {
		System::String^ aux;
		for (int i = 0; i < a.length(); i++) 
			aux += a[i] - 47;
		return aux;
	}
};
