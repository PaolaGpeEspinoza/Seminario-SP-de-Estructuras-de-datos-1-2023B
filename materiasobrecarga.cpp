#include <iostream>
#include <string>

using namespace std;

class Materia{
    private:
        int Clave;
        string Nombre;
        string ProfesorTit;
        string LibroTexto;
        int NumAlum;
    protected:
    public:
        //constructores
        Materia(int clv, string n, string profe,int numal){
            Clave = clv;
            Nombre = n;
            ProfesorTit = profe;
            NumAlum = numal;
        }
        /*El metodo imprime en este momento no esta implementado en el programa, vaya al caso 3 del switch
        para quitarlo de comentarios y activarla*/
        void Imprime(){
            cout << " Clave: " << Clave << endl;
            cout << " Nombre: " << Nombre << endl;
            cout << " Profesor: " << ProfesorTit << endl;
            cout << " Numero de alumnos: " << NumAlum << endl;
        }
        void CambiaClave(int clv){
            Clave = clv;
        }
        void CambiaProfe(string profe){
            ProfesorTit = profe;
        }
        friend ostream& operator<<(ostream& o, const Materia& imp) {
            o<<"Clave: " << imp.Clave << endl;
            o<<"Nombre: " << imp.Nombre << endl;
            o<<"Profesor: " << imp.ProfesorTit << endl;
            o<<"Numero de Alumnos: "<<imp.NumAlum<<endl;
            o<<"\n";
            return o;
        }
        bool operator==(const Materia& ig) const {
            return Clave == ig.Clave;
        }

        bool operator!=(const Materia& desig) const {
            return Clave != desig.Clave;
        }
        Materia operator+(const Materia& sum) const {
            Materia resultado(Clave + sum.Clave, Nombre + sum.Nombre, ProfesorTit + sum.ProfesorTit, NumAlum + sum.NumAlum);
            return resultado;
        }

        bool operator<(const Materia& menq) const {
            return NumAlum < menq.NumAlum;
        }

        bool operator>(const Materia& mayq) const {
            return NumAlum > mayq.NumAlum;
        }

};

int main(){
    Materia Programacion(1111,"Programacion","Luis Mariscal",20);
    Materia BasesDatos(2222,"Bases de datos","Ignacio Vazquez",30);
    int opc,clv;
    string profe;

    do{
    cout<<"\n------BIENVENIDO A NUESTRO MENU------"<<endl
        <<"1.-Cambiar la clave de la materia programacion\n"
        <<"2.-Cambiar el nombre del profesor de Base de datos\n"
        <<"3.-Ver los datos de la materia Base de datos\n"
        <<"4.-Unir materias\n"
        <<"5.-Comparar materias\n"
        <<"6.-Comparar numero de alumnos\n"
        <<"7.-Salir\n"
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
            cout<<BasesDatos;
            //BasesDatos.Imprime();
            break;
        case 4:{
            Materia resultado = BasesDatos + Programacion;
            cout << "Materias unidas:" << endl;
            cout << resultado;
            break;}
        case 5:{
            if (BasesDatos == Programacion) {
                cout << "Las materias son iguales" << endl;
            } else if (BasesDatos != Programacion) {
                cout << "Las materias son diferentes" << endl;}
            break;}
        case 6:{
            if (BasesDatos > Programacion) {
                cout << "Bases de datos tiene mas alumnos que Programacion" << endl;
            } else if (BasesDatos < Programacion) {
                cout << "Programacion tiene mas alumnos que Bases de datos" << endl;
            }else {
                cout<<"Las dos materias tienen el mismo numero de alumnos";
            }
            break;}
        case 7:
            cout<<"Gracias por usar nuestro programa";
            exit(EXIT_SUCCESS);
            break;
        default:
            cout<<"\nLa opcion elegida no es valida, por favor intente de nuevo\n\n"<<endl;
        }
    }while(opc!=7);
    return 0;
}
