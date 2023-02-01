#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include"Funcion.cpp"


using namespace std;


int main(){
    int tam=0;
   // int *ptr=new int[10];
   //if(*ptr=realloc(*ptr,sizeof(int))    
    int *ptr=(int*)malloc(4*sizeof(int));

    cout<<"\nIngrese el tamano: ";
    cin>>tam;
    funcion<int> val;
    val.ingresar(ptr,tam);
    val.imprimir(ptr,tam);
    val.procesar(ptr,tam);
    val.imprimir(ptr,tam);  
    getch();
}