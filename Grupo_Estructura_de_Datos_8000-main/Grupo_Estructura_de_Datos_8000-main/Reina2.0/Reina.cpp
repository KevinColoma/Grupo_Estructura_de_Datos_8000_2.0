#include "Reina.h"
#include "time.h"
void Reina:: encerarTablero(){
			for(int i=0;i<DIMENSION;i++){
				validar[i]=new bool[DIMENSION];
				tablero[i]=new char[DIMENSION];
				for(int j=0;j<DIMENSION;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}

void Reina:: crearArchivo(){
		archivo.open("exaustivo.txt",std::fstream::out);
		archivo<<"solucion"<<DIMENSION<<"*"<<DIMENSION<<std::endl<<std::endl;
		contador=0;
	}

 Reina::Reina(int n1){
		n=n1;
		validar=new bool *[DIMENSION];
		tablero=new char *[DIMENSION];
		encerarTablero();
		crearArchivo();
	}
	
void Reina::bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;
		aux1=0;
		while(aux1<DIMENSION){//vertical
			*(*(validar+aux1)+aux2)=true;
			aux1++;
		}
		aux2=0;
		aux1=x;
		while(aux2<DIMENSION){ //horizontal
			*(*(validar+aux1)+aux2)=true;
			aux2++;
		}
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		while (aux1 < DIMENSION && aux2 < DIMENSION) { //FALTABA
        *(*(validar + aux1) + aux2) = true; //FALTABA
        aux1++; //FALTABA
        aux2++; //FALTABA
    	}
		aux2=y;
		aux1=x;
		while(aux1<DIMENSION && aux2>0){
			aux1++;
			aux2--;
		}
		if (x + y >= DIMENSION) { //FALTABA
            aux1--;
            aux2++;
        } //FALTABA
		while(aux1>=0 && aux2<DIMENSION){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}

void Reina:: mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<std::endl;
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<std::endl;
		}
		archivo<<std::endl;
	}

void Reina:: quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				if(*(*(tablero +i)+j)=='R') 
				bloquear(i,j);
			}	
		}
	}

void Reina::mostrarPantalla(){
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				std::cout<<(*(*(tablero +i)+j))<<" ";
			}
			std::cout<<"\n";
		}
	}


void Reina::mostrarEnConsola(){
	std::ifstream archivoResp;
	std::string texto;
	
	archivoResp.open("exaustivo.txt",std::ios::in);
	
	if(archivoResp.fail()){
		std::cout<<"No se encontro el archivo "<<std::endl;
		exit(1);
	}	
	while(!archivoResp.eof()){
		getline(archivoResp,texto);
		std::cout<<texto<<std::endl;
	}
	
	archivoResp.close();
}

void Reina::solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='R';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}

void Reina::solucionReinas(){
		for(int i=2;i<DIMENSION;i++){ //AQUI ES !!
			for(int j=0;j<DIMENSION;j++){
				solucion(i,j,1);	//AQUI ES !!!
			}
		}
		archivo.close();	
	}


