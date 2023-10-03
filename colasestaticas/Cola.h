#ifndef COLA_H
#define COLA_H
#include "CAlumno.h"
#include <string>

using namespace std;
const int TAM = 2;

class Cola{
private:
    Alumno datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Alumno& elem, int pos);

public:
     Cola():ult(-1) {}
    bool vacia()const;
    bool llena()const;
    int ultimo()const;
    friend ostream& operator<<(ostream & o, Cola& L);
    void enqueue(Alumno& elem);
    Alumno& dequeue();
};

#endif // COLA_H
