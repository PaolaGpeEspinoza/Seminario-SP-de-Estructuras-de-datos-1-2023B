#ifndef CALUMNO_H
#define CALUMNO_H
#include <iostream>
#include <string>
using namespace std;

class Alumno
{
private:
    string nombre;
    string carrera;
    int materiasAprobadas;
    double promedioGeneral;

public:
    Alumno();
    Alumno(string n, string c, int ma, double prom);
    void operator=(const Alumno& x);
    friend ostream& operator<<(ostream& os, const Alumno& a);
    friend istream& operator>>(istream& is, Alumno& a);
};

#endif // CALUMNO_H
