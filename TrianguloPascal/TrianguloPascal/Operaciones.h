#pragma once

class Operaciones {
public:
	int factorial(int);
	int combinacion(int, int);
};

int Operaciones::factorial(int numero) {
    if (numero < 2)
        return 1;
    else
        return numero * factorial(numero - 1);
}

int Operaciones::combinacion(int n, int k) {
    if (k == 1)
        return n;
    else {
        if (n == k)
            return 1;
        else
            return factorial(n) / (factorial(n - k) * factorial(k));
    }
}