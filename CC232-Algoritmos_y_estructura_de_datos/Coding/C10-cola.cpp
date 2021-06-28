#include<iostream>
using namespace std;
class NodoCola
{
public:
    NodoCola* siguiente;
    int elemento;
    NodoCola(int x)
    {
        elemento =x;
        siguiente=NULL;
    }
};

class Cola
{
private:
    NodoCola* frente;
    NodoCola* final;
public:
    Cola()
    {
        frente=final=NULL;
    }
    void insertar(int);
    int quitar();
    int frenteCola();
    int finalCola();
    bool colaVacia();
    NodoCola* devolverFrente();
    NodoCola* devolverFinal();
};
//************* funcion insertar **************
void Cola::insertar(int elemento)
{
    NodoCola* nuevo;
    nuevo=new NodoCola(elemento);
    if (colaVacia())
    {
        frente=nuevo;
    }
    else
    {
        (final->siguiente)=nuevo;
    }
    final=nuevo;
}

bool Cola::colaVacia()
{
    if(frente==NULL)
        frente = final = NULL;
    return frente==NULL;
}

//************* funcion quitar **************
int Cola::quitar()
{
    if (colaVacia())
    {
        cout<<"Cola vacia, nose puede extraer";
    }
    else
    {
        cout<<"Se elimino de la memoria el nodo: "<<frente;
        int x = (frente->elemento);
        NodoCola* a= frente;
        frente=(frente->siguiente);
        delete a;
        return x;
    }
}

//************* funcion mostrarCola **************
void mostrarCola(Cola &cola)
{
    int x;
    cout <<"\nElementos de la Pila:"<<endl;
    while (!cola.colaVacia())
    {
        cout<<"Direccion frente: "<<cola.devolverFrente()<<" . Elemento frente: "<<cola.frenteCola()<<endl;
        cout<<"Direccion final: "<<cola.devolverFinal()<<" . Elemento final: "<<cola.finalCola()<<endl;
        x = cola.quitar();
        cout << " . "<<x <<endl;
    }
    cout<<"Direccion frente: "<<cola.devolverFrente()<<" . Elemento frente: "<<cola.frenteCola()<<endl;
    cout<<"Direccion final: "<<cola.devolverFinal()<<" . Elemento final: "<<cola.finalCola()<<endl;
}


//************* funciones devolverFrente, frenteCola, devolverFinal y finalCola **************
NodoCola* Cola::devolverFrente()
{
    return frente;
}

int Cola::frenteCola()
{
    if (colaVacia())
    {
        cout<<"Cola vacia";
    }
    else
        return frente->elemento;
}

NodoCola* Cola::devolverFinal()
{
    return final;
}

int Cola::finalCola()
{
    if (colaVacia())
    {
        cout<<"Cola vacia: ";
    }
    else
        return final -> elemento;
}

//****************** funcion completarCola*******************
void completarCola(Cola &cola)
{
    int x, n;
    cout<<"Cuantos elementos ingresara a la cola: ";
    cin>>n;
    cout<<"Digite el elemento y luego pulse enter";
    for(int i=0; i<n; i++)
    {
        cout<<"Direccion frente: "<<cola.devolverFrente()<<". Elemento frente: "<<cola.frenteCola()<<endl;
        cout<<"Direccion final: "<<cola.devolverFinal()<<". Elemento final"<<cola.finalCola()<endl;
        cout<<"Indice"<<i<<":";
        cin>>x;
        cola.insertar(x);
    }
    cout<<"Direccion frente: "<<cola.devolverFrente()<<". Elemento frente: "<<cola.frenteCola()<<endl;
    cout<<"Direccion final: "<<cola.devolverFinal()<<". Elemento final"<<cola.finalCola()<endl;
}

/*
int main()
{
    Cola cola;
    cola.insertar(5);
    cola.insertar(6);
    cola.insertar(7);
    cola.insertar(8);
    mostrarCola(cola);
    return 0;
}
*/
int main()
{
    Cola cola;
    complementarCola(cola);
    mostrarCola(cola);
    return 0;
}