#include<iostream>
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
        Nodo(Nodo* nodoIzq, Tipo valor, Nodo* nodoDer)
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
//Clase arbol
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
    bool esVacio()
    {
        return raiz==NULL;
    }
    Nodo raizArbol()
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

};

int main()
{
    ArbolB ar;
    ArbolB a[15];
    Nodo* n[15];
    //Nivel 3
    n[0]=a[0].nuevoArbol(NULL, "Benito",NULL);
    n[1]=a[1].nuevoArbol(NULL, "Federico",NULL);
    n[2]=a[2].nuevoArbol(NULL, "Rosa",NULL);
    n[3]=a[3].nuevoArbol(NULL, "Luis",NULL);
    n[4]=a[4].nuevoArbol(NULL, "Pedro",NULL);
    n[5]=a[5].nuevoArbol(NULL, "Ramon",NULL);
    n[6]=a[6].nuevoArbol(NULL, "Zulema",NULL);
    n[7]=a[7].nuevoArbol(NULL, "Pamela",NULL);
    //Nivel 2
    n[8]=a[8].nuevoArbol(n[0], "Maria",n[1]);
    n[9]=a[9].nuevoArbol(n[2], "Rodrigo",n[3]);
    n[10]=a[10].nuevoArbol(n[4], "Anyora", n[5]);
    n[11]=a[11].nuevoArbol(n[6], "Abel",n[7]);
    //Nivel 1
    n[12]=a[12].nuevoArbol(n[8], "Isabel", n[9]);
    n[13]=a[13].nuevoArbol(n[10], "Jesus", n[11]);
    //Nivel 0
    n[14]=a[14].nuevoArbol(n[12], "Esperanza", n[13]);
    ar.Praiz(n[14]);
    //impresion
    cout<<"Nivel 0"<<endl;
    cout<<ar.Oraiz()->valorNodo()<<endl;
    cout<<"Nivel 1"<<endl;
    cout<<ar.Oraiz()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->valorNodo()<<" ";
    cout<<"Nivel 2"<<endl;
    cout<<ar.Oraiz()->subArbolIzq()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolIzq()->subArbolDer()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->subArbolDer()->valorNodo()<<" ";
    cout<<"Nivel 3"<<endl;
    cout<<ar.Oraiz()->subArbolIzq()->subArbolIzq()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolIzq()->subArbolIzq()->subArbolDer()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolIzq()->subArbolDer()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolIzq()->subArbolDer()->subArbolDer()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->subArbolIzq()->subArbolDer()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->subArbolDer()->subArbolIzq()->valorNodo()<<" ";
    cout<<ar.Oraiz()->subArbolDer()->subArbolDer()->subArbolDer()->valorNodo()<<" ";
    return 0;
}



