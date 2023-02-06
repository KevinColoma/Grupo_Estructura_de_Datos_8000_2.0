#include "CuboMagico.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;
CuboMagico::CuboMagico(){
}
CuboMagico::CuboMagico( int **_cuadrado){
	cuadrado=_cuadrado;
}
void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
	cuadrado=_cuadrado;
}
int **CuboMagico::getCuboMagicoCuadrado(){
	return cuadrado;
}
void CuboMagico::llenar(int a, int b,int patron){
	
	int x=0,t=0,s=0,d=0,p=patron,k=0,j=0;
	x=(b-1)/2; //2
	t=((a+1)/2); //3
	s=(a-x-1)/2;  //5+2-1 / 2  =3
	d=x;          //2
	for(int g=0;g<((a+1)/2);g++){
		j=g;    //El primer número se coloca en la esquina superior izquierda.   0 1 2 3
		k=g;
		for(int i=x;i>=j;i--){ 
			*(*(cuadrado+i)+k)=p;
			if(k<(d-s)){
				*(*(cuadrado+i)+(k+t))=p;//El siguiente número se coloca en la posición de la fila de abajo y la columna siguiente.
			}
			if(k>(d+s)){
				*(*(cuadrado+i)+(k-t))=p;//Si la siguiente celda está fuera de los límites de la matriz, se coloca en la primera fila y la columna siguiente
			}
			if(i>(d+s)){            
				*(*(cuadrado+(i-t))+k)=p;
			}
			if(i<(d-s)){
				*(*(cuadrado+(i+t))+k)=p; // Si la siguiente celda está ocupada, se coloca en la fila de arriba de la celda actual.
			}
			k++;
			p+=patron;    
		}
		x++;
	}
}
void CuboMagico::mostrar(int a, int b){
	system("cls");
	int x=0,t=0,s=0,z=0,l=0,n=0;
	char buffer[20];
	x=(b-1)/2;
	t=((a+1)/2);
	s=(a-x-1)/2;
	for(int g=0;g<a;g++){
		l=0;
		for(int h=0;h<b;h++){	
			if(h>=(x-s)&&h<=(x+s)&&g<=(x+s)&&g>=(x-s)){
				z=*(*(cuadrado+g)+h);
				itoa(z,buffer,10);
				outtextxy(110+(60*l),(60*n)-28,buffer);
				l++;
			 	 std::chrono::milliseconds duracion(400);
  				  std::this_thread::sleep_for(duracion); 																  
			}
			
		}
		n++;		
	}
}

void CuboMagico::crearArchivo(int a, int b){
	system("cls");
    int x=(b-1)/2;
    int t=((a+1)/2);
    int s=(a-x-1)/2;
    ofstream archivo("cuadrado_magico.txt");
    for(int g=0;g<a;g++){
        archivo<<endl;
        for(int h=0;h<b;h++){
            if(h>=(x-s)&&h<=(x+s)&&g<=(x+s)&&g>=(x-s)) {                 
                archivo << "\t" << *(*(cuadrado + g) + h);
            }
        }
    }
    archivo.close();	
}

