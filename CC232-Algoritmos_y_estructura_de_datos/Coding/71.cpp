#include <iostream>
#include <string>
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
            dato = t;
            adelante=atras=NULL;
        }
        int datoNodo(){return dato;} 
        void fijarDato(int a) {dato=a;}
		NodoDoble* adelanteNodo() {return adelante;}
		NodoDoble* atrasNodo() {return atras;}
		void ponerAdelante(NodoDoble* a) {adelante=a;}
		void ponerAtras(NodoDoble* a) {atras=a;}
};

class ListaDoble
{
    private:
        NodoDoble* cabeza;
    public:
        ListaDoble()
        {
            cabeza = NULL;
        }
    void crearLista();
    void visualizar();
    void insertarCabezaLista(int);
    void insertarDespues(int, int);
    void eliminar(int);
    //Continua las demás funciones
};

void ListaDoble::crearLista()
{
    int x;
    cout<<"Termina con -1"<<endl;
    do
    {
        cin>>x;
        if(x!=-1)
            insertarCabezaLista(x);
    }while (x!=-1);
};

void ListaDoble::insertarCabezaLista(int dato)
{
    NodoDoble* nuevo;
    nuevo=new NodoDoble(dato);
    nuevo -> ponerAdelante(cabeza);

    if (cabeza != NULL )
        cabeza -> ponerAtras(nuevo);
    cabeza = nuevo;
};

void ListaDoble::visualizar()
{
    NodoDoble* indice;
    indice = cabeza;
    cout<<"Atras"<<"\t"<<"DirDelDato"<<"\t"<<"Dato"<<"\t"<<"Adelante"<<endl;
    while (indice != NULL)
    {
        cout<<indice->atrasNodo()<<"\t"<<indice<<"\t"<<indice->datoNodo()<<"\t"<<indice->adelanteNodo()<<endl;
        indice = indice -> adelanteNodo();
    }
};




void ListaDoble::insertarDespues(int datoAnterior, int dato)
{
    NodoDoble* nuevo;
    NodoDoble* anterior;
    nuevo= new NodoDoble(dato);
    //Buscar el datoAnterior
    NodoDoble *indice;
    indice=cabeza;
    while(indice!=NULL)
    {
        if(indice->datoNodo()==datoAnterior)
            break;
        else
            indice=indice->adelanteNodo();
    }
    //Insertamos el dato
    if(indice !=NULL)
    {
        anterior=indice;
        nuevo->ponerAdelante(anterior->adelanteNodo());
        if(anterior->adelanteNodo()!=NULL)
            anterior->adelanteNodo()->ponerAtras(nuevo);
        anterior->ponerAdelante(nuevo);
        nuevo->ponerAtras(anterior);
    }
};

void ListaDoble::eliminar(int dato)
{
    
}




int main()
{
    ListaDoble miLista;
    miLista.crearLista();
    miLista.visualizar();
    miLista.insertarDespues(7, 50);
    cout<<"----------\n";
    miLista.visualizar();
    /*NodoDoble *x;
    NodoDoble *y;
    NodoDoble *z;
    x=new NodoDoble(3);
    y=new NodoDoble(5);
    z=new NodoDoble(7);

    cout<<"Atras\tDirDelDato\tDato\tAdelante\n";
	cout<<x->atrasNodo()<<"\t"<<x<<"\t"<<x->datoNodo()<<"\t"<<x->adelanteNodo()<<endl;	
	cout<<y->atrasNodo()<<"\t"<<y<<"\t"<<y->datoNodo()<<"\t"<<y->adelanteNodo()<<endl;
	cout<<z->atrasNodo()<<"\t"<<z<<"\t"<<z->datoNodo()<<"\t"<<z->adelanteNodo()<<endl;
	//Formando la lista doble
	x->ponerAdelante(y);y->ponerAtras(x);
	y->ponerAdelante(z);z->ponerAtras(y);
    z->ponerAdelante(y);
    cout<<"Atras\tDirDelDato\tDato\tAdelante\n";
	cout<<x->atrasNodo()<<"\t"<<x<<"\t"<<x->datoNodo()<<"\t"<<x->adelanteNodo()<<endl;	
	cout<<y->atrasNodo()<<"\t"<<y<<"\t"<<y->datoNodo()<<"\t"<<y->adelanteNodo()<<endl;
	cout<<z->atrasNodo()<<"\t"<<z<<"\t"<<z->datoNodo()<<"\t"<<z->adelanteNodo()<<endl;
	return 0;
    */


}