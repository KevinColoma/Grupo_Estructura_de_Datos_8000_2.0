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

#if !defined(__Class_Diagram_2_Interface_1_h)
#define __Class_Diagram_2_Interface_1_h

#include <Cproceso.h>

class Interface_1
{
public:
   virtual Cproceso racional(Cproceso numer, Cproceso denom)=0;
   virtual void imprimir(Cproceso obj)=0;

protected:
private:

};

#endif