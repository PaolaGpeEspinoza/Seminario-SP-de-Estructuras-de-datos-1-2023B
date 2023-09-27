#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <string>
using namespace std;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

public:
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


#endif // EMPLEADO_H
