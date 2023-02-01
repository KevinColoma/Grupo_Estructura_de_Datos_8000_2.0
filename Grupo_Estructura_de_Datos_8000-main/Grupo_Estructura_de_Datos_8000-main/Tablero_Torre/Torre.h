#pragma once

class Torre{
	
	private:
		int pos;
	public:
		int posicionarTorre(int);
		void movimientosTorre(int,int);
		bool recursivaTorreIzquierda(int,int);
		bool recursivaTorreDerecha(int,int);
	 	bool recursivaTorreArriba(int,int);
	 	bool recursivaTorreAbajo(int,int);
	
};