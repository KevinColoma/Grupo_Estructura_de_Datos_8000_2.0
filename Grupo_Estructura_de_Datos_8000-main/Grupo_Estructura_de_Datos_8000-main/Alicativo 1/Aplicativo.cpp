#include <iostream>
#include"Cproceso.cpp"
int main(int argc, int ** argv){
	Cproceso *obj1=new Cproceso(5,7);
	Cproceso *obj2=new Cproceso(9,11);
	Cproceso *obj3=new Cproceso(0,0);
	obj3->racional(*obj1,*obj2);
	obj1->imprimirObj(*obj1);
	obj2->imprimirObj(*obj2);
	obj3->imprimirObj(*obj3);
	return 0;
}