#include <iostream>
#include <string.h>
#include <fstream>
#include "Tablero.h"
#include <graphics.h>
#include <string>
#define TAM 60

using namespace std;

void Tablero::generarTabla(int x1, int y1,int x2,int y2,int cant){
	for(int j=0;j<cant;j++){
		generarFila(x1,y1,x2,y2,cant);	
		y1=y1+TAM;
		y2=y2+TAM;
	}
}

void Tablero::pintarLinea(string linea,int x,int y){
	int num1;
	string linea2;
	for(int i=0;i<linea.size();i++){
		linea2=linea[i];
		num1=stoi(linea2);
		if(num1==0){
			floodfill(x+1,y+1,15);
		}
		x=x+TAM;
	}	
}

void Tablero::generarFila(int x1,int y1,int x2, int y2,int cant){
	for(int i =0; i<cant ;i++){
		rectangle(x1,y1,x2,y2);
		x1=x1+TAM;
		x2=x2+TAM;
	}	
}

void Tablero::pintarTabla(string linea,int x,int y){
	ifstream archivo("Tablero.txt");
	while(getline(archivo,linea)){
		pintarLinea(linea,x,y);
		y=y+TAM;
	}
	archivo.close();	
}
