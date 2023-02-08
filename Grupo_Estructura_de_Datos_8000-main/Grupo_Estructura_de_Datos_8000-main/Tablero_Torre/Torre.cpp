#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <time.h>
#include "Torre.h"
#define TAM 60

void Torre::movimientosTorre(int random,int y){
	int x=random%8;
	setcolor(4);
	recursivaTorreIzquierda(x,y);
	recursivaTorreDerecha(x,y);
	recursivaTorreArriba(x,y);
	recursivaTorreAbajo(x,y);
}

bool Torre::recursivaTorreIzquierda(int random,int y){
	if(random==0){
		//outtextxy(110,170+(TAM*y),"T");
		//imprimirTorre(110,170+(TAM*y));
		readimagefile("chess.jpg",100,160+(TAM*y),120,180+(TAM*y));
		return true;
	}else{
		//outtextxy(110+(TAM*random),170+(TAM*y),"T");
		//imprimirTorre(110+(TAM*random),170+(TAM*y));
		readimagefile("chess.jpg",100+(TAM*random),160+(TAM*y),120+(TAM*random),180+(TAM*y));
		return recursivaTorreIzquierda(random-1,y);
	}
}

bool Torre::recursivaTorreDerecha(int random,int y){
	if(random==7){
		//outtextxy(530,170+(TAM*y),"T");
		//imprimirTorre(530,170+(TAM*y));
		readimagefile("chess.jpg",520,160+(TAM*y),540,180+(TAM*y));
		return true;
	}else{
		//outtextxy(110+(TAM*random),170+(TAM*y),"T");
		//imprimirTorre(110+(TAM*random),170+(TAM*y));
		readimagefile("chess.jpg",100+(TAM*random),160+(TAM*y),120+(TAM*random),180+(TAM*y));
		return recursivaTorreDerecha(random+1,y);
	}
}

bool Torre::recursivaTorreAbajo(int random,int y){
	if(y==7){
		//outtextxy(110+(TAM*random),590,"T");
		//imprimirTorre(110+(TAM*random),590);
		readimagefile("chess.jpg",100+(TAM*random),580,120+(TAM*random),600);
		return true;
	}else{
		//outtextxy(110+(TAM*random),170+(TAM*y),"T");
		//imprimirTorre(110+(TAM*random),170+(TAM*y));
		readimagefile("chess.jpg",100+(TAM*random),160+(TAM*y),120+(TAM*random),180+(TAM*y));
		return recursivaTorreAbajo(random,y+1);
	}
}

bool Torre::recursivaTorreArriba(int random,int y){
	if(y==0){
		//outtextxy(110+(TAM*random),170,"T");
		//imprimirTorre(110+(TAM*random),170);
		readimagefile("chess.jpg",100+(TAM*random),160,120+(TAM*random),180);
		return true;
	}else{
		//outtextxy(110+(TAM*random),170+(TAM*y),"T");
		readimagefile("chess.jpg",100+(TAM*random),160+(TAM*y),120+(TAM*random),180+(TAM*y));
		return recursivaTorreArriba(random,y-1);
	}
}

void Torre::imprimirTorre(int x,int y){
	rectangle(x,y,x+10,y+10);
	rectangle(x,y,x+10,y+10);
	line(x-1,y-1,x-6,y-5);//diagonal 1er
	line(x,y-1,x-5,y-5);
	line(x+9,y,x+14,y-5);//diagonal 2da
	line(x+10,y,x+15,y-5);
	line(x-5,y-5,x+15,y-5);//linea diagonal arriba
	line(x-1,y+9,x-6,y+15);//diagonal 3er
	line(x,y+9,x-5,y+15);
	line(x+9,y+10,x+14,y+15);//diagonal 4ta
	line(x+10,y+10,x+15,y+15);
	line(x-5,y+15,x+15,y+15);//linea diagonal abajo
	//parte corona
	line(x-5,y-5,x-5,y-10);//parte izquierda
	line(x-6,y-5,x-6,y-10);
	line(x+14,y-5,x+14,y-10);
	line(x+15,y-5,x+15,y-10);//parte derecha	
	line(x-5,y-10,x-1,y-10);// 1er horizontal izquierda
	line(x+15,y-10,x+11,y-10);//1er horizontal derecha
	line(x-1,y-10,x-1,y-7);// 1er vertical izquierda
	line(x+11,y-10,x+11,y-7);//1er vertical derecha
	line(x-1,y-7,x+3,y-7);// 2da horizontal izquierda
	line(x+11,y-7,x+7,y-7);//2da horizontal derecha
	line(x+3,y-7,x+3,y-10);// 2da vertical izquierda
	line(x+7,y-7,x+7,y-10);// 2da vertical derecha
	line(x+3,y-10,x+7,y-10);//horizontal centro	
}
