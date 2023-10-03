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
        cout << "3. Salir" << endl;
        cout << "Ingrese la opcion que desea seleccionar: ";
        cin >> opc;
        switch (opc){
            case 1:{
                if (!solicitudes.llena()){
                    Alumno creaconstancia;
                    cout << "\nIngrese los datos que se piden a continuacion:" << endl;
                    cin >> creaconstancia;
                    solicitudes.enqueue(creaconstancia);
                }
                else{
                    cout << "No se pueden ingresar mas datos la cola esta llena\n" << endl;
                }
                break;
            }
            case 2:{
                if (!solicitudes.vacia()){
                    Alumno constanciacreada = solicitudes.dequeue();
                    cout << "Constancia creada:\n" << constanciacreada << endl;
                }
                else{
                    cout << "No hay solicitudes pendientes, la cola esta vacia\n" << endl;
                }
                break;
            }
            case 3:
                cout << "Gracias por usar nuestro programa\n" << endl;
                return 0;
            default:
                cout << "Opción no valida, por favor intente de nuevo\n" << endl;
        }
    }while(opc!=3);

    return 0;
}
