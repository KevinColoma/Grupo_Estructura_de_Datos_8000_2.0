#include <iostream>
#include <string.h>
#include "CuboMagico.h"
#include <Windows.h>

using namespace std;

int main()
{
	int repetir;
	do {
		system("cls");
		system("color b2");
		int** cuadrado, dim, num;
		int serie, centinela;
		cout << "Ingrese la dimension: ";
		cin >> dim;
		num = 2 * dim - 1;
		cout << num << endl;
		cout << "Ingrese la serie: ";
		cin >> serie;
		cout << "Ingrese el centinela: ";
		cin >> centinela;
		cuadrado = (int**)calloc(num, sizeof(int*));
		system("color e3");
		for (int i = 0; i < num; i++) {
			*(cuadrado + i) = (int*)calloc(num, sizeof(int));
			//cout << *(cuadrado + i) << endl;
		}
		CuboMagico cubo = CuboMagico(cuadrado);
		cubo.llenar(num, num, serie, centinela);
		//cubo.mostrar(num, num);
		cubo.verificar(num, num);
		cout << "\n 0 para salir 1 para continuar: ";
		cin >> repetir;
	   // system("pause");
	} while (repetir != 0);

  
}
