/*****************************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE			 *
*  Autores: Kevin Chuquimarca, Marco Iza			 *
*  Fecha de creacion: 21/03/2021					 *
*  Fecha de modificacion: 4/04/2021					 *
*  Recorrido de graficas en ampliotud y profundidad  *
******************************************************/

#include "VentanaGrafo.h"

using namespace Grafo;

int main() {
	VentanaGrafo^ vGrafo = gcnew VentanaGrafo;
	Application::Run(vGrafo);
	return 0;
}