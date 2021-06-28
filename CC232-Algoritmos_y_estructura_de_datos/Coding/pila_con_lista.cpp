#include<iostream>
using namespace std;
class NodoPila
{
    public:
        int elemento;
        NodoPila* siguiente;
        NodoPila(int x)//constructor
        {
            elemento=x;
            siguiente=NULL;
        }
};
//Clase PilaDina
class PilaDina
{
public:
    NodoPila* cima;
    PilaDina()//constructor
    {
        cima=NULL;
    }
    void insertar(int);
    int quitar();
    int cimaPila();
    bool pilaVacia();
    //void limpiarPila();
};
//********************funcion insertar***************
void PilaDina::insertar(int elemento)
{
    NodoPila* nuevo;
    nuevo=new NodoPila(elemento);
    nuevo->siguiente=cima;
    cima=nuevo;
}

//********************funcion mostrarPila***********************
bool PilaDina::pilaVacia()
{
    return cima==NULL;
};
int PilaDina::cimaPila()
{
    if(pilaVacia())
        cout<<"Pila vacia\n";
    else 
        return cima->elemento;
}
void mostrarPila(PilaDina &pila) //muestra el elemento de la cima a la par que lo elimina
{
    int x;
    cout<<"\nElementos de la pila"<<endl;
    while (!pila.pilaVacia())8
   
   ]
    {
        cout<<"Direccion cima: "<<pila.cima<<". Elemento en la cima: "<<pila.cimaPila()<<endl;
        x=pila.quitar();
        cout<<x<<endl;
    }
    cout<<"Al terminar queda:\n";
    cout<<"Direccion cima:"<<pila.cima<<". Elemento en la cima: "<<pila.cimaPila()<<endl;
};

//**************************funcion quitar********************************
int PilaDina::quitar()
{
    NodoPila* n;
    if(pilaVacia())
    {
        cout<<"Pila vacia, no se puede extraer\n";
    }
    else
    {
        n=cima;
        int x=cima->elemento;
        cima=cima->siguiente;
        delete n;
        return x;
    }   
}


int main()
{
    PilaDina pila;
    pila.insertar(7);
    pila.insertar(6);
    pila.insertar(5);
    pila.insertar(4);
    pila.insertar(3);
    mostrarPila(pila);
    return 0;
}