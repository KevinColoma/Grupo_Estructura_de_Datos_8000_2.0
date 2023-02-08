#pragma once
#include <fstream>

class Tablero{
	public:
		void generarFila(int x1, int y1, int x2, int y2,int cant);
		void generarTabla(int x1, int y1,int x2,int y2,int cant);
		void pintarLinea(std::string linea,int x,int y);
		void pintarTabla(std::string linea,int x,int y);
	

};