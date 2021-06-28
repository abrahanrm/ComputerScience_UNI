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
    void enOrden(Nodo *);
    void preOrden(Nodo *);
    void postOrden(Nodo *);
    int contarNodos(Nodo*);
    int encontrarAltura(Nodo*);
    void verNivel(Nodo*, int);
    void porAnchura(arbolBB);
    Nodo* busqueda(Nodo*, int);
    void borrarNodo(int );
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
//funcion recursiva para enorden
void arbolBB::enOrden(Nodo *raiz)
{
    if (raiz!=NULL)
    {
        enOrden(raiz->izq);
        cout<<raiz->dato<<" ";
        enOrden(raiz->der);
    }
}

//funcion recursiva para postorden
void arbolBB::postOrden(Nodo *raiz)
{
    if (raiz!=NULL)
    {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        cout<<raiz->dato<<" ";
    }
    
}

//Busqueda de un nodo
Nodo* arbolBB::busqueda(Nodo* raiz, int datoBuscado)
{
    Nodo* r;
    Nodo* rpta=NULL;
    r=raiz;//Inicializa la raiz
    while (r!=NULL)
    {
        if(r->dato==datoBuscado)
        {
            rpta=r;
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

Nodo* arbolBB::minValorNodo(Nodo* nodo)
{
    Nodo* temp = raiz;
    while(temp->izq != NULl)
        temp = temp->izq;
    return tmp;
}

void arbolBB::borrarNodo2(int datoBorrar)
{
    Nodo*r,*padre=NULL,*temp, *destino, *min;
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
    min = minValorNodo(raiz->der);
    destino->dato=min->dato;
    //una vez reeemplado el valor del nodo destino por el valor del nodo min
    //eliminimos el nodo destino con borrarNodo1
    borrarNodo1(r->dato);
}

int main()
{
    arbolBB a;
    int destino;
    completarArbol(a);
    cout<<"\npreorden"<<endl;
    a.preOrden(a.raiz);
    cout<<"\nenorden"<<endl;
    a.enOrden(a.raiz);
    cout<<"\npostorden"<<endl;
    a.postOrden(a.raiz);
    a.porAnchura(a);

    cout<<"Nodo hoja a borrar: ";
    cin>>destino;
    a.borrarNodo(destino);
    a.porAnchura(a);
    return 0;
}




