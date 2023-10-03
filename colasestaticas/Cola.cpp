#include "Cola.h"
#include <string>
using namespace std;
bool Cola::vacia()const
{
    if(ult==-1)
        return true;
    return false;
}
bool Cola::llena()const
{
    if(ult==TAM-1)
        return true;
    return false;
}

int Cola::ultimo()const
{
    return ult;
}

ostream& operator<<(ostream & o, Cola& L)
{
    int i=0;
    cout<<"\n";
    while(i<=L.ultimo())
    {
        ;
        o<<L.datos[i];
        i++;
    }
    return o;
}

void Cola::enqueue(Alumno& elem)
{
    inserta(elem,0);
}

Alumno& Cola::dequeue()
{
    ult--;
    return datos[ult+1];

}

bool Cola::elimina(int pos)
{
    if(vacia() || pos<0 || pos>ult)
    {
        cout<<"\n error de eliminacion";
        return true;
    }
    int i=pos;
    while(i<ult)
    {
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return false;
}
int Cola::inserta(Alumno& elem, int pos)
{
    int i=ult+1;
    while(i>pos)
    {
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return 1;
}
