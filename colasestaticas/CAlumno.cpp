#include "CAlumno.h"
#include <string>
using namespace std;

Alumno::Alumno(){}
Alumno::Alumno(string n, string c, int ma, double prom){
    nombre=n;
    carrera=c;
    materiasAprobadas=ma;
    promedioGeneral=prom;
}
void Alumno::operator=(const Alumno& x){
    nombre = x.nombre;
    carrera = x.carrera;
    materiasAprobadas = x.materiasAprobadas;
    promedioGeneral = x.promedioGeneral;
}
ostream& operator<<(ostream& o, const Alumno& a){
    o <<"\nA quien corresponda:"<<endl
      << "Por medio de este documento se hace constar que el/la alumno/a " << a.nombre
      << " quien cursa la carrera " << a.carrera
      << " con " << a.materiasAprobadas << " materias aprobadas"
      <<" y un promedio de " << a.promedioGeneral
      <<" esta inscrito y activo en el ciclo escolar actual y se encuentra cursandolo"<<endl
      <<"Este documento tiene validez oficial por parte de la universidad y puede ser utilizado en los tramites que sea requerido"<<endl<<"Atte: La direccion de la universidad\n";
    return o;
}
istream& operator>>(istream& i, Alumno& a){
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
    return i;
}
