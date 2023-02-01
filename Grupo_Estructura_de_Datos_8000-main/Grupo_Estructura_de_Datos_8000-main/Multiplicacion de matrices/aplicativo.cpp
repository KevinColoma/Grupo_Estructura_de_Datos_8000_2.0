#include "Matrices.cpp" 

int main(){
	
	Matrices<int> matriz;
	
	char datoEntero1[30],datoEntero2[30],datoEntero3[30],datoEntero4[30], *datoFlotante, *datoReal;
	int valorEntero1=0, valorEntero2=0, valorEntero3=0, valorEntero4=0;
	double valorReal=0.d;
	
	strcpy(datoEntero1,ingresarDatosEnteros("Escriba el numero de filas para A: "));
	valorEntero1=atoi(datoEntero1);
	matriz.setFa(valorEntero1);
	
	strcpy(datoEntero2,ingresarDatosEnteros("\nEscriba el numero de columnas para A: "));
	valorEntero2=atoi(datoEntero2);
	matriz.setCa(valorEntero2);
		
	strcpy(datoEntero3,ingresarDatosEnteros("\nEscriba el numero de filas para B: "));
	valorEntero3=atoi(datoEntero3);
	matriz.setFb(valorEntero3);
	
	strcpy(datoEntero4,ingresarDatosEnteros("\nEscriba el numero de columnas para B: "));
	valorEntero4=atoi(datoEntero4);
	matriz.setCb(valorEntero4);
	
	matriz.encerarMatriz();
	
	
	if(matriz.getCa()==matriz.getFb()){	
	
		int i,j,k;
		matriz.llenarMatrizA();
		
		
		matriz.llenarMatrizB();
		
		//Realizamos el calculo
	
	//	matriz.multiplicacionMatrices(matriz.getMat1(),matriz.getMat2(),matriz.getMatR());
		matriz.multiplicacionRecursivaMatrizA(matriz.getMat1(),matriz.getMat2(),matriz.getMatR(),i);
		cout<<endl;                                                            
		//imprimimos la matriz resultante
		
		matriz.imprimirMatriz(matriz.getMatR(),"R");
		free(matriz.getMat1());
		free(matriz.getMat2());
		free(matriz.getMatR());
	}else{
	cout<<"\nLa multiplicacion entre estas dimensiones de matrices no se pueden realizar"<<endl;
	}
	return 0;
}