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

class Bicola
{
    private:
        NodoCola* frente;
        NodoCola* final;
    public:
        Bicola()
        {
        frente=final=NULL;
        }
        void insertar(int elemento);
        int quitar();
        int frenteCola();
        int finalCola();
        bool colaVacia();
        NodoCola* devolverFrente();
        NodoCola* devolverFinal();
        //funciones para la Bicola
        void ponerFinal(int);
        void ponerFrente(int);
        int quitarFrente();
        int quitarFinal();
        int frenteBicola();
        int finalBicola();
        bool bicolaVacia();
        int numElemsBicola();
};
//************ funciones iguales a la cola ******************
NodoCola* Bicola::devolverFrente()
{
    return frente;
}

NodoCola* Bicola::devolverFinal()
{
    return final;
}
//funcion insertar (por el final)*****
void Bicola::insertar(int elemento)
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

bool Bicola::colaVacia()
{
    if(frente==NULL)
        frente = final = NULL;
    return frente==NULL;
}
//*********

int Bicola::quitar()
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


int Bicola::frenteCola()
{
    if (colaVacia())
    {
        cout<<"Cola vacia";
    }
    else
        return frente->elemento;
}

int Bicola::finalCola()
{
    if (colaVacia())
    {
        cout<<"Cola vacia: ";
    }
    else
        return final -> elemento;
}

//************ funciones de Bicola **************

//poner elemento al frente
void Bicola::ponerFrente(int elemento)
{
    NodoCola* nuevo;
    nuevo = new NodoCola(elemento);
    if (bicolaVacia())
    {
        final=nuevo;
    }
    else
    {
        (nuevo->siguiente)=frente;
    }
    frente=nuevo;
}

//quitar elemento del final
int Bicola::quitarFinal()
{
    int x;
    if(bicolaVacia())
    {
        if(frente==final)//bicola dispone de un solo nodo
            x=quitar();
        else
        {
            cout<<"Se elimino de la memoria el nodo: "<<final;
            NodoCola* a = frente; //recorrera la cola
            while (a->siguiente!=final)
                a=a->siguiente;
            x=final->elemento;
            final=a;
            delete(a->siguiente);
            final->siguiente=NULL;
        }   
    }
    else
    {
        cout<<"Bicola vacia\n";
        return 0; 
    }
    return x;
}

//devuelve el elemento final
int Bicola::finalBicola()
{
    if(bicolaVacia())
        cout<<"Error: bicola vacia'n";
    return (final->elemento);
}

int Bicola::numElemsBicola()
{
    int n=0;
    NodoCola* a= frente;
    if(!bicolaVacia())
    {
        n=1;
        while (a!=final)
        {
            n++;
            a=a->siguiente;
        }   
    }
    return n;
}

//funciones equivalentes a la cola
void Bicola::ponerFinal(int elemento)
{
    insertar(elemento);
}

int Bicola::quitarFrente()
{
    return quitar();
}

int Bicola::frenteBicola()
{
    return frenteCola();
}

bool Bicola::bicolaVacia()
{
    return colaVacia();
}

void mostrarCola(Bicola &cola)
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


void completarCola(Bicola &cola)
{
    int x, n;
    cout<<"Cuantos elementos ingresara a la cola: ";
    cin>>n;
    cout<<"Digite el elemento y luego pulse enter";
    for(int i=0; i<n; i++)
    {
        cout<<"Direccion frente: "<<cola.devolverFrente()<<". Elemento frente: "<<cola.frenteCola()<<endl;
        cout<<"Direccion final: "<<cola.devolverFinal()<<". Elemento final"<<cola.finalCola()<<endl;
        cout<<"Indice"<<i<<":";
        cin>>x;
        cola.insertar(x);
    }
    cout<<"Direccion frente: "<<cola.devolverFrente()<<". Elemento frente: "<<cola.frenteCola()<<endl;
    cout<<"Direccion final: "<<cola.devolverFinal()<<". Elemento final"<<cola.finalCola()<<endl;
}


int main()
{
    Bicola cola;
    completarCola(cola);
    cola.ponerFrente(5);
    cola.ponerFinal(500);
    mostrarCola(cola);
    return 0;
}