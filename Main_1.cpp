#include <fstream>
#include <iostream>
#include <graphics.h>
#include "Tablero.h"
#include "Tablero.cpp"
#include <string.h>
using namespace std;

int main(){
	initwindow(980,720);
	string linea;
	Tablero t;
	t.generarTabla(80,140,140,200,8);
	t.pintarTabla(linea,80,140);
	getch();	
}
