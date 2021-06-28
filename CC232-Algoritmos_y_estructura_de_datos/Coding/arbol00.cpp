#include<iostream>
using namespace std;
class Nodo
{
    public:
    int dato;
    Nodo *izq, *der;
    Nodo()
    {
        dato=NULL;
        izq=der=NULL;
    }
};
class arbolBB
{
    public:
    Nodo *raiz;
    arbolBB()
    {
        raiz=NULL;
    }
    void crear(int);
    void crear(Nodo*, int);
    void preOrden(Nodo *);
    int contarNodos(Nodo*);
    int encontrarAltura(Nodo*);
    void verNivel(Nodo*, int);
    void porAnchura(arbolBB);
    Nodo* busqueda(int);
    void borrarNodo(int );
    Nodo* minValorNodo(Nodo* );
    void borrarNodo1(int );
    void borrarNodo2(Nodo*,int );
};


/////Crear Recursivo///////////
//Funcion para la llamada recursiva
void arbolBB::crear(int nuevoDato)
{

    if (raiz==NULL)//Si no tiene raiz, crea el nodo raiz
    {
        raiz=new Nodo;
        raiz->dato=nuevoDato;
        //raiz->izq=raiz->der=NULL;
        return ;
    }
    Nodo *r=raiz;
    crear(r, nuevoDato);//llamada a la funcion recursiva
}
    
//funcion recursiva
void arbolBB::crear(Nodo *r, int nuevoDato)
{
    if (nuevoDato<r->dato)//Si el nuevoDato es menor que el dato raiz se mueve a la izquierda
    {
        if (r->izq == NULL)
        {
            Nodo *nuevoNodo;
            nuevoNodo=new Nodo;
            nuevoNodo->dato=nuevoDato;
            r->izq=nuevoNodo;
            return;
        }
        crear(r->izq, nuevoDato);//Si no mueve la raiz al nodo de la izquierda
    }
    else
    {
        if (nuevoDato>r->dato)
        {
            if (r->der==NULL)
            {
                Nodo *nuevoNodo=new Nodo;
                nuevoNodo->dato=nuevoDato;
                r->der=nuevoNodo;
                return;
            }
            crear(r->der, nuevoDato);//Si no mueve la raiz al nodo de la derecha
        }
    }
}

//Cuenta nodos del arbol
int arbolBB::contarNodos(Nodo *raiz)
{
    int n=1;
    if (raiz->izq!=NULL)
        n=n+contarNodos(raiz->izq);
    if(raiz->der!=NULL)
        n=n+contarNodos(raiz->der);
    return n;
}

//Altura del nodo
int arbolBB::encontrarAltura(Nodo*raiz){
    if(raiz!=NULL)
        return max(encontrarAltura(raiz->izq),encontrarAltura(raiz->der))+1;
}
//Funcion recursiva para ver por nivel
void arbolBB::verNivel(Nodo *raiz, int n)
{
    if (raiz!=NULL)
    {
        if(n==0)
        {
            cout<<raiz->dato<<" ";
        }
        else
        {
            verNivel(raiz->izq, n-1);
            verNivel(raiz->der, n-1);
        }
    }
}

void arbolBB::porAnchura(arbolBB a)
{
    int nivel=0, niveles;
    niveles=a.encontrarAltura(a.raiz)-1;
    while (nivel<=niveles)
    {
        verNivel(a.raiz,nivel);
        nivel++;
        cout<<endl;
    }   
}

//*************** funcion completarArbol *****************
void completarArbol(arbolBB &a)
{
    int n, dato;
    cout<<"Cuantos nodos desea insertar: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Dato"<<i<<":";
        cin>>dato;
        a.crear(dato);
    }   
}

//funcion recursiva para preorden
void arbolBB::preOrden(Nodo *raiz)
{
    if (raiz!=NULL)
    {
        cout<<raiz->dato<<" ";
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

//Busqueda de un nodo
Nodo* arbolBB::busqueda(int datoBuscado)
{
    Nodo* r;
    Nodo* rpta=NULL;
    r=raiz;//Inicializa la raiz
    while (r!=NULL)
    {
        if(r->dato==datoBuscado)
        {
            return r;
            break;
        }
        if(datoBuscado < r->dato)
            r = r->izq;
        else    
            r=r->der;
    }
    return rpta;
}

////Eliminacion de un nodo con un solo hijo o sin hijos
void arbolBB::borrarNodo1(int datoBorrar)
{
    Nodo*r,*padre=NULL,*temp;
    r=raiz;
    while(r!=NULL) //Busca el dato a borrar
    {
        if(r->dato==datoBorrar)
            break;
        padre=r;
        if (datoBorrar < r->dato)
            r=r->izq;
        else
            r=r->der;
    } //Fin de la busqueda
    if(r==NULL)
    {
        cout<<" El dato no esta en el arbol"<<endl;
        return;
    }
    else if (padre->dato < r->dato) //Si el nodo objetivo esta a la derecha
    {
        if ((r->der==NULL) && (r->izq!=NULL)) // Si r solo tiene hijo izquierdo
        {
            temp=r;
            padre->der=r->izq;
            delete temp;
        }
        else if ((r->der!=NULL) && (r->izq==NULL)) // Si r solo tiene hijo derecho
        {
            temp=r;
            padre->der=r->der;
            delete temp;
        }
        else if ((r->izq==NULL) &&(r->der==NULL)) // si r es una hoja
        {
            temp=r;
            padre->der=NULL;
            delete temp;
        }
    }
    else if (padre->dato > r->dato) //Si el nodo objetivo esta a la izquierda
    {
        if ((r->der==NULL) && (r->izq!=NULL)) // Si r solo tiene hijo izquierdo
        {
            temp=r;
            padre->izq=r->izq;
            delete temp;
        }
        else if ((r->der!=NULL) && (r->izq==NULL)) // Si r solo tiene hijo derecho
        {
            temp=r;
            padre->izq=r->der;
            delete temp;
        }
        else if ((r->izq==NULL) &&(r->der==NULL)) // si r es una hoja
        {
            temp=r;
            padre->izq=NULL;
            delete temp;
        }
    }
}


void arbolBB::borrarNodo2(Nodo* min, int datoBorrar)
{
    Nodo*r,*padre=NULL;
    int tmp;
    r=raiz;
    while(r!=NULL) //Busca el dato a borrar
    {
        if(r->dato==datoBorrar)
        break;
        padre=r;
        if (datoBorrar < r->dato)
            r=r->izq;
        else
            r=r->der;
    } //Fin de la busqueda
    if(r==NULL)
    {
        cout<<" El dato no esta en el arbol"<<endl;
        return;
    }
    else {
    tmp = min->dato;
    borrarNodo1(min->dato);
    r->dato = tmp;
    }
}

Nodo* arbolBB::minValorNodo(Nodo* nodo)
{
    Nodo* tmp = nodo;
    while(tmp->izq != NULL)
        tmp = tmp->izq;
    return tmp;
}

int main()
{
    arbolBB a;
    Nodo *min, *d;
    int destino;
    completarArbol(a);
    cout<<"\npreorden"<<endl;
    a.preOrden(a.raiz);
    cout<<endl;
    a.porAnchura(a);
    min = a.minValorNodo(a.raiz->der);
    cout<<"Minimo valor del subarbol derecho"<<endl;
    cout<<min->dato;
    cout<<"Ingrese el nodo a eliminar: ";
    cin>>destino;
    d = a.busqueda(destino);
    if((d->izq!=NULL)&&(d->der!=NULL))
        a.borrarNodo2(min, destino);
    else{
        a.borrarNodo1(destino);
    }
    a.preOrden(a.raiz);
    cout<<endl;
    a.porAnchura(a);
    return 0;
}




