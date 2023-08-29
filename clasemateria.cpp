#include <iostream>
#include <string>

using namespace std;

class Materia{
    private:
        int Clave;
        string Nombre;
        string ProfesorTit;
        string LibroTexto;
    protected:
    public:
        //constructores
        Materia(int clv, string n, string profe){
            Clave = clv;
            Nombre = n;
            ProfesorTit = profe;
        }
        void Imprime(){
            cout << " Clave: " << Clave << endl;
            cout << " Nombre: " << Nombre << endl;
            cout << " Profesor: " << ProfesorTit << endl;
        }
        void CambiaClave(int clv){
            Clave = clv;
        }
        void CambiaProfe(string profe){
            ProfesorTit = profe;
        }

};

int main(){
    Materia Programacion(1111,"Programacion","Luis Mariscal");
    Materia BasesDatos(2222,"Bases de datos","Ignacio Vazquez");
    int opc,clv;
    string profe;

    do{
    cout<<"\n------BIENVENIDO A NUESTRO MENU------"<<endl
        <<"1.-Cambiar la clave de la materia programacion\n"
        <<"2.-Cambiar el nombre del profesor de Base de datos\n"
        <<"3.-Ver los datos de la materia Base de datos\n"
        <<"4.-Salir\n"
        <<"Escriba el numero de la opcion que deseas seleccionar: "; cin>>opc;
    switch(opc){
        case 1:
            cout << "Ingrese nueva clave: ";
            cin >> clv;
            Programacion.CambiaClave(clv);
            break;
        case 2:
            cin.ignore();
            cout << "Ingrese el nombre del nuevo profesor: ";
            getline(cin, profe);
            BasesDatos.CambiaProfe(profe);
            break;
        case 3:
            BasesDatos.Imprime();
            break;
        case 4:
            cout<<"Gracias por usar nuestro programa";
            exit(EXIT_SUCCESS);
            break;
        default:
            cout<<"\nLa opcion elegida no es valida, intente de nuevo\n\n"<<endl;
        }
    }while(opc!=5);
    return 0;
}
