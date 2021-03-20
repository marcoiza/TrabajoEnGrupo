/*********************************************
*  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE   *
*  Sudoku               				     *
*  Autores: Kevin Chuquimarca, Marco Iza     *
*  Fecha de creacion: 19/03/2021             *
*  Fecha de modificacion: 19/03/2021         *
*  Resolución de tablero de sudoku           *
*********************************************/

#include <iostream>
#include "JuegoSudoku.h"
#include "Matriz.h"

int main()
{
	int** mat=NULL;
	int dim = 9;
	Matriz<int> matriz;
	mat = matriz.inicializarMatriz(mat, dim);
	JuegoSudoku <int> jugar;
	jugar.resolverSudoku(mat, 0, 0, dim, 1);
	system("pause");
	return 0;
}
