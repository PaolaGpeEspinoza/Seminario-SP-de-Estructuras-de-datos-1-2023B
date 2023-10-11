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
    bool operator==(Alumno&p){
        return p.nombre==nombre&&p.carrera==carrera&&p.materiasAprobadas==materiasAprobadas&&p.promedioGeneral==promedioGeneral;
    }
    friend bool operator<(const Alumno& a, const Alumno& b);
    string getNombre() const;
};

#endif // CALUMNO_H
