#include <stdlib.h>
//char *ingresarDatosEnteros(char *);

class Interfaz{
	public:
	virtual ~Interfaz();
	virtual char *ingresarDatos(char const *msj) = 0;
    virtual char *ingresarDatosEnteros(char const *msj) = 0; //interfaz pura
    virtual char *ingresarDatosReales(char const *msj) = 0;
    virtual float ingresar_DatosReales() = 0;
    virtual int ingresar_DatosEnteros() = 0;
};