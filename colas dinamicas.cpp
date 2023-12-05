#include <iostream>
#include <string>
using namespace std;

class Alumno
{
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    Alumno(){}
    Alumno(string n, string c, int ma, double prom){
        nombre=n;
        carrera=c;
        materiasAprobadas=ma;
        promedioGeneral=prom;}

    void operator=(const Alumno& x){
        nombre = x.nombre;
        carrera = x.carrera;
        materiasAprobadas = x.materiasAprobadas;
        promedioGeneral = x.promedioGeneral;}

    friend ostream& operator<<(ostream& o, const Alumno& a){
        o <<"\nA quien corresponda:"<<endl
        << "Por medio de este documento se hace constar que el/la alumno/a " << a.nombre
        << " quien cursa la carrera " << a.carrera
        << " con " << a.materiasAprobadas << " materias aprobadas"
        <<" y un promedio de " << a.promedioGeneral
        <<" esta inscrito y activo en el ciclo escolar actual y se encuentra cursandolo"<<endl
        <<"Este documento tiene validez oficial por parte de la universidad y puede ser utilizado en los tramites que sea requerido"<<endl<<"Atte: La direccion de la universidad\n";
        return o;}

    friend istream& operator>>(istream& i, Alumno& a){
        cin.ignore();
        cout << "Ingrese el nombre del alumno: ";
        getline(i, a.nombre);
        cout << "Ingrese el nombre de la carrera: ";
        getline(i, a.carrera);
        cout << "Ingrese el numero de materias aprobadas: ";
        i >> a.materiasAprobadas;
        cout << "Ingrese el promedio general del alumno: ";
        i >> a.promedioGeneral;
        cout << "\n";
        return i;}
};


template <class T>
class node {
public:
    T data;
    node<T>* sig;

    node() : sig(nullptr) {}
    node(const T& elem) : data(elem), sig(nullptr) {}
};

template <class T>
class CoDi {
private:
    node<T>* cola;
    int ult;

public:
    CoDi() : cola(nullptr), ult(0) {}
    ~CoDi();
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    void insertar(node<T>* pos, const T& elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;
    void enqueue( const T& elem);
    T dequeue();
};

template <class T>
CoDi<T>::~CoDi() {
    while (cola != nullptr) {
        node<T>* temp = cola;
        cola = cola->sig;
        delete temp;
    }
}

template <class T>
bool CoDi<T>::vacia() const {
    if(cola==nullptr)
        return true;
    return false;
}

template <class T>
node<T>* CoDi<T>::ultimo() const {
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=cola;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template <class T>
node<T>* CoDi<T>::primero() const {
    if(vacia()){
        return nullptr;
    }
    return cola;
}

template <class T>
node<T>* CoDi<T>::anterior(node<T>* pos) const {
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=cola;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template <class T>
void CoDi<T>::insertar(node<T>* pos, const T& elem) {
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=cola;
        cola=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }

}

template <class T>
bool CoDi<T>::eliminar(node<T>* pos) {

    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==cola){
        cola=cola->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template <class T>
void CoDi<T>::imprimir() const {
    node<T>* aux = cola;
    while (aux != nullptr) {
        std::cout << aux->data << "\n";
        aux = aux->sig;
    }
}

template <class T>
T CoDi<T>::dequeue()
{
    if (vacia()) {
        throw runtime_error("Error: cola vacía");
    }
    T dato = cola->data;
    eliminar(cola);
    ult--;
    return dato;

}

template <class T>
void CoDi<T>::enqueue(const T& elem)
{
    insertar(ultimo(), elem);
    ult++;
}

int main() {
    CoDi<Alumno> Solicitudes;
    int opc;

    do {
        std::cout << "\n---------BIENVENIDO A NUESTRO MENU---------\n";
        std::cout << "1.- Dar de alta una constancia escolar\n";
        std::cout << "2.- Imprimir constancia\n";
        std::cout << "3.- Salir\n";
        std::cout << "Escriba el numero de opcion que desea seleccionar: ";
        std::cin >> opc;

        switch (opc) {
            case 1: {
                    Alumno creaconstancia;
                    cout << "\nIngrese los datos que se piden a continuacion:" << endl;
                    cin >> creaconstancia;
                    Solicitudes.enqueue(creaconstancia);
                break;
            }
            case 2: {
                if (!Solicitudes.vacia()){
                    Alumno constanciacreada = Solicitudes.dequeue();
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
                std::cout << "\nLa opcion elegida no es valida, intente de nuevo\n\n";
        }
    } while (opc != 3);

    return 0;
}

