#pragma once
class Registradora
{
private: 
	int monto;
	bool llave;
public:
	Registradora();
	Registradora(int, bool );
	int getMonto();
	bool getLlave();
	void setLlave(bool);
};

