/***********************************************************************
 * UFA - ESPE 
 * ALUMNOS:
 *FECHA CREACION:27/10/2022
  * Module:  Interface_1.h
 * Author:  Jefferson Guamani , Kevin Coloma
 * MODIFICACION: 28/10/2022
 * ENUNCIADO DEL PROBLEMA: Declaration of the class Interface_1
 NIVEL:  NRC : 8000
 ***********************************************************************/
#include "Cproceso.h"


int Cproceso::getNum(void)
{
   return num;
}


void Cproceso::setNum(int newNum)
{
   num = newNum;
}

int Cproceso::getDen(void)
{
   return den;
}

void Cproceso::setDen(int newDen)
{
   den = newDen;
}



Cproceso::Cproceso(int nume, int deno)
{
   thins->num=nume;
    thins->den=deno;

}
//delete Cproceso;
Cproceso::~Cproceso()
{
   
}
