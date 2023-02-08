#include "IngresoDatos.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>


int IngresoDatos::IngresarDatosEntero()
{
	std::cout<<"Ingrese el numero de piezas por favor"<<std::endl;
	char *dato=new char[10],c;
	int i=0,n= 0;
	//do{
		while((c=_getch())!=13){
		if(c>='1'&& c<='8'&& n<=1){
			printf("%c",c);
			dato[i++]=c;
			n++;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
			n--;
		}
			}
			dato[i]='\0';
	//}while((c=_getch())==13 || n==0);
		return atoi(dato);
}

