 
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
 
 
  #include "iostream"
 #include "Cproceso.h"
 #include "Cproceso.cpp"
 
 int main (int argc, char *argv) {
  
  Cproceso *obj1=new Cproceso(5,7);
  Cproceso *obj2=new Cproceso(9,11);
  Cproceso *obj3=new Cproceso(0,0);
  
 obj3->racional(*obj1,*obj2);
 
 	obj1->imprimir(*obj1);
    obj2->imprimir(*obj2);
 	obj3->imprimir(*obj3);
  ~Cproceso();// ?
return 0 ; 
}
