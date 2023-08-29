#include <iostream>
#include <string>

using namespace std;

class Empleado{
    private:
        string Nombre;
        int ClaveEmpleado;
        string Domicilio;
        float Sueldo;
        string ReportaA;
    protected:
    public:
        //constructores
        Empleado(string n, int clv, string dom, float sue, string rep){
            Nombre=n;
            ClaveEmpleado=clv;
            Domicilio=dom;
            Sueldo=sue;
            ReportaA=rep;
        }
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

};

int main(){
    Empleado JefePlanta("Larissa Torres",1111,"Av de la mancha 555",1000,"Juan Rodriguez");
    Empleado JefePersonal("Diego Flores",2222,"Mariano Otero 333",1000,"Martin Lopez");
    int opc, clv;
    string dom, rep;
    float sue;

    do{
    cout<<"\n------BIENVENIDO A NUESTRO MENU------"<<endl
        <<"1.-Cambiar domicilio de un empleado\n"
        <<"2.-Actualizar el sueldo de un empleado\n"
        <<"3.-Ver los datos de un empleado\n"
        <<"4.-Cambiar el nombre de la persona a quien reporta un empleado\n"
        <<"5.-Salir\n"
        <<"Escriba el numero de la opcion que deseas seleccionar: "; cin>>opc;
    switch(opc){
        case 1:
            cout<<"Ingrese la clave del empleado: ";
            cin>>clv;
            cin.ignore();
            if(clv==1111){
            cout<<"\nSelecciono al jefe de planta:\nIngrese el nuevo domicilio: ";
            getline(cin,dom);
            JefePlanta.CambiaDomic(dom);
            cout<<"\n";
            }
            if(clv==2222){
            cout<<"\nSelecciono al jefe de personal\nIngrese el nuevo domicilio: ";
            getline(cin,dom);
            JefePersonal.CambiaDomic(dom);
            cout<<"\n";
            }
            break;
        case 2:
            cout<<"Ingrese la clave del empleado: ";
            cin>>clv;
            if(clv==1111){
            cout<<"\nSelecciono al jefe de Planta\nIngrese el porcentaje de incremento a su sueldo: ";
            cin>>sue;
            JefePlanta.ActualSueldo(sue);
            cout<<"\n";
            }
            if(clv==2222){
            cout<<"\nJefe Personal\nIngrese el porcentaje de incremento a su sueldo: ";
            cin>>sue;
            JefePersonal.ActualSueldo(sue);
            cout<<"\n";
            }
            break;
        case 3:
            cout<<"Ingrese la clave del empleado: ";
            cin>>clv;
            if(clv==1111){
                cout<<"\nJefe de Planta:";
                JefePlanta.Imprime();
            }
            if(clv==2222){
                cout<<"\nJefe de Personal:";
                JefePersonal.Imprime();
            }
            break;
        case 4:
            cout<<"Ingresa la clave del empleado: ";
            cin>>clv;
            cin.ignore();
            if(clv==1111){
                cout<<"Ingresa el nombre de quien reporta: ";
                getline(cin,rep);
                JefePlanta.CambiaReportaA(rep);
                cout<<"\n";
            }
            if(clv==2222){
                cout<<"Ingresa el nombre de quien reporta: ";
                getline(cin,rep);
                JefePersonal.CambiaReportaA(rep);
                cout<<"\n";
            }
            break;
        case 5:
            cout<<"Gracias por usar nuestro menu";
            exit(EXIT_SUCCESS);
        default:
            cout<<"\nLa opcion elegida no es valida, intente de nuevo\n\n"<<endl;
        }
    }while(opc!=5);
    return 0;
}
