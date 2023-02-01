#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Validacion.h"

//Función ingreso de datos con char

char *ingresarDatos(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

//Ingreso de datos con flotantes
char *ingresarDatosReales(char const *msj){
	char *dato=new char[10],c;
	int i=0, punto=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
		else if(c=='8' && c=='127'){
			printf(" \b");
			dato[i--]=0;
			i--;
		}
		else if(c=='.' && punto==0){
			printf("%c",c);
			dato[i++]=c;
			punto--;
		}
	}
	dato[i]='\0';
	return dato;
}

float ingresar_DatosReales()
{
	char *dato=new char[10],c;
	int i=0, punto=0;
	printf("Seleccione una opcion: ");
	while((c=_getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
		else if(c=='.' && punto==0){
			printf("%c",c);
			dato[i++]=c;
			punto--;
		}
	}
	dato[i]='\0';
	return atof(dato);
}


//Ingreso de datos con enteros

char* ingresarDatosEnteros(char *msj){
	char *dato=new char[10],c;
	int i=0;
	printf("%s ",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return dato;
}

int ingresar_DatosEnteros()
{
	char *dato=new char[10],c;
	int i=0;
	printf("Seleccione una opcion: ");
	while((c=_getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
	return atoi(dato);
}