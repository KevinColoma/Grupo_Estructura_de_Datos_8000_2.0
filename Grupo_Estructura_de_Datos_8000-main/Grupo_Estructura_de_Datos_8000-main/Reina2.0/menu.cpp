#include "Alfil.cpp"
#include "Reina.cpp"
#include "IngresoDatos.cpp"
#include "Tablero.cpp"
#include "Tablero.h"
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <stdlib.h>
#include <graphics.h>
#include <fstream>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13

int menu(const char *titulo, const char *opciones[], int n);

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void leerLinea(string linea,int x,int y){
	string linea2;
	char *c;
	for(int i=0;i<linea.size();i++){
		linea2=linea[i];
		c= const_cast<char*>(linea2.c_str());
		if(c[0]=='R'){
			//outtextxy(x+(30*i),y,"R");
			readimagefile("queen.jpg",x+(30*i),y,x+30+(30*i),y+30);
		}
		
	}	
}


void escribirReina(string linea,int x,int y){
	ifstream archivo("exaustivo.txt");
	int j=0;
//	while(getline(archivo,linea)){
//		
//		y=y+60;
//	}
    for (int i = 1; getline(archivo, linea); i++) {
    	if (i >= 4 && i <= 11) {
      		leerLinea(linea,x,y+(60*j));
      		j++;
    	}
   } 		
	archivo.close();	
}

void MenuIngreso(){
   bool repite = true;
   int opcion, longitud;   
   std::string op;
   std::string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Reina","Retornar"};
   int n = 2;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				int n;
    			IngresoDatos in;
				n= in.IngresarDatosEntero();
    			std::cout<<'\n';
				Reina *obj=new Reina(n);
				obj->solucionReinas();
    			//obj->mostrarPantalla();
    			//obj->mostrarEnConsola();
				std::cout<<"\nSe creo el archivo txt"<<std::endl;
				initwindow(980,720);
				Tablero t;
				string linea,linea1;
				t.generarTabla(80,140,140,200,8);
				t.pintarTabla(linea1,80,140);
				escribirReina(linea,110,170);	
				//_getch();	
				//system ("pause");
				_getch();
				break;
			}							
			case 2:{
				system("cls");
				std::cout<<std::endl;
				std::cout<<"Regresando..."<<std::endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuPrincipal(){

	bool repite = true;
	int opcion;   
   
    const char *titulo = "****Tablero de Ajedrez (Reina )****";
    const char *opciones[] = {"Tablero","Salir del programa"};
    int n =2;  
 
    do {
        opcion = menu(titulo, opciones, n); 	
		switch(opcion){
			case 1:{
				system("cls");
				MenuIngreso();
				break;
			}				
			case 2:{
				std::cout<<std::endl;
				printf("\n\n\n");
				std::cout<<"Saliendo del programa..."<<std::endl;
				repite=false;
				break;
			}										
	}
	printf("\n\n\n");
	//system("pause");
	_getch();
	}while(repite);
}

int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  
 
   int tecla;
 
   bool repite = true; 
 
   do {
      system("cls");
      //system("Color 8B");
      gotoxy(5, 3 + opcionSeleccionada); std::cout << "->" << std::endl;
 
      
      gotoxy(15, 2); std::cout << titulo;
 
      
      for (int i = 0; i < n; ++i) {
         gotoxy(10, 4 + i); std::cout <<"["<< i + 1 << "] | " << opciones[i];
      }
 
      
 
      do {
         tecla = _getch();
         
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != TECLA_ENTER);
 
      switch (tecla) {
 
         case TECLA_ARRIBA:   
 
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
 
            break;
 
         case TECLA_ABAJO:
            opcionSeleccionada++;
 
            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
 
            break;
 
         case TECLA_ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}