#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Nodo
{
    private:
        T dato;
        Nodo<T>* enlace;
    public:
    Nodo(T t)
    {
        dato=t;
        enlace=NULL;
    }
    Nodo(T t, Nodo<T>* n)
    {
        dato=t;
        enlace=n;
    }
    T datoNodo()
    {
        return dato;
    }
    Nodo<T>* enlaceNodo()
    {
        return enlace;
    }
    void ponerEnlace(Nodo<T>* sgte)
    {
        enlace=sgte;
    }
    void ponerDato(T sgte)
    {
        dato=sgte;
    }
};
//La clase lista
class Lista
{
    private:
        Nodo<int>* primero;
    public:
        Lista()
        {
            primero=NULL;
        }
        void crearLista();
        void visualizarLista();
        void insertarCabezaLista(int );
        void InsertarUltimo(int );
        Nodo<int>* ultimoNodo();
        Nodo<int>* BuscarLista(int );
        void insertarLista(int , int);
        void eliminar(int);
        void modificar(int, int);
};

//Crear una lista
void Lista::crearLista()
{
    int x;
    cout<<"Termina con -1"<<endl;
    do
    {
        cin>>x;
        if(x!=-1)
            primero=new Nodo<int>(x,primero);
    }while(x!=-1);
};

//Visualizar lista
void Lista::visualizarLista()
{
    Nodo<int>* indice;// contador
    cout<<"Direccion del nodo\tDato\tA donde apunta"<<endl;
    for(indice=primero; indice!=NULL; indice=indice->enlaceNodo())
        cout<<indice<<"\t\t"<<indice->datoNodo()<<"\t\t"<<indice->enlaceNodo()<<endl;
};

//insercion en la cabeza de la lista
void Lista::insertarCabezaLista(int dato)
{
    Nodo<int>* nuevo;
    nuevo=new Nodo<int>(dato);
    nuevo->ponerEnlace(primero);
    primero=nuevo;
}

//Insercion en la cola de la lista
void Lista::InsertarUltimo(int dato)
{
    Nodo<int>* ultimo=ultimoNodo();
    ultimo->ponerEnlace(new Nodo<int> (dato));
}

//Encuentra el ultimo nodo
Nodo<int>* Lista::ultimoNodo()
{
    Nodo<int>* p=primero;
    while(p->enlaceNodo()!=NULL)
    {
        p=p->enlaceNodo();
    }
    return p;
}

//Busqueda en lista
Nodo<int>* Lista::BuscarLista(int dato)
{
    Nodo<int>* indice;
    for(indice=primero; indice!=NULL; indice=indice->enlaceNodo())
        if(dato==indice->datoNodo())
            return indice;
    return NULL;
}

//insercion entre dos nodos de la lista
void Lista::insertarLista(int datoAnt, int dato)
{
    Nodo<int>* nuevo;
    Nodo<int>* anterior;
    nuevo=new Nodo<int>(dato);
    anterior=Lista::BuscarLista(datoAnt);
    nuevo->ponerEnlace(anterior->enlaceNodo());
    anterior->ponerEnlace(nuevo);
}

//Borrado de un nodo de la lista
void Lista::eliminar(int dato)
{
    Nodo<int> *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado)
    {
        encontrado = (actual -> datoNodo() == dato);
        if (!encontrado)
        {
            anterior = actual;
            actual = actual -> enlaceNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL)
    {
        // distingue entre cabecera y resto de la lista
        if (actual == primero)
        {
            primero = actual -> enlaceNodo();
        }
        else
        {
            anterior -> ponerEnlace(actual -> enlaceNodo());
        }
        delete actual;
    }
}

void Lista::modificar(int dato, int nuevo)
{
    Nodo<int> *actual, *anterior, *tmp;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    tmp = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado)
    {
        encontrado = (actual -> datoNodo() == dato);
        if (!encontrado)
        {
            anterior = actual;
            actual = actual -> enlaceNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL)
    {
        // distingue entre cabecera y resto de la lista
        if (actual == primero)
        {
            actual -> ponerDato(nuevo);
        }
        else
        {
            actual -> ponerDato(nuevo);
        }
    }
}


int main()
{
    Lista miLista;
    miLista.crearLista();
    miLista.visualizarLista();
    //miLista.insertarCabezaLista(77);
    //miLista.visualizarLista();
    //miLista.InsertarUltimo(44);
    //miLista.visualizarLista();
    //miLista.BuscarLista(77);
    //miLista.insertarLista(10, 15);
    //miLista.visualizarLista();
    //miLista.eliminar(10);
    miLista.modificar(10, 20);
    miLista.visualizarLista();
    return 0;
}

