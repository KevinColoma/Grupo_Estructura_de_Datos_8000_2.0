// Mochila.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstring>
#include "Objeto.h"
using namespace std;

int main()
{
    Backpack backpack;
    int choice, weight, value, capacity;
    while (true)
    {
        cout << "1. Agregar objeto" << endl;
        cout << "2. Resolver problema de la mochila" << endl;
        cout << "3. Obtener resultado" << endl;
        cout << "4. Limpiar datos" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Ingrese el peso y el valor del objeto: ";
            cin >> weight >> value;
            backpack.addObject(weight, value);
            break;
        case 2:
            cout << "Ingrese la capacidad de la mochila: ";
            cin >> capacity;
            backpack.setCapacity(capacity);
            backpack.solve();
            break;
        case 3:
            cout << "Resultado: " << backpack.getResult() << endl;
            break;
        case 4:
            backpack.clear();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
