#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
		bool listaVacia(){
			return (this->primero==NULL);
		}
	public:
		Lista(){
			this->primero=NULL;
			this->actual=NULL;
		}
	void insertar(int val){
		Nodo *nuevo=new Nodo(val);
		if(listaVacia()){
			this->primero=nuevo;
		}
		else{
			this->actual->siguiente=nuevo;
		}
		this->actual=nuevo;
	}

	
	void mostrarLista(){
		Nodo *ptr =this->primero;
		while(ptr){
			cout<<ptr->valor<<" --> ";
			ptr=ptr->siguiente;
		}
		cout<<"NULL\n";
	}
};
