#include "Caballo.h"
#include <graphics.h>
#define VAL1 15
#define VAL2 55
#define TAM 60

void Caballo::movimientosCaballo(int random,int y){
	int x=random%8;
	readimagefile("Caballo.jpg",VAL1+(TAM*x),VAL1+(TAM*y),VAL2+(TAM*x),VAL2+(TAM*y));	
	recursivaCaballoVertical(x,y,0);
	recursivaCaballoHorizontal(x,y,0);
}


bool Caballo::recursivaCaballoVertical(int random,int y,int n){
	if(n==2){
		readimagefile("Caballo.jpg",VAL1+(TAM*(random+1)),VAL1+(TAM*y),VAL2+(TAM*(random+1)),VAL2+(TAM*y));
		readimagefile("Caballo.jpg",VAL1+(TAM*(random-1)),VAL1+(TAM*y),VAL2+(TAM*(random-1)),VAL2+(TAM*y));
		readimagefile("Caballo.jpg",VAL1+(TAM*(random+1)),VAL1+(TAM*(y+4)),VAL2+(TAM*(random+1)),VAL2+(TAM*(y+4)));
		readimagefile("Caballo.jpg",VAL1+(TAM*(random-1)),VAL1+(TAM*(y+4)),VAL2+(TAM*(random-1)),VAL2+(TAM*(y+4)));
		return true;
	}else{
		return recursivaCaballoVertical(random,y-1,n+1);
	}
}

bool Caballo::recursivaCaballoHorizontal(int random,int y,int n){
	if(n==2){
		readimagefile("Caballo.jpg",VAL1+(TAM*random),VAL1+(TAM*(y-1)),VAL2+(TAM*random),VAL2+(TAM*(y-1)));
		readimagefile("Caballo.jpg",VAL1+(TAM*random),VAL1+(TAM*(y+1)),VAL2+(TAM*random),VAL2+(TAM*(y+1)));
		readimagefile("Caballo.jpg",VAL1+(TAM*(random+4)),VAL1+(TAM*(y-1)),VAL2+(TAM*(random+4)),VAL2+(TAM*(y-1)));
		readimagefile("Caballo.jpg",VAL1+(TAM*(random+4)),VAL1+(TAM*(y+1)),VAL2+(TAM*(random+4)),VAL2+(TAM*(y+1)));
	}else{
		return recursivaCaballoHorizontal(random-1,y,n+1);
	}
}