#include<iostream>
#include<string>
using namespace std;
class NodoDoble 
{
    private:
        int dato;
        NodoDoble* adelante;
        NodoDoble* atras;
    public:
        NodoDoble(int t)
        {
            dato=t;
            adelante=atras=NULL;
        }
        int datoNodo(){return dato;}
        void fijarDato(int a){dato=a;}
        NodoDoble* adelanteNodo(){return adelante;}
        NodoDoble* atrasNodo(){return atras;}
        void ponerAdelante(NodoDoble* a){adelante=a;}
        void ponerAtras(NodoDoble* a){atras=a;}
};

class ListaDoble
{
    private:
        NodoDoble* cabeza;
        NodoDoble* cola;
    public:
        ListaDoble()
        {
            cabeza=cola=NULL;
        }
        void crearLista();
        void visualizar();
        void insertarCabezaLista(int);
        void insertarDespues(int, int);
        void eliminar(int);
        void insertarFinLista(int);
        void insertarAntes(int, int);
        void modificar(int,int);
};

void ListaDoble::crearLista(){
    int x;
    cout<<"Termina con -1"<<endl;
    do
    {
        cin>>x;
        if(x!=-1)
            insertarCabezaLista(x);
    } while(x!=-1);
};

void ListaDoble::insertarCabezaLista(int dato)
{
    NodoDoble* nuevo;
    nuevo=new NodoDoble(dato);
    nuevo->ponerAdelante(cabeza);
    if(cabeza!=NULL)
        cabeza->ponerAtras(nuevo);
    cabeza=nuevo;
};

void ListaDoble::visualizar()
{
    NodoDoble* indice;
    indice=cabeza;
    cout<<"Atras"<<"\t"<<"DirDelDato"<<"\t"<<"Dato"<<"\t"<<"Adelante"<<endl;
    while (indice!=NULL)
    {
        cout<<indice->atrasNodo()<<"\t"<<indice<<"\t"<<indice->datoNodo()<<"\t"<<indice->adelanteNodo()<<endl;
        indice=indice->adelanteNodo();
    }   
};

void ListaDoble::insertarDespues(int datoAnterior, int dato)
{
    NodoDoble* nuevo;
    NodoDoble* anterior;
    nuevo=new NodoDoble(dato);
    //buscando el dato anterior
    NodoDoble *indice;
    indice=cabeza;
    while (indice!=NULL)
    {
        if(indice->datoNodo()==datoAnterior)
            break;
        else
            indice=indice->adelanteNodo();
    }
    //insertando el dato
    if(indice!=NULL)
    {
        anterior=indice;
        nuevo->ponerAdelante(anterior->adelanteNodo());
        if(anterior->adelanteNodo()!=NULL)
            anterior->adelanteNodo()->ponerAtras(nuevo);
        else
            cola=nuevo;
        anterior->ponerAdelante(nuevo);
        nuevo->ponerAtras(anterior);
    }
};

void ListaDoble::insertarFinLista(int dato)
{
    NodoDoble* nuevo;
    nuevo = new NodoDoble (dato);
    nuevo -> ponerAtras(cola);
    if (cola != NULL )
    cola->ponerAdelante(nuevo);
    else
    cabeza=cola=nuevo;
    cola=nuevo;
};

void ListaDoble::insertarAntes(int datoPosterior, int dato)
{
    NodoDoble* nuevo;
    NodoDoble* posterior;
    nuevo=new NodoDoble(dato);
    //busqueda del nodo
    NodoDoble* indice;
    indice = cabeza;
    while (indice != NULL)
    {
        if(indice -> datoNodo() == datoPosterior)
        break;
        else
        indice = indice -> adelanteNodo();
    }
    //Inserta antes
    if(indice != NULL)
    {
        posterior=indice;
        nuevo->ponerAdelante(posterior);
        if(posterior->atrasNodo()!=NULL)
            posterior->atrasNodo()->ponerAdelante(nuevo);
        else
            cabeza=nuevo;
        nuevo->ponerAtras(posterior->atrasNodo());
        posterior->ponerAtras(nuevo);
    }
};

void ListaDoble::modificar(int datoAntiguo, int dato)
{
    // Bucle de búsqueda del antiguo
    NodoDoble* indice;
    indice = cabeza;
    while (indice != NULL)
    {
        if (indice -> datoNodo() == datoAntiguo)
        break;
        else
        indice=indice->adelanteNodo();
    }
    //Reemplaza el dato
    if(indice != NULL)
    {
        indice->fijarDato(dato);
    }
}

int main()
{
    ListaDoble miLista;
    miLista.crearLista();
    miLista.visualizar();
    miLista.insertarDespues(7, 99);
    //miLista.modificar(7,555);
    //cout<<"--------------\n";
    miLista.visualizar();
    return 0;
}
