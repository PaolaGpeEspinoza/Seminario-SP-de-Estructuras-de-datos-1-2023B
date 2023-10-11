#include <iostream>
#include <string>
#include "Cola.h"
using namespace std;

int main(){
    Cola solicitudes;
    int opc;
    do{
        cout << "--------BIENVENIDOS AL MENU DE LA DIRECCION (CONSTANCIAS)--------" << endl;
        cout << "1. Dar de alta una constancia escolar" << endl;
        cout << "2. Imprimir constancia" << endl;
        cout << "3.Buscar una constancia"<<endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese la opcion que desea seleccionar: ";
        cin >> opc;
        switch (opc){
            case 1:{
                if (!solicitudes.llena()){
                    Alumno creaconstancia;
                    cout << "\nIngrese los datos que se piden a continuacion:" << endl;
                    cin >> creaconstancia;
                    solicitudes.enqueue(creaconstancia);
                }else{
                    cout << "No se pueden ingresar mas datos la cola esta llena\n" << endl;
                }
                break;
            }
            case 2:{
                if (!solicitudes.vacia()){
                    Alumno constanciacreada = solicitudes.dequeue();
                    cout << "Constancia creada:\n" << constanciacreada << endl;
                }else{
                    cout << "No hay solicitudes pendientes, la cola esta vacia\n" << endl;
                }
                break;
            }
            case 3:{
                Alumno constanciaencontrada;
                if (!solicitudes.vacia()){
                cout << "\nIngrese los datos de la solicitud a buscar:" << endl;
                cin >> constanciaencontrada;
                int posicion = solicitudes.busquedaLineal(constanciaencontrada);
                int constanciasPend = solicitudes.constanciasPendientes(posicion);

                if (posicion != -1){
                    cout << "Solicitud encontrada en la posicion " << posicion << endl;
                if (constanciasPend > 0){
                    cout << "Faltan " << constanciasPend << " constancias antes de elaborar la de " << constanciaencontrada.getNombre() << "." << endl;
                }else{
                    cout << "Es el turno de elaborar la constancia de " << constanciaencontrada.getNombre() << endl;
                }}else{
                cout << "Ese usuario no ha generado una constancia, favor de darla de alta" << endl;
                }}else{
                        cout << "No hay solicitudes, la cola esta vacia\n" << endl;
                }break;
                }
            case 4:
                cout << "Gracias por usar nuestro programa\n" << endl;
                return 0;
            default:
                cout << "Opción no valida, por favor intente de nuevo\n" << endl;
        }
    }while(opc!=4);

    return 0;
}
