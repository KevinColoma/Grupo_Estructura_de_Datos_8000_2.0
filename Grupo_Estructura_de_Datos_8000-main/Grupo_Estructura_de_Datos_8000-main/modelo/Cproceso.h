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

#if !defined(__Class_Diagram_2_Cproceso_h)
#define __Class_Diagram_2_Cproceso_h
#include <iostream>
#include <Interface_1.h>
using namespace std;
class Cproceso : public Interface_1
{
public:
   int getNum(void);
   void setNum(int newNum);
   int getDen(void);
   void setDen(int newDen);
   Cproceso(int nume, int deno);
   ~Cproceso();

protected:
private:
   int num;
   int den;
void Cproceso::racional(Cproceso obj1,Cproceso obj2){

int a,b,c,d;
a=obj1.getNum();
b=obj1.getDen();

c=obj2.getNum();
d=obj2.getDen();
this -> setNum((a*d)+(b*c));
this -> setDen(b*d);
	return *this;
	
}

void imprimir(Cproceso obj){
	cout<< obj.getNum()<<"/"<<obj.getDen()<< endl;
	}
};

#endif