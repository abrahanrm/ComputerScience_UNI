#include<iostream>
using namespace std;
class NodoCircular //nodo circular
{
    private:
        int dato;
        NodoCircular* enlace;
    public:
        NodoCircular(int t)
        {
            dato=t;
            enlace=this;
        }
        int datoNodo()
        {
            return dato;
        }
        void fijarDato(int a)
        {
            dato=a;
        }
        NodoCircular* enlaceNodo()
        {
            return enlace;
        }
        void ponerEnlace(NodoCircular* sgte)
        {
            enlace=sgte;
        }
};

//Clase 
class ListaCircular
{
    private:
        NodoCircular* acceso;
    public:
        ListaCircular()
        {
            acceso=NULL;
        }
        void crearLista();
        void visualizar();
        void insertarAcceso(int);
        void insertarDespues(int, int);
        void insertarAntes(int, int);
        void eliminar(int);
        void getAcceso();
};

void ListaCircular::getAcceso()
{
    cout<<" "<<acceso->datoNodo()<<endl;
}

//crear lista
void ListaCircular::crearLista()
{
    int x;
    cout<<"Termina con -1"<<endl;
    do
    {
        cin>>x;
        if (x!=-1)
        {
            insertarAcceso(x);
        }
        
    } while (x!=-1);   
}

//visualizar lista
void ListaCircular::visualizar()
{
    NodoCircular* indice;
    if (acceso!=NULL)
    {
        indice=acceso;
        cout<<"DirDelDato"<<"\t"<<"Dato"<<"\t"<<"Siguiente"<<endl;
        do
        {
            cout<<indice<<"\t"<<indice->datoNodo()<<"\t"<<indice->enlaceNodo()<<endl;;
            indice=indice->enlaceNodo();
        } while (indice!=acceso);
    }  
};

//borrado de un nodo
void ListaCircular::eliminar(int dato)
{
    NodoCircular *actual, *anterior;
    actual=acceso;
    anterior=NULL;
    //busca el nodo a eliminar y al anterior
    if (actual->datoNodo()==dato)
    {
        anterior=actual;
        actual=actual->enlaceNodo();
        acceso=actual;
    }
    do
    {
        if (actual->datoNodo()==dato)
            break;
        else
        {
            anterior=actual;
            actual=actual->enlaceNodo();
        }
    } while (actual!=acceso);
    
    //borrando el nodo
    if (actual==acceso)
    {
        acceso=actual->enlaceNodo();
    }
    else
    {
        anterior->ponerEnlace(actual->enlaceNodo());
    }
    delete actual;
}

void ListaCircular::insertarAcceso(int dato)
{
    NodoCircular* nuevo;
    nuevo=new NodoCircular(dato);
    if (acceso!=NULL)
    {
        nuevo->ponerEnlace(acceso->enlaceNodo());
        acceso->ponerEnlace(nuevo);
    }
    acceso=nuevo;
}

void ListaCircular::insertarDespues(int datoAnterior, int dato)
{
    NodoCircular* nuevo;
    NodoCircular* anterior;
    nuevo=new NodoCircular(dato);
    //buscando el datoAnterior
    NodoCircular *indice;
    indice=acceso;
    while(indice!=NULL)
    {
        if(indice->datoNodo()==datoAnterior)
            break;
        else
            indice=indice->enlaceNodo();
    }
    //Insertamos el dato
    if(indice !=NULL)
    {
        anterior=indice;
        if(anterior->enlaceNodo()!=NULL)
        {
            nuevo->ponerEnlace(anterior->enlaceNodo());
            anterior->ponerEnlace(nuevo);
        }
    }
}

void ListaCircular::insertarAntes(int datoPosterior, int dato)
{
    NodoCircular* nuevo;
    NodoCircular* antposterior;
    nuevo=new NodoCircular(dato);
    //buscando el datoAnterior
    NodoCircular *indice;
    indice=acceso;
    while(indice!=NULL)
    {
        if(indice->enlaceNodo()->datoNodo()==datoPosterior)
            break;
        else
            indice=indice->enlaceNodo();
    }
    //Insertamos el dato
    if(indice !=NULL)
    {
        antposterior=indice;
        if(antposterior->enlaceNodo()!=NULL)
        {
            nuevo->ponerEnlace(antposterior->enlaceNodo());
            antposterior->ponerEnlace(nuevo);
        }
    }
}



int main()
{
    ListaCircular miLista;
    miLista.crearLista();
    miLista.visualizar();
    miLista.insertarDespues(7, 8);
    miLista.insertarAntes(5, 9);
    miLista.visualizar();
    //miLista.eliminar(7);
    //miLista.visualizar();
    return 0;
}