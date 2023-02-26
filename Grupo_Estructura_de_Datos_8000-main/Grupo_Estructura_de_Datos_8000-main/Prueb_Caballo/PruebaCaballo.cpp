#include <graphics.h>
#include <iostream>
#include <random> 
#include "Tablero.cpp"
#include "Caballo.cpp"

using namespace std;


int main(){
	Tablero t;
	string linea;
	Caballo ca;
	int n;
	std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1,64);
    std::uniform_int_distribution<int> distribution2(0,7);	
	initwindow(490,490);
	t.generarTabla(5,5,65,65,8);
	t.pintarTabla(linea,5,5);
    int random_number1 = distribution(generator);//"Random numero1: "
	int random_number2 = distribution2(generator);//"Random numero2: "
	ca.movimientosCaballo(random_number1,random_number2);	
	getch();
	
	return 0;
}
