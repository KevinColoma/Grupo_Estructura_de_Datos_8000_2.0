#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <time.h>
#include "Torre.h"


void Torre::movimientosTorre(int random,int y){
	int x=random%8;
	setcolor(10);
	recursivaTorreIzquierda(x,y);
	recursivaTorreDerecha(x,y);
	recursivaTorreArriba(x,y);
	recursivaTorreAbajo(x,y);
}

bool Torre::recursivaTorreIzquierda(int random,int y){
	if(random==0){
		outtextxy(110,170+(60*y),"T");
		return true;
	}else{
		outtextxy(110+(60*random),170+(60*y),"T");
		return recursivaTorreIzquierda(random-1,y);
	}
}

bool Torre::recursivaTorreDerecha(int random,int y){
	if(random==7){
		outtextxy(530,170+(60*y),"T");
		return true;
	}else{
		outtextxy(110+(60*random),170+(60*y),"T");
		return recursivaTorreDerecha(random+1,y);
	}
}

bool Torre::recursivaTorreAbajo(int random,int y){
	if(y==7){
		outtextxy(110+(60*random),590,"T");
		return true;
	}else{
		outtextxy(110+(60*random),170+(60*y),"T");
		return recursivaTorreAbajo(random,y+1);
	}
}

bool Torre::recursivaTorreArriba(int random,int y){
	if(y==0){
		outtextxy(110+(60*random),170,"T");
		return true;
	}else{
		outtextxy(110+(60*random),170+(60*y),"T");
		return recursivaTorreArriba(random,y-1);
	}
}