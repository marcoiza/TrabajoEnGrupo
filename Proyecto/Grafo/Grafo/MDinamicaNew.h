#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

class MDinamicaNew 
{
public:
	int** reservarM(int**, int);
	void encerar(int**, int);
	void liberar(int**, int);
};