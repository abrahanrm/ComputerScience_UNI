#include<iostream>
#include<string>
using namespace std;
//*****Clases Grafo***************
class nodoG
{
    public:
    class arco;
    int nombre; 
    nodoG* sgte; 
    arco* ady; 
    nodoG* p; 
    void insertarNodo(int ); 
    void mostrarGrafo(); 
    void insertarArco(int, int); 
    void agregarArco(nodoG* , nodoG* , arco* ); 
};
class nodoG::arco
{
    public:
    nodoG* destino; 
    arco* sgte; 
};

//*****Clases arbol************
class NodoA
{
    public:
    int dato;
    NodoA *izq, *der, *padre;  //agregra el nodo pardre para dfacilitar la insercion de arcos
    NodoA()
    {
        dato=NULL;
        izq=der=padre=NULL;
    }
};
class arbolBB
{
    public:
    NodoA *raiz;
    arbolBB()
    {
        raiz=NULL;
    }
    void crear(int);
    void crear(NodoA*, int);
    //void preOrden(NodoA *);
    int contarNodos(NodoA*);
    int encontrarAltura(NodoA*);
    void verNivel(NodoA*, int);
    void porAnchura(arbolBB);
    NodoA* busqueda(NodoA*,int);
    int maximovalor(NodoA*);
    //void borrarNodo(int );
};

//*************************************

//********************************************* funciones Grafo  **********************************************************
void nodoG::insertarNodo(int nom)
{
    nodoG* t; 
    nodoG *nuevo=new nodoG; 
    nuevo->nombre = nom;
    //cin>>nuevo->nombre; 
    nuevo->sgte = NULL; 
    nuevo->ady=NULL;
    if(p==NULL)
    {
        p = nuevo; 
    }
    else
    {
        t = p; 
        while(t->sgte!=NULL) 
        {
            t = t->sgte; 
        }
        t->sgte = nuevo; 
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

void nodoG::insertarArco(int ini, int fin)
{
    //int ini, fin; 
    arco* nuevo=new arco(); 
    nodoG* aux; 
    nodoG* aux2; 
    if(p==NULL) 
    {
        cout<<"Grafo vacio\n";
        return;
    }
    nuevo->sgte=NULL; 
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

//************************************************************************************* funciones arbol  **********************************************************
int arbolBB::maximovalor(NodoA* r){
	int n;
	while(r->der!=NULL){
		r = r->der;
	}
	n=r->dato;
	return n;
}
void arbolBB::crear(int nuevoDato)
{

    if (raiz==NULL)//Si no tiene raiz, crea el nodo raiz
    {
        raiz=new NodoA;
        raiz->dato=nuevoDato;
        //raiz->izq=raiz->der=NULL;
        return ;
    }
    NodoA *r=raiz;
    crear(r, nuevoDato);
}
    
//funcion recursiva
void arbolBB::crear(NodoA *r, int nuevoDato)
{
    if (nuevoDato<r->dato)
    {
        if (r->izq == NULL)
        {
            NodoA *nuevoNodo;
            nuevoNodo=new NodoA;
            nuevoNodo->dato=nuevoDato;
            r->izq=nuevoNodo;
            r->izq->padre=r; 
            return;
        }
        crear(r->izq, nuevoDato);
    }
    else
    {
        if (nuevoDato>r->dato)
        {
            if (r->der==NULL)
            {
                NodoA *nuevoNodo=new NodoA;
                nuevoNodo->dato=nuevoDato;
                r->der=nuevoNodo;
                r->der->padre=r; 
                return;
            }
            crear(r->der, nuevoDato);
        }
    }
}

//Cuenta nodos del arbol
int arbolBB::contarNodos(NodoA *raiz)
{
    int n=1;
    if (raiz->izq!=NULL)
        n=n+contarNodos(raiz->izq);
    if(raiz->der!=NULL)
        n=n+contarNodos(raiz->der);
    return n;
}

//Altura del nodo
int arbolBB::encontrarAltura(NodoA *raiz){
    if(raiz!=NULL)
        return max(encontrarAltura(raiz->izq),encontrarAltura(raiz->der))+1;
}
//Funcion recursiva para ver por nivel
void arbolBB::verNivel(NodoA *raiz, int n)
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

void arbolBB::porAnchura(arbolBB a)   //ingresar directorio
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

//Busqueda de un nodo
NodoA* arbolBB::busqueda(NodoA* raiz,int datoBuscado)
{
	NodoA *r;
	NodoA *rpta=NULL;
	r=raiz; //Se inicializa a la raiz del arbol
	while(r!=NULL)
	{
		if(r->dato==datoBuscado)
		{
			rpta=r;
			break;
		}
		if (datoBuscado<r->dato)
			r=r->izq;
		else
			r=r->der;	
	}
}

int main()  //arbol
{
    nodoG* p=new nodoG; //grafo
    int n;
    arbolBB a;          //arbol
    NodoA *min, *d;
    int destino;
    completarArbol(a);  //llena el arbol
    n = a.maximovalor(a.raiz);

    for(int i=0; i<=n; i++){
		if(a.busqueda(a.raiz,i)!=NULL)
		  p->insertarNodo(a.busqueda(a.raiz, i)->dato);
		}		
	
    //insertando arcos
    NodoA* b =new NodoA;
    NodoA* c =new NodoA;
    for(int i=0; i<=n; i++)
    {
        b=a.busqueda(a.raiz,i);
		if((b!=NULL) && (b->dato != a.raiz->dato))
        {
            c = b->padre;
            while(c->dato != a.raiz->dato)
            {
                p->insertarArco(b->dato, c->dato);
                c = c->padre;
            }
            p->insertarArco(b->dato, c->dato);
        }
	}

	cout<<"Grafo creado: \n";
	p->mostrarGrafo();
    
    //cout<<"\npreorden"<<endl;
    //a.preOrden(a.raiz);
    cout<<endl;
    //a.porAnchura(a);
    //min = a.minValorNodo(a.raiz->der);
    //cout<<"Minimo valor del subarbol derecho"<<endl;
    //cout<<min->dato;
    return 0;
}
