#include "Pila.h"
using namespace std;

Pila::Pila() : ult(-1) {}
int Pila::inserta(Empleado elem, int pos){
    if(llena()|| pos<0 || pos>ult+1){
        cout<<"\n Error de insercion";
        return 0;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
bool Pila::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
bool Pila::vacia() const {
    if(ult==-1)
        return true;
    return false;
}

bool Pila::llena() const {
    if(ult==TAM-1)
        return true;
    return false;
}

int Pila::ultimo() const {
    return ult;
}
void Pila::push(const Empleado& emp){
    if (llena()) {
        cout << "La pila esta llena." << endl;
        return;
    }
    inserta(emp, ultimo()+1);
    cout << "Empleado apilado exitosamente" << endl;
}

void Pila::pop(){
    if (vacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    elimina(ultimo());
    cout << "Empleado desapilado exitosamente" << endl;
}
bool Pila::top(Empleado& empleado) {
    if (vacia()) {
        cout << "La pila esta vacia." << endl;
        return false;
    }
    empleado = datos[ult];
    return true;
}


