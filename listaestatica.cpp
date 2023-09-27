#include <iostream>
#include <string>
using namespace std;

const int TAM = 100;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

public:
    Empleado() {
        ClaveEmpleado = 0;
        Sueldo = 0.0f;
    }
    int GetClaveEmpleado() const {
        return ClaveEmpleado;}
    void SetClaveEmpleado(int clv) {
        ClaveEmpleado = clv;}
    string GetNombre() const {
        return Nombre;}
    void SetNombre(const string& nom) {
        Nombre = nom;}
    string GetDomicilio() const {
        return Domicilio;}
    void SetDomicilio(const string& dom) {
        Domicilio = dom;}
    float GetSueldo() const {
        return Sueldo;}
    void SetSueldo(float sue) {
        Sueldo = sue;}
    string GetReporta() const {
        return ReportaA;}
    void SetReporta(const string& rep) {
        ReportaA = rep;}
    friend istream& operator>>(istream& i, Empleado& e) {
        cout << "Ingrese la clave del empleado: ";
        i >> e.ClaveEmpleado;
        i.ignore();
        cout << "Ingrese el nombre del empleado: ";
        getline(i, e.Nombre);
        cout << "Ingrese el domicilio del empleado: ";
        //i.ignore();
        getline(i, e.Domicilio);
        cout << "Ingrese el sueldo del empleado: ";
        i >> e.Sueldo;
        cout << "Ingrese a quien reporta el empleado: ";
        i.ignore();
        getline(i, e.ReportaA);
        return i;}
    friend ostream& operator<<(ostream& o, const Empleado& e) {
    o << "Clave del Empleado: " << e.GetClaveEmpleado() << endl;
    o << "Nombre: " << e.GetNombre() << endl;
    o << "Domicilio: " << e.GetDomicilio() << endl;
    o << "Sueldo: " << e.GetSueldo() << endl;
    o << "Reporta a: " << e.GetReporta() << endl;
    return o;}
};

class Lista {
private:
    Empleado datos[TAM];
    int ult;
public:
    Lista():ult(0){}
    bool Vacia()const{
        if(ult==0){
            return true;}
        return false;
    }
    bool Llena()const{
        if(ult==TAM){
            return true;}
        return false;
    }
    int Agrega(const Empleado& empleado) {
        if (ult < TAM) {
            datos[ult] = empleado;
            ult++;
            return 1;
        } else {
            cout << "La lista esta llena. No se pudo agregar el empleado." << endl;
            return 0;
        }
    }
    int Busca(const Empleado& empleado) {
        if (ult == 0) {
            cout << "La lista está vacía." << endl;
            return -1;
        }
        for (int i = 0; i < ult; i++) {
            if (datos[i].GetNombre() == empleado.GetNombre()) {
                cout << "Empleado encontrado en la posicion " << i << ":" << endl;
                cout << datos[i] << endl;
                return i;
        }
    }
    cout << "No se encontro el empleado en la lista." << endl;
    return -1;
    }

    int Elimina(const Empleado& empleado) {
        if (ult == 0) {
            cout << "La lista esta vacía." << endl;
            return 0;
        }
        for (int i = 0; i < ult; i++) {
            if (datos[i].GetNombre() == empleado.GetNombre()) {
                for (int j = i; j < ult - 1; j++) {
                    datos[j] = datos[j + 1];
                }
                ult--;
                cout << "Empleado eliminado exitosamente." << endl;
                return 1;
            }
        }
        cout << "El empleado ingresado no existe en la lista." << endl;
        return 0;
    }

    int Inserta(const Empleado& empleado, int posicion) {
        if (ult == TAM) {
            cout << "La lista esta llena. No se pudo insertar el empleado." << endl;
            return 0;
        }

        if (posicion < 0 || posicion > ult) {
            cout << "La posicion para insertar el empleado es invalida." << endl;
            return 0;
        }

        for (int i = ult; i > posicion; i--) {
            datos[i] = datos[i - 1];
        }
        datos[posicion] = empleado;
        ult++;
        cout << "Empleado insertado exitosamente en la posicion " << posicion << "." << endl;
        return 1;
    }
    void Muestra() {
        if (ult == 0) {
        cout << "La lista esta vacia." << endl;
        } else {
            cout << "Empleados en la lista:" << endl;
            for (int i = 0; i < ult; i++) {
                cout << "Posicion " << i << ":" << endl;
                cout << datos[i] << endl;
            }
        }
    }
};

int main() {
    Lista lista;
    int opc,clv,posicion;
    string nom, dom, rep;
    float sue;

    do {
        cout<<"\n------BIENVENIDO AL MENU DE LISTA DE EMPLEADOS------"<<endl
        <<"1.-Agregar un empleado a la lista\n"
        <<"2.-Buscar un empleado\n"
        <<"3.-Eliminar un empleado\n"
        <<"4.-Insertar un empleado\n"
        <<"5.-Mostrar la lista de empleados\n"
        <<"6.-Salir\n"
        <<"Escriba el numero de la opcion que deseas seleccionar: "; cin>>opc;
        switch (opc) {
            case 1: {
                Empleado nuevoEmpleado;
                cin >> nuevoEmpleado;
                lista.Agrega(nuevoEmpleado);
                break;
            }
            case 2: {
                Empleado buscarEmpleado;
                cout << "Ingrese el nombre completo del empleado a buscar: ";
                cin.ignore();
                getline(cin, nom);
                buscarEmpleado.SetNombre(nom);
                lista.Busca(buscarEmpleado);
                break;
            }
            case 3: {
                Empleado eliminarEmpleado;
                cout << "Ingrese el nombre completo del empleado a eliminar: ";
                cin.ignore();
                getline(cin, nom);
                eliminarEmpleado.SetNombre(nom);
                lista.Elimina(eliminarEmpleado);
                break;
            }
            case 4: {
                Empleado insertarEmpleado;
                cin>>insertarEmpleado;
                cout << "Ingrese la posicion donde desea insertar el empleado: ";
                cin >> posicion;
                lista.Inserta(insertarEmpleado, posicion);
                break;
            }
            case 5:
                lista.Muestra();
                break;
            case 6:
                cout<< "Gracias por usar nuestro menu";
                exit(EXIT_SUCCESS);
                break;
            default:
                cout<< "\nLa opcion elegida no es valida, por favor intente de nuevo\n\n" <<endl;
                break;
        }

    } while (opc != 6);

    return 0;
}
