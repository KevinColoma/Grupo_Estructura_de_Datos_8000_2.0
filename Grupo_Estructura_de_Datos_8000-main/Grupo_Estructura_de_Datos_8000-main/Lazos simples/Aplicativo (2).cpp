#include <iostream>
#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Lista lst;
	lst.insertar(2);
	lst.insertar(12);
	lst.insertar(22);
	lst.insertar(32);
	lst.insertar(42);
	lst.insertar(52);
	lst.insertar(62);
	lst.insertar(72);
	lst.insertar(82);
	lst.insertar(92);
	lst.mostrarLista();
	return 0;
}