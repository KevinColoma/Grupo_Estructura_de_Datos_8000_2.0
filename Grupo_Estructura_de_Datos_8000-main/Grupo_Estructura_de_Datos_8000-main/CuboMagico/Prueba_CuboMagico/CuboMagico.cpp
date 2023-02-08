#include "CuboMagico.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

CuboMagico::CuboMagico() {
}

CuboMagico::CuboMagico(int** _cuadrado) {
	cuadrado = _cuadrado;
}

void CuboMagico::setCuboMagicoCuadrado(int** _cuadrado) {
	cuadrado = _cuadrado;
}

int** CuboMagico::getCuboMagicoCuadrado() {
	return cuadrado;
}

void CuboMagico::llenar(int a, int b, int serie, int centinela) {
	int x = 0, t = 0, s = 0, d = 0, p = centinela, k = 0, j = 0;
	x = (b - 1) / 2;
	t = ((a + 1) / 2);
	s = (a - x - 1) / 2;
	d = x;
	for (int g = 0; g < ((a + 1) / 2); g++) {
		j = g;
		k = g;
		for (int i = x; i >= j; i--) {
			*(*(cuadrado + i) + k) = p;
			if (k < (d - s)) {
				*(*(cuadrado + i) + (k + t)) = p;
			}
			if (k > (d + s)) {
				*(*(cuadrado + i) + (k - t)) = p;
			}
			if (i > (d + s)) {
				*(*(cuadrado + (i - t)) + k) = p;
			}
			if (i < (d - s)) {
				*(*(cuadrado + (i + t)) + k) = p;
			}
			k++;
			//p++;
			p = p + serie;
		}
		x++;
	}
}

void CuboMagico::mostrar(int a, int b) {
	system("cls");
	int x = 0, t = 0, s = 0;
	x = (b - 1) / 2;
	t = ((a + 1) / 2);
	s = (a - x - 1) / 2;
	for (int g = 0; g < a; g++) {
		printf("\n\t");
		for (int h = 0; h < b; h++) {
			if (h >= (x - s) && h <= (x + s) && g <= (x + s) && g >= (x - s)) {
				printf("\t%d", *(*(cuadrado + g) + h));
			}
		}
	}
}

void CuboMagico::verificar(int a, int b) {
	system("cls");
	int x = 0, t = 0, s = 0;
	int* resultado = new int[a];
	x = (b - 1) / 2;
	t = ((a + 1) / 2);
	s = (a - x - 1) / 2;
	cout << "\nVerificar horizontal." << endl;
	for (int g = 0; g < a; g++) {
		printf("\n\t");
		int sum = 0;
		for (int h = 0; h < b; h++) {
			if (h >= (x - s) && h <= (x + s) && g <= (x + s) && g >= (x - s)) {
				cout << "\t" << * (*(cuadrado + g) + h);
				sum = *(*(cuadrado + g) + h) + sum;		
			}
		}
		cout << "\t [" << sum << "]";
	}

	// h = fila y g = columna
	cout << "\nVerificar vertical." << endl;
	for (int g = 0; g < a; g++) {
		printf("\n\t");
		int sum1 = 0;
		for (int h = 0; h < b; h++) {
			if (h >= (x - s) && h <= (x + s) && g <= (x + s) && g >= (x - s)) {
				cout << "\t" << *(*(cuadrado + h) + g);
				sum1 = *(*(cuadrado + h) + g) + sum1;
			}
		}
		cout << "\t [" << sum1 << "]";
	}
}