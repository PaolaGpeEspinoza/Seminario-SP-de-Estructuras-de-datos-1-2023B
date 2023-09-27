#include "Pila.h"
#include <iostream>
using namespace std;

int main() {
    Pila miPila;
    int opc;

    do {
        cout << "\n------BIENVENIDO AL MENU DE PILA DE EMPLEADOS------" << endl
             << "1.- Push (Apilar)\n"
             << "2.- Pop (Desapilar)\n"
             << "3.- Top (Ver empleado en la cima)\n"
             << "4.- Salir\n"
             << "Escriba el numero de la opcion que desea seleccionar: "; cin >> opc;
        switch (opc) {
            case 1: {
                Empleado nuevoEmpleado;
                cin >> nuevoEmpleado;
                miPila.push(nuevoEmpleado);
                break;
            }
            case 2: {
                miPila.pop();
                break;
            }
            case 3: {
                Empleado empleado;
                if (miPila.top(empleado)) {
                    cout << "Empleado en la cima de la pila:" << endl;
                    cout << empleado << endl;
                }
                break;
            }
            case 4:
                cout << "Gracias por usar nuestro menu." << endl;
                break;
            default:
                cout << "\nLa opcion elegida no es valida, por favor intente de nuevo.\n" << endl;
                break;
        }

    } while (opc != 4);

    return 0;
}
