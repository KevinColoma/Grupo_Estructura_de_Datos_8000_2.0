#include <iostream>
#include <fstream>
#define DIMENSION 8
class Reina{
	private:
		bool **validar;
		char **tablero;
		std::fstream archivo;
		int contador;
		int n;
    public:
    	
        Reina(int n1);
		void encerarTablero();
        void crearArchivo();
        void bloquear(int x, int y);
        void mostrar();
        void quitarRelleno(int x,int y);
        void mostrarPantalla();
        void mostrarEnConsola();
        void solucion(int x, int y, int n1);
        void solucionReinas();      
};
