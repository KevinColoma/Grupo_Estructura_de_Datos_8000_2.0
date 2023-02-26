#include <iostream>
#include "application.h"

/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Nombre del archivo: Traductor.cpp
 * Fecha de creación: DD/MM/AAAA
 * Autores:  Mateo Llumigusin, Kevin Coloma, Jefferson Guamaní, Mateo Barriga
 * Correo electrónico: correo@espe.edu.ec
 * Descripción: TRADUCTOR DE ESPAÑOL A INGLES Y VICEVERSA
 *              con cuentas de usuario y Administrador.
 */

int main()
{
    std::setlocale(LC_ALL, ".UTF-8");
    return Application::run(ApplicationState::RUN);
}