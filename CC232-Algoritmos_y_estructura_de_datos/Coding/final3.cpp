#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Nodo
{
	public:
	int dato;
	Nodo *izq,*der,*padre;    //para ahorrar el trabajo de buscar el padre, lo que hice fue enlazar el nodo con su nodo padre 
	Nodo(){                    
		dato=NULL;
		izq=der=padre=NULL;  //nuestro nodo padre tambien se NULL
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
	void crear1(Nodo*, int);
	void preOrden(Nodo*);
	void enOrden(Nodo*);
	void postOrden(Nodo*);
	int contarNodos(Nodo*);
	int encontrarAltura(Nodo*);
	void porAnchura(arbolBB);
	void verNivel(Nodo*,int);
	Nodo* busqueda(Nodo*,int);           
	int maximovalor(Nodo*);
};
int arbolBB::maximovalor(Nodo* r){
	int n;
	while(r->der!=NULL){
		r = r->der;
	}
	n=r->dato;
	return n;
}
class nodo1
{
	public:
	class arco;      
	int nombre;  
	nodo1* sgte;       
	arco* ady;       
	nodo1* p;        
	void insertarNodo(int);   
	void mostrarGrafo();   
	void insertarArco(int, int, float);    //Solicita los nombres del nodo inicial y final
						    //Si los encuentra llama a agregarArco() pra crear el arco
	void agregarArco(nodo1*,nodo1*,arco*, float);     //Crea el arco con los datos enviados por insertarArco()					
	void eliminarNodo();
	void borrarTodosArcos(nodo1*);
	void mostrarArcos();
	void eliminarArco(nodo1*, nodo1*);
};
class nodo1::arco
{
	public:
	nodo1* destino; 
	arco* sgte;
	float peso;
}; 
void nodo1::insertarNodo(int nombre)
{
	nodo1* t; 
	nodo1* nuevo=new nodo1;
	nuevo->nombre=nombre; 
	nuevo->sgte=NULL; 
	nuevo->ady=NULL; 
	if(p==NULL) 
	{
		p=nuevo; 
	}
	else
	{
		t=p; 
		while(t->sgte!=NULL)
		{
			t=t->sgte;
		}
		t->sgte=nuevo;
	}
}
void nodo1::mostrarGrafo()
{
	nodo1* t; 
	arco* ar;
	t=p;
	cout<<"Nodo\t|\tLista de adyacencia\n";
	while (t!=NULL) 
	{
		cout<<t->nombre<<"\t|"; 
		if (t->ady!=NULL) 
		{
			ar=t->ady; 
			while(ar!=NULL)
			{
				cout<<"  "<<ar->destino->nombre ; //<<"("<<ar->peso<<") "; //Muestra el nombre del nodo destino del arco
				ar=ar->sgte; //avanza al siguiente arco de la lista
			}
		}
		t=t->sgte; //Avanza al siguiente nodo
		cout<<endl;
	}
}

void arbolBB::crear(int nuevoDato) //Crea la raiz
{
	if (raiz==NULL) //Si no tiene raíz, crea el nodo raiz
	{
		raiz=new Nodo;
		raiz->dato=nuevoDato;   
		return;
	}
		Nodo *r=raiz;
		crear1(r, nuevoDato); //Llamada a la función recursiva
}
// Funcion recursiva
void arbolBB::crear1(Nodo *r, int nuevoDato)
{
	if (nuevoDato < r->dato) // Si el nuevoDato es menor que el dato raíz entonces se mueve a la izquierda
	{
		if(r->izq==NULL) // Si izq is NULL coloca el nuevoNodo a la izquierda.
		{
			Nodo *nuevoNodo;
			nuevoNodo=new Nodo;
			nuevoNodo->dato=nuevoDato;
			r->izq=nuevoNodo;
			r->izq->padre=r;    //aqui añadimos al nodo de la izquierda su padre que seria la raiz
			return;
		}
		crear1(r->izq, nuevoDato); // Si no mueve la raíz al nodo de la izquierda
	}
else 
	{
		if (nuevoDato> r->dato) // Si el nuevoDato es mayor que el dato raíz entonces se mueve a la derecha
		{
			if(r->der==NULL) // Si der is NULL coloca el nuevoNodo a la derecha.
			{
				Nodo *nuevoNodo=new Nodo;
				nuevoNodo->dato=nuevoDato;
				r->der=nuevoNodo;
				r->der->padre=r;  //aqui añadimos al nodo de la derecha su padre que seria la raiz
				return;
			}
			crear1(r->der, nuevoDato); // Si no mueve la raíz al nodo de la derecha
		}
	}
}

//Altura del nodo
int arbolBB::encontrarAltura(Nodo* raiz)
{
	if (raiz!=NULL)
		return max(encontrarAltura(raiz->izq),encontrarAltura(raiz->der))+1;
}
//Recorrer el arbol por anchura (por nivel)
void arbolBB::porAnchura(arbolBB a)
{
	int nivel=0,niveles;
	niveles=a.encontrarAltura(a.raiz)-1;
	while(nivel<=niveles)
	{
		verNivel(a.raiz,nivel);
		nivel++;
		cout<<endl;
	}
}
void arbolBB::verNivel(Nodo* raiz,int n)
{
	if (raiz!=NULL)
	{
		if(n==0)
			cout<<raiz->dato<<"\t";
		verNivel(raiz->izq,n-1);
		verNivel(raiz->der,n-1);
	}
}
//Busqueda de un nodo
Nodo* arbolBB::busqueda(Nodo* raiz,int datoBuscado)
{
	Nodo *r;
	Nodo *rpta=NULL;
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
//Funcion completar arbol
void completarArbol(arbolBB &a)
{
	int n,dato;
	cout<<"Ingrese la cantidad de nodos a insertar en el arbol binario de busqueda: ";
	cin>>n;
	for (int i=1; i<=n;i++)
	{
		cout<<"Dato "<<i<<": ";
		cin>>dato;
		a.crear(dato);
	}
}

int main()
{
   	arbolBB a;
   	int n;
   	nodo1* p=new nodo1;
	completarArbol(a);
	cout<<"Arbol creado: \n";
	a.porAnchura(a);
	n = a.maximovalor(a.raiz);
	for(int i=0; i<=n; i++){
		if(a.busqueda(a.raiz,i)!=NULL)
		  p->insertarNodo(a.busqueda(a.raiz, i)->dato);
		}		

    //insertando arcos
    Nodo* b =new Nodo;
    Nodo* c =new Nodo;
    for(int i=0; i<=n; i++)
    {
        b=a.busqueda(a.raiz,i);
		if(b!=NULL)
        {
            c = b->padre
            while(c->dato != a.raiz->dato)
            {
                insertarArco(b; c);
                c = c->padre;
            }
            insertarArco(b;c);
        }
	}

	cout<<"Grafo creado: \n";
	p->mostrarGrafo();
	return 0;
}