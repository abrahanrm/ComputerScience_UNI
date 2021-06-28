//Programa que ordena los nodos de una lista ascendentemente de cabeza a cola.
#include <iostream>
#include <string>
using namespace std;
//Nodo generico
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
//Clase lista
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
        void insertaOrden(int);
};

//Crear lista
void Lista::crearLista()
{
    int x;
    cout<<"Termina con -1"<<endl;
    do
    {
        cin>>x;
        if(x!=-1)
            insertaOrden(x);
            //primero=new Nodo<int>(x,primero);
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

//InsertaOrden
void Lista::insertaOrden(int dato)
{
    Nodo<int>* nuevo;
    nuevo=new Nodo<int>(dato);
    if(primero==NULL)//cuando la lista esta vacia
        primero=nuevo;
    else if (dato<primero->datoNodo())
    {
        nuevo->ponerEnlace(primero);//El dato nuevo apunta al primero
        primero=nuevo;//Y ahora el dato nuevo se convierte en primero
    }
    else //busqueda del nodo al anterior al de inserción
    {
        Nodo<int> *anterior, *p;//p es un puntero que recorre
        anterior=NULL;
        p=primero;
        while((p!=NULL)&&(dato>p->datoNodo()))//anterior y p recorren la lista desde la cabeza
        {
            anterior=p; //guarda el nodo menor al
            p=p->enlaceNodo(); //avanza al siguiente enlace
        }
        //se procede a insertar
        nuevo->ponerEnlace(anterior->enlaceNodo());
        anterior->ponerEnlace(nuevo);
    }   
}

int main()
{
    Lista miLista;
    miLista.crearLista();
    miLista.visualizarLista();
    return 0;
}
