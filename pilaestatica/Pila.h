#ifndef PILA_H
#define PILA_H

#include "Empleado.h"

const int TAM = 100;

class Pila {
private:
    Empleado datos[TAM];
    int ult;

public:
    Pila();
    int inserta(Empleado elem, int pos);
    bool elimina(int pos);
    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    void push(const Empleado&);
    void pop();
    bool top(Empleado& empleado);
};

#endif // PILA_H
