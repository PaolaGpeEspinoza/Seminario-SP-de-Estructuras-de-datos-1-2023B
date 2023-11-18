#include <iostream>
#include <string>

class SocioClub {
private:
    int NumeroSocio;
    std::string NombreSocio;
    std::string Domicilio;
    int AnioIngreso;

public:
    SocioClub() : NumeroSocio(0), AnioIngreso(0) {}
    SocioClub(int numSocio, const std::string& nombre, const std::string& domicilio, int anioIngreso)
        : NumeroSocio(numSocio), NombreSocio(nombre), Domicilio(domicilio), AnioIngreso(anioIngreso) {}

    int getNumeroSocio() const { return NumeroSocio; }
    std::string getNombreSocio() const { return NombreSocio; }
    std::string getDomicilio() const { return Domicilio; }
    int getAnioIngreso() const { return AnioIngreso; }

    friend std::ostream& operator<<(std::ostream& os, const SocioClub& socio) {
        os << "Numero Socio: " << socio.NumeroSocio << ", Nombre: " << socio.NombreSocio
           << ", Domicilio: " << socio.Domicilio << ", Anio Ingreso: " << socio.AnioIngreso;
        return os;
    }

    bool operator<(const SocioClub& otro) const {
        return NumeroSocio < otro.NumeroSocio;
    }

    bool operator==(const SocioClub& otro) const {
        return NumeroSocio == otro.NumeroSocio;
    }
};

template <class T>
class node {
public:
    T data;
    node<T>* sig;

    node() : sig(nullptr) {}
    node(const T& elem) : data(elem), sig(nullptr) {}
};

template <class T>
class LSLSE {
private:
    node<T>* lista;

public:
    LSLSE() : lista(nullptr) {}
    ~LSLSE();
    bool vacia() const;
    node<T>* ultimo() const;
    node<T>* primero() const;
    node<T>* anterior(node<T>* pos) const;
    void insertar(node<T>* pos, const T& elem);
    bool eliminar(node<T>* pos);
    void imprimir() const;
    int calcularTotalSocios() const;
    SocioClub* buscarPorNombre(const std::string& nombre) const;
    SocioClub* buscarPorDomicilio(const std::string& domicilio) const;
};

template <class T>
LSLSE<T>::~LSLSE() {
    while (lista != nullptr) {
        node<T>* temp = lista;
        lista = lista->sig;
        delete temp;
    }
}

template <class T>
bool LSLSE<T>::vacia() const {
    if(lista==nullptr)
        return true;
    return false;
}

template <class T>
node<T>* LSLSE<T>::ultimo() const {
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template <class T>
node<T>* LSLSE<T>::primero() const {
    if(vacia()){
        return nullptr;
    }
    return lista;
}

template <class T>
node<T>* LSLSE<T>::anterior(node<T>* pos) const {
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template <class T>
void LSLSE<T>::insertar(node<T>* pos, const T& elem) {
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template <class T>
bool LSLSE<T>::eliminar(node<T>* pos) {

    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template <class T>
void LSLSE<T>::imprimir() const {
    node<T>* aux = lista;
    while (aux != nullptr) {
        std::cout << aux->data << "\n";
        aux = aux->sig;
    }
}

template <class T>
int LSLSE<T>::calcularTotalSocios() const {
    int total = 0;
    node<T>* aux = lista;
    while (aux != nullptr) {
        total++;
        aux = aux->sig;
    }
    return total;
}

template <>
SocioClub* LSLSE<SocioClub>::buscarPorNombre(const std::string& nombre) const {
    node<SocioClub>* aux = lista;
    while (aux != nullptr) {
        if (aux->data.getNombreSocio() == nombre) {
            return &(aux->data);
        }
        aux = aux->sig;
    }
    return nullptr;
}

template <>
SocioClub* LSLSE<SocioClub>::buscarPorDomicilio(const std::string& domicilio) const {
    node<SocioClub>* aux = lista;
    while (aux != nullptr) {
        if (aux->data.getDomicilio() == domicilio) {
            return &(aux->data);
        }
        aux = aux->sig;
    }
    return nullptr;
}

int main() {
    LSLSE<SocioClub> listaSocios;
    int opcion;

    do {
        std::cout << "\n---------BIENVENIDO A NUESTRO MENU---------\n";
        std::cout << "1.- Registrar un nuevo socio\n";
        std::cout << "2.- Dar de baja un socio\n";
        std::cout << "3.- Generar reporte de socios\n";
        std::cout << "4.- Buscar socio por nombre\n";
        std::cout << "5.- Buscar socio por domicilio\n";
        std::cout << "6.- Calcular e imprimir el total de socios registrados\n";
        std::cout << "7.- Salir\n";
        std::cout << "Escriba el numero de opcion que desea seleccionar: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int numSocio, anioIngreso;
                std::string nombre, domicilio;

                std::cout << "Ingrese Numero de Socio: ";
                std::cin >> numSocio;

                if (listaSocios.buscarPorNombre(nombre) != nullptr) {
                    std::cout << "Ya existe un socio con ese numero.\n";
                    break;
                }

                std::cout << "Ingrese Nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);

                std::cout << "Ingrese Domicilio: ";
                std::getline(std::cin, domicilio);

                std::cout << "Ingrese Anio de Ingreso: ";
                std::cin >> anioIngreso;

                SocioClub nuevoSocio(numSocio, nombre, domicilio, anioIngreso);
                listaSocios.insertar(listaSocios.ultimo(), nuevoSocio);
                std::cout << "Socio registrado con exito.\n";
                break;
            }
            case 2: {
                if (!listaSocios.vacia()){
                int numSocio;
                std::cout << "Ingrese Numero de Socio a dar de baja: ";
                std::cin >> numSocio;

                node<SocioClub>* aux = listaSocios.primero();
                while (aux != nullptr) {
                    if (aux->data.getNumeroSocio() == numSocio) {
                        listaSocios.eliminar(aux);
                        std::cout << "Socio dado de baja con exito.\n";
                        break;
                    }
                    aux = aux->sig;
                }
                if (aux == nullptr) {
                    std::cout << "No se encontro un socio con ese numero.\n";
                }
                }else{
                    std::cout << "La lista esta vacia\n" << std::endl;
                }
                break;
            }
            case 3: {
                if (!listaSocios.vacia()){
                std::cout << "\nReporte de Socios:\n";
                listaSocios.imprimir();
                }else{
                    std::cout << "No hay socios registrados\n" << std::endl;
                }
                break;
            }
            case 4: {
                if (!listaSocios.vacia()){
                std::string nombre;
                std::cout << "Ingrese nombre del socio a buscar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);

                SocioClub* socioEncontrado = listaSocios.buscarPorNombre(nombre);
                if (socioEncontrado != nullptr) {
                    std::cout << "Socio encontrado:\n" << *socioEncontrado << "\n";
                } else {
                    std::cout << "No se encontro un socio con ese nombre.\n";
                }
                }else{
                    std::cout << "La lista esta vacia\n" << std::endl;
                }
                break;
            }
            case 5: {
                if(!listaSocios.vacia()){
                std::string domicilio;
                std::cout << "Ingrese domicilio del socio a buscar: ";
                std::cin.ignore();
                std::getline(std::cin, domicilio);

                SocioClub* socioEncontrado = listaSocios.buscarPorDomicilio(domicilio);
                if (socioEncontrado != nullptr) {
                    std::cout << "Socio encontrado:\n" << *socioEncontrado << "\n";
                } else {
                    std::cout << "No se encontro un socio con ese domicilio\n";
                }
                }else{
                    std::cout << "La lista esta vacia\n" << std::endl;
                }
                break;
            }
            case 6: {
                int totalSocios = listaSocios.calcularTotalSocios();
                std::cout << "Total de socios registrados: " << totalSocios << "\n";
                break;
            }
            case 0:
                std::cout << "Gracias por usar nuestro menu\n";
                break;
            default:
                std::cout << "\nLa opcion elegida no es valida, intente de nuevo\n\n";
        }
    } while (opcion != 7);

    return 0;
}

