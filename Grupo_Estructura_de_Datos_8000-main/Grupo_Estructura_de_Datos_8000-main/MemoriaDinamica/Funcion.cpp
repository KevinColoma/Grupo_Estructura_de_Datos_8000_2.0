#include<iostream>
#include "Funcion.h"
template<typename T>
void funcion <T> ::ingresar(T *p,T t){
    int i=0;
    for(i=0;i<t;i++)
    {
        printf("\nIngrese el valor: ");
        scanf("%d",*(&p)+i);
    }
}

template<typename T>
void funcion <T> ::imprimir(T *p,T t){
    int i;
    for(i=0;i<t;i++)
    {
        printf("\n\nValores ingresados: ");
        printf("%d",*(&(*p)));
        printf("\n");
        *(p++);//navega por la direccion del puntero extrayendo los valores
    }
}

template<typename T>
void funcion <T> ::procesar(T *p,T t){
    int i,e;
    printf("\nIngrese el escalar:");
    scanf("%d",&e);

    for(i=0;i<t;i++)
    {
        *p=(*(&(*p)))*e;
        *(p++);


    }
}