#include <iostream>
#include <string>
using namespace std;

const int TAM = 100;

class Solicitud {
public:
    string nombreAlumno;
    string carrera;
    string preparatoria;
    float promedioGeneral;

    Solicitud() {
        nombreAlumno = "";
        carrera = "";
        preparatoria = "";
        promedioGeneral = 0.00f;
    }
    friend ostream& operator<<(ostream& o, const Solicitud& soli) {
        o << "Nombre del alumno: " << soli.nombreAlumno << endl;
        o << "Carrera a cursar: " << soli.carrera << endl;
        o << "Preparatoria procedente: " << soli.preparatoria << endl;
        o << "Promedio General: " << soli.promedioGeneral << endl;
        return o;
    }
};

class ListaSolicitudes {
private:
    Solicitud solicitudes[TAM];
    int cants;

public:
    ListaSolicitudes():cants(0){}
    bool Vacia()const{
        if(cants==0){
            return true;}
        return false;
    }
    bool llena()const{
        if(cants==TAM){
            return true;}
        return false;
    }
    void darAltaSolicitud(const Solicitud& soli) {
            solicitudes[cants] = soli;
            cants++;
            cout << "Solicitud agregada exitosamente." << endl;
    }

    void buscarSolicitud(float promedio) {
        if (cants == 0) {
            cout << "No hay solicitudes" << endl;
            return;
        }

        // ordena las solicitudes por promedio de mayor a menor
        quicksort(solicitudes, 0, cants - 1);

        // realiza busqueda binaria
        int izquierda = 0;
        int derecha = cants - 1;
        int posicion = -1;

        while (izquierda <= derecha) {
            int medio = (izquierda + derecha) / 2;
            if (solicitudes[medio].promedioGeneral == promedio) {
                posicion = medio;
                break;
            } else if (solicitudes[medio].promedioGeneral < promedio) {
                derecha = medio - 1; // Debes restar, no sumar
            } else {
                izquierda = medio + 1; // Debes sumar, no restar
                }
        }

        if (posicion != -1) {
            cout << "Solicitud encontrada en la posicion " << posicion << ":" << endl;
            cout << solicitudes[posicion] << endl;
        } else {
            cout << "Solicitud no encontrada. Por favor, dar de alta una solicitud." << endl;
        }
    }


    void quicksort(Solicitud arr[], int extizq, int extder) {
        if (extizq >= extder) return;

        // Intercambiar arr[(extizq + extder) / 2] ↔ arr[extder]
        swap(arr[(extizq + extder) / 2], arr[extder]);

        int i = extizq;
        int j = extder;

        while (i < j) {
            while (i < j && arr[i].promedioGeneral >= arr[extder].promedioGeneral) {
                i++;
        }
        while (i < j && arr[j].promedioGeneral <= arr[extder].promedioGeneral) {
            j--;
        }
        if (i != j) {
            swap(arr[i], arr[j]);
        }
    }

    if (i != extder) {
        swap(arr[i], arr[extder]);
    }

    quicksort(arr, extizq, i - 1);
    quicksort(arr, i + 1, extder);
    }

    void insercion(Solicitud solicitudes[], int ultind){
        int i = 1;
        while (i <= ultind) {
            Solicitud aux = solicitudes[i];
            int j = i;
            while (j > 0 && aux.promedioGeneral < solicitudes[j - 1].promedioGeneral){
                solicitudes[j] = solicitudes[j - 1];
                j = j - 1;}
            if (i != j){
                solicitudes[j] = aux;}
            i = i + 1;
        }}
};

int main() {
    ListaSolicitudes listaSolicitudes;
    int opc;

    do {
        cout << "--------BIENVENIDOS AL MENU DE SOLICITUDES DE INGRESO)--------" << endl;
        cout << "1. Dar de alta una solicitud de ingreso" << endl;
        cout << "2. Buscar una solicitud por promedio general" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opcion que desea seleccionar: ";
        cin >> opc;
        switch (opc) {
            case 1: {
                if (!listaSolicitudes.llena()){
                Solicitud nuevaSolicitud;
                cin.ignore();
                cout << "Nombre del alumno: ";
                getline(cin, nuevaSolicitud.nombreAlumno);
                cout << "Carrera a cursar: ";
                getline(cin, nuevaSolicitud.carrera);
                cout << "Preparatoria procedente: ";
                getline(cin, nuevaSolicitud.preparatoria);
                cout << "Promedio General: ";
                cin >> nuevaSolicitud.promedioGeneral;
                listaSolicitudes.darAltaSolicitud(nuevaSolicitud);
                }else{
                    cout << "No se pueden ingresar mas datos, no hay mas cupo\n" << endl;}
                break;
            }
            case 2: {
                if (!listaSolicitudes.Vacia()){
                float promedio;
                cout << "Ingrese el promedio general a buscar: ";
                cin >> promedio;
                cout<<"\n";
                listaSolicitudes.buscarSolicitud(promedio);
                }else{
                    cout << "No hay solicitudes\n" << endl;}
                break;
            }
            case 3:
                cout << "Gracias por usar nuestro programa\n" << endl;
                return 0;
            default:
                cout << "Opción no válida, por favor intente de nuevo\n" << endl;
        }
    } while (opc != 3);
    return 0;
}
