#pragma once
class CuboMagico {
public:
	CuboMagico();
	CuboMagico(int**);
	void setCuboMagicoCuadrado(int**);
	int** getCuboMagicoCuadrado();
	void mostrar(int, int);
	void llenar(int, int, int, int);
	void verificar(int, int);
protected:
private:
	int** cuadrado;
};