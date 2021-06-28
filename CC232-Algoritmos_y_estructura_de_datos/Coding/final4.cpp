#include<iostream>
using namespace std;
//*****Clases Grafo***************
class nodoG
{
    public:
    class arco;
    string nombre; 
    nodoG* sgte; 
    arco* ady; 
    nodoG* p; 
    void insertarNodo(string ); 
    void mostrarGrafo(); 
    void insertarArco(); 
    void agregarArco(nodoG* , nodoG* , arco* ); 
};
class nodoG::arco
{
    public:
    nodoG* destino; 
    arco* sgte; 
};
//************** Clases arbol **********
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
    //void borrarNodo1(int );
    //void borrarNodo2(Nodo*,int );
    void verNivel2(Nodo*, int, nodoG* &);
    void porAnchura2(arbolBB, nodoG* &);
    void insertarDirectorio(arbolBB , nodoG* &g);
};


//***************************************************************** funciones Grafo  **********************************************************
void nodoG::insertarNodo(string nom)
{
    nodoG* t; 
    nodoG *nuevo=new nodoG; 
    //cout<<"Ingrese el nombre:";
    nuevo->nombre = nom;
    //cin>>nuevo->nombre; 
    nuevo->sgte = NULL; 
    nuevo->ady=NULL;
    cout<<"print"<<endl;
    if(p==NULL)
    {
        p = nuevo; 
        cout<<"Primer nodo del directorio\n";
    }
    else
    {
        t = p; 
        while(t->sgte!=NULL) 
        {
            t = t->sgte; 
        }
        t->sgte = nuevo; 
        cout<<"Nodo ingresado\n";
    }
};

void nodoG::mostrarGrafo()
{
    nodoG* t; 
    arco* ar; 
    t=p; 
    cout<<"Nodo\t|\tLista de adyacencia\n";
    while(t!=NULL) 
    {
        cout<<t->nombre<<"\t|";
        if(t->ady!=NULL) 
        {
            ar=t->ady; 
            while(ar!=NULL) 
            {
                cout<<" "<<ar->destino->nombre; 
                ar=ar->sgte; 
            }
        }
    t=t->sgte; 
    cout<<endl;
    }
};

void nodoG::insertarArco()
{
    string ini, fin; 
    arco* nuevo=new arco(); 
    nodoG* aux; 
    nodoG* aux2; 
    if(p==NULL) 
    {
        cout<<"Grafo vacio\n";
        return;
    }
    nuevo->sgte=NULL; 
    cout<<"Ingrese el nombre del nodo inicio: ";
    cin>>ini;
    cout<<"Ingrese el nombre del nodo final: ";
    cin>>fin;
    aux=p; 
    aux2=p; 
    while(aux2!=NULL) 
    {
        if(aux2->nombre==fin) 
        {
        break; 
        }
        aux2=aux2->sgte; 
    }
    while(aux!=NULL) 
    {
        if(aux->nombre==ini) 
        {
            agregarArco(aux,aux2, nuevo); 
            return;
        }
        aux = aux->sgte; 
    }
};
// agregarArco une los nodos inicial y final
void nodoG::agregarArco(nodoG* aux, nodoG* aux2, arco* nuevo)
{
    arco* q; 
    if(aux->ady==NULL) 
    {
        aux->ady=nuevo; 
        nuevo->destino=aux2; 
        cout<<"1er arco del nodo "<<aux->nombre<<endl;
    }
    else
    {
        q=aux->ady; 
        while(q->sgte!=NULL)
        {
            q=q->sgte;
        }
        q->sgte=nuevo; 
        nuevo->destino=aux2; 
        cout<<"Arco agregado\n";
    }
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


Nodo* arbolBB::minValorNodo(Nodo* nodo)
{
    Nodo* tmp = nodo;
    while(tmp->izq != NULL)
        tmp = tmp->izq;
    return tmp;
}




//***** insertar directorio (inicio) ************
void arbolBB::verNivel2(Nodo *raiz, int n, nodoG* &p)
{
    //to_string(raiz->dato)
    if (raiz!=NULL)
    {
        if(n==0)
        {
            //cout<<raiz->dato<<" ";
            p->insertarNodo("3");    //insertando nodo en el grafo
        }
        else
        {
            verNivel2(raiz->izq, n-1, p);
            verNivel2(raiz->der, n-1, p);
        }
    }
}

void arbolBB::porAnchura2(arbolBB a, nodoG* &g)   //ingresar directorio
{
    int nivel=0, niveles;
    niveles=a.encontrarAltura(a.raiz)-1;
    while (nivel<=niveles)
    {
        verNivel2(a.raiz,nivel,g);
        nivel++;
        cout<<endl;
    }   
}

void arbolBB::insertarDirectorio(arbolBB a, nodoG* &g)
{
    a.porAnchura2(a, g);  
    
}
//***** insertar directorio (fin) ************




int main()
{
    nodoG* p=new nodoG; //grafo
    arbolBB a;
    Nodo *min, *d;
    int destino;
    completarArbol(a);
    cout<<"\npreorden"<<endl;
    a.preOrden(a.raiz);
    cout<<endl;
    a.porAnchura(a);
    
    
    a.insertarDirectorio(a, p);
    
    p->insertarArco();
    p->insertarArco();
    p->insertarArco();
    p->insertarArco();
    p->insertarArco();
    p->insertarArco();
    
    cout<<"Mostrando grafo:\n";
    p->mostrarGrafo();
    
    /*
    
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
    */
    return 0;
}
