/***********************************************************************
 * Module:  Cproceso.h
 * Author:  Fernando Solis
 * Modified: miércoles, 26 de octubre de 2022 11:12:05
 * Purpose: Declaration of the class Cproceso
 ***********************************************************************/
#if !defined(__Class_Diagram_2_Cproceso_h)
#define __Class_Diagram_2_Cproceso_h
class Cproceso
{
public:
   int getNum(void);
   void setNum(int newNum);
   int getDen(void);
   void setDen(int newDen);
   Cproceso(int nume, int deno);
   ~Cproceso();
   Cproceso racional(Cproceso numer, Cproceso denom);
   void imprimirObj(Cproceso obj);
protected:
private:
   int num;
   int den;
};

#endif