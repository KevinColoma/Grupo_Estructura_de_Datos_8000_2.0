#include <iostream>
#include "application.h"

/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Nombre del archivo: Traductor.cpp
 * Fecha de creaci�n: DD/MM/AAAA
 * Autores:  Mateo Llumigusin, Kevin Coloma, Jefferson Guaman�, Mateo Barriga
 * Correo electr�nico: correo@espe.edu.ec
 * Descripci�n: TRADUCTOR DE ESPA�OL A INGLES Y VICEVERSA
 *              con cuentas de usuario y Administrador.
 */

int main()
{
    std::setlocale(LC_ALL, ".UTF-8");
    return Application::run(ApplicationState::RUN);
}