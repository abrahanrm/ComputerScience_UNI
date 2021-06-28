#include <iostream>
using namespace std;
typedef string Tipo;
class Nodo
{
    private:
        Tipo dato;
        Nodo *izq;
        Nodo *der;
    public:
        Nodo(Tipo valor)
        {
            dato=valor;
            izq=der=NULL;
        }
        Nodo(Nodo* nodoIzq, Tipo vlor, Nodo* nodoDer)
        {
            dato=valor;
            izq=nodoIzq;
            der=nodoDer;
        }
    //funciones de acceso
    Tipo valorNodo(){return dato;}
    Nodo* subArbolIzq(){return izq;}
    Nodo* subArbolDer(){return der;}
    //funciones de modificacion
    void nuevoValor(Tipo d){dato=d;}
    void nodoIzq(Nodo* n){izq=n;}
    void nodoDer(Nodo* n){der=n;}
};

//clase arbol binario
class ArbolB
{
    private:
        Nodo* raiz;
    public:
        ArbolB()
        {
            raiz=NULL;
        }
    //funciones
    bool esVAcio()
    {
        return raiz==NULL;
    }
    Nodo* rizArbol()
    {
        if(esVacio())
            cout<<"Arbol vacio\n";
        else 
            return *raiz;
    }
    Nodo* hijoIzq()
    {
        if(esVacio())
            cout<<"Arbol vacio\n";
        else 
            return raiz->subArbolIzq();
    }
    Nodo* hijoDer()
    {
        if(esVacio())
            cout<<"Arbol vacio\n";
        else 
            return raiz->subArbolDer();
    }
    Nodo* nuevoArbol(Nodo* nodoIzq, Tipo dato, Nodo* nodoDer)
    {
        return new Nodo(nodoIzq, dato, nodoDer);
    }
    void Praiz(Nodo *r)
    {
        raiz=r;
    }
    Nodo* Oraiz()
    {
        return raiz;
    }






}