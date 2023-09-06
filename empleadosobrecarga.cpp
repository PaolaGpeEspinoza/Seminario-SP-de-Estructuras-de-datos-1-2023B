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
        // Constructor
        Empleado(string n, int clv, string dom, float sue, string rep){
            Nombre=n;
            ClaveEmpleado=clv;
            Domicilio=dom;
            Sueldo=sue;
            ReportaA=rep;
        }
        /*El metodo imprime en este momento no esta implementado en el programa, vaya al caso 3 del switch
        para quitarlo de comentarios y activarla*/
        void Imprime(){
            cout<<"\n\nClave del empleado: "<<ClaveEmpleado
                <<"\nNombre: "<<Nombre
                <<"\nDomicilio: "<<Domicilio
                <<"\nSueldo: "<<Sueldo
                <<"\nReporta a: "<<ReportaA
                <<"\n";
        }
        void CambiaDomic(string dom){
            Domicilio = dom;
        }
        void CambiaReportaA(string rep){
            ReportaA = rep;
        }
        void ActualSueldo(float suel){
            suel = suel*Sueldo/100;
            Sueldo = Sueldo+suel;
        }
        bool operator==(const Empleado& ig) const {
            return ClaveEmpleado == ig.ClaveEmpleado;
        }

        bool operator!=(const Empleado& desig) const {
            return ClaveEmpleado != desig.ClaveEmpleado;
        }

        friend ostream& operator<<(ostream& o, const Empleado& imp) {
            o<<"\n\nClave del empleado: "<<imp.ClaveEmpleado;
            o<<"\nNombre: "<<imp.Nombre;
            o<<"\nDomicilio: "<<imp.Domicilio;
            o<<"\nSueldo: "<<imp.Sueldo;
            o<<"\nReporta a: "<<imp.ReportaA;
            o<<"\n";
            return o;
        }

        Empleado operator+(const Empleado& sum) const {
            Empleado resultado(Nombre + sum.Nombre, ClaveEmpleado + sum.ClaveEmpleado, Domicilio + sum.Domicilio, Sueldo + sum.Sueldo, ReportaA + sum.ReportaA);
            return resultado;
        }

        bool operator<(const Empleado& menq) const {
            return Sueldo < menq.Sueldo;
        }

        bool operator>(const Empleado& mayq) const {
            return Sueldo > mayq.Sueldo;
        }
};

int main() {
    Empleado JefePlanta("Larissa Torres",1111,"Av de la mancha 555",1000,"Juan Rodriguez");
    Empleado JefePersonal("Diego Torres",2222,"Mariano Otero 333",1000,"Martin Lopez");
    int opc, clv;
    string dom, rep;
    float sue;

    do{
        cout<<"\n------BIENVENIDO A NUESTRO MENU------"<<endl
        <<"1.-Cambiar domicilio de un empleado\n"
        <<"2.-Actualizar el sueldo de un empleado\n"
        <<"3.-Ver los datos de un empleado\n"
        <<"4.-Cambiar el nombre de la persona a quien reporta un empleado\n"
        <<"5.-Unir empleados\n"
        <<"6.-Comparar empleados\n"
        <<"7.-Comparar sueldos de empleados\n"
        <<"8.-Salir\n"
        <<"Escriba el numero de la opcion que deseas seleccionar: "; cin>>opc;

        switch (opc) {
            case 1:{
                cout<<"Ingrese la clave del empleado: ";
                cin>>clv;
                cin.ignore();
                if(clv==1111){
                    cout<<"\nSelecciono al jefe de planta:\nIngrese el nuevo domicilio: ";
                    getline(cin,dom);
                JefePlanta.CambiaDomic(dom);
                cout<<"\n";
                }else if(clv==2222){
                cout<<"\nSelecciono al jefe de personal\nIngrese el nuevo domicilio: ";
                getline(cin,dom);
                JefePersonal.CambiaDomic(dom);
                cout<<"\n";
                }else{
                cout << "Clave no valida, por favor intente de nuevo" << endl;
                }
                break;}
            case 2:{
                cout<<"Ingrese la clave del empleado: ";
                cin>>clv;
                if(clv==1111){
                cout<<"\nSelecciono al jefe de Planta\nIngrese el porcentaje de incremento a su sueldo: ";
                cin>>sue;
                JefePlanta.ActualSueldo(sue);
                cout<<"\n";
                }else if(clv==2222){
                cout<<"\nJefe Personal\nIngrese el porcentaje de incremento a su sueldo: ";
                cin>>sue;
                JefePersonal.ActualSueldo(sue);
                cout<<"\n";
                }else{
                cout << "Clave no valida, por favor intente de nuevo" << endl;
                }
                break;}
            case 3:{
                cout<<"Ingrese la clave del empleado: ";
                cin>>clv;
                if(clv==1111){
                    cout<<"\nJefe de Planta:";
                    cout<<JefePlanta;
                    //JefePlanta.Imprime();
                }else if(clv==2222){
                    cout<<"\nJefe de Personal:";
                    cout<<JefePersonal;
                    //JefePersonal.Imprime();
                }else{
                    cout << "Clave no valida, por favor intente de nuevo" << endl;
                }
                break;}
            case 4:{
                cout<<"Ingresa la clave del empleado: ";
                cin>>clv;
                cin.ignore();
                if(clv==1111){
                    cout<<"Ingresa el nombre de quien reporta: ";
                    getline(cin,rep);
                    JefePlanta.CambiaReportaA(rep);
                    cout<<"\n";
                }else if(clv==2222){
                    cout<<"Ingresa el nombre de quien reporta: ";
                    getline(cin,rep);
                    JefePersonal.CambiaReportaA(rep);
                    cout<<"\n";
                }else{
                    cout << "Clave no valida, por favor intente de nuevo" << endl;
                }
                break;}
            case 5:{
                Empleado resultado = JefePlanta + JefePersonal;
                cout << "Empleados unidos:" << endl;
                cout << resultado;
                break;}
            case 6:{
                if (JefePersonal == JefePlanta) {
                    cout << "Los empleados son iguales" << endl;
                } else if (JefePersonal != JefePlanta) {
                    cout << "Los empleados son diferentes" << endl;}
                break;}
            case 7:{
                if (JefePersonal > JefePlanta) {
                    cout << "El Jefe de Personal gana mas que el Jefe de Planta" << endl;
                } else if (JefePersonal < JefePlanta) {
                    cout << "El Jefe de Personal gana menos que el Jefe de Planta" << endl;
                    }else {
                        cout<<"Los sueldos son iguales";

                    }
                break;}
            case 8:{
                cout<<"Gracias por usar nuestro menu";
                exit(EXIT_SUCCESS);
            }
            default:
                cout<<"\nLa opcion elegida no es valida, por favor intente de nuevo\n\n"<<endl;
                break;
        }
    }while(opc!=8);

    return 0;
}
