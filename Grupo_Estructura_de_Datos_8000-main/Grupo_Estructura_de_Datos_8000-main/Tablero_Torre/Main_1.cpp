#include <fstream>
#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <time.h>
#include <random> 
#include "Tablero.h"
#include "Tablero.cpp"
#include "Torre.h"
#include "Torre.cpp"

using namespace std;

int main(){
	initwindow(880,720);
	string linea;
	std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1,64);
    std::uniform_int_distribution<int> distribution2(0,7);
    int random_number1 = distribution(generator);//"Random numero1: "
	int random_number2 = distribution2(generator);//"Random numero2: "
	Tablero t;
	Torre to;
	t.generarTabla(80,140,140,200,8);
	t.pintarTabla(linea,80,140);
	to.movimientosTorre(random_number1,random_number2);
	getch();	
}