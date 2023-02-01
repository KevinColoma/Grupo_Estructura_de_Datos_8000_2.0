#pragma once
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
	Nodo (int val, Nodo *sig=NULL){
		this->valor=val;
		this->siguiente=sig;
	}
	friend class Lista;
};