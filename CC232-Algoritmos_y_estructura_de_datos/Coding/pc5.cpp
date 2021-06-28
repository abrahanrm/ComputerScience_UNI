#include<iostream>
#include<string>
using namespace std;
class nodo
{
    public:
	class arco;
	string nombre; //nombre del nodo
	nodo* sgte; //puntero al siguiente nodo del directorio
	arco* ady; //puntero hacia el primer arco del nodo
	nodo* p; //el primer nodo del directorio (la cabeza de la lista directorio)
	void insertarNodo(); //Inserta un nodo al directorio
	void mostrarGrafo(); //Muestra el grafo
	void insertarArco(); //Solicita nombres y en encuentra los nodos donde se insertara el arco
	void agregarArco(nodo* , nodo* , arco* ); //Crea el arco con los datos recibidos de insertarArco()
	void eliminarNodo();
	void borrarTodosArcos(nodo*);
	void mostrarArcos();
	void eliminarArco();
	void eliminarConexiones(nodo*);
	//void borrarArcosDestino();
	//void borrarArcosDestino(nodo*);
};
class nodo::arco
{
    public:
    nodo* destino; //puntero al nodo de llegada
    arco* sgte; //puntero al siguiente arco
};
void nodo::insertarNodo()
{
    nodo* t; //Contador que recorre todo el directorio
    nodo *nuevo=new nodo; //"nuevo" es el nodo que se insertara al directorio
    cout<<"Ingrese el nombre:";
    cin>>nuevo->nombre; //se asigna un nombre del nuevo nodo
    nuevo->sgte = NULL; //nuevo no apunta a ningun nodo
    nuevo->ady=NULL; //nuevo no apunta a ninguna arista
    if(p==NULL) //Si el primer nodo del directorio es NULL
    {
        p = nuevo; //"nuevo" es el primer nodo del directorio
        cout<<"Primer nodo del directorio\n";
    }
    else
    {
        t = p; //t se inicializa al primer nodo del directorio
        while(t->sgte!=NULL) //t avanza hasta que apunte a NULL
        {
            t = t->sgte; //Avanza al siguiente nodo
        }
        t->sgte = nuevo; //El ultimo nodo de la lista apunta a nuevo
        cout<<"Nodo ingresado\n";
    }
};

void nodo::mostrarGrafo()
{
    nodo* t; //Contador que recorre todo el directorio
    arco* ar; //Contador que recorre toda la lista de arcos
    t=p; //t se inicializa al primer nodo del directorio
    cout<<"Nodo\t|\tLista de adyacencia\n";
    while(t!=NULL) //t avanza por el directorio hasta que apunte a NULL
    {
        cout<<t->nombre<<"\t|";
        if(t->ady!=NULL) //Si el nodo no t tiene primer arco
        {
            ar=t->ady; //Obtiene el primer arco del nodo t
            while(ar!=NULL) //ar avanza por la lista arco del nodo t hasta que apunte a NULL
            {
                cout<<" "<<ar->destino->nombre; //Muestra el nombre del nodo destino del arco
                ar=ar->sgte; //Avanza al siguiente arco de la lista
            }
        }
    t=t->sgte; //Avanza al siguiente nodo
    cout<<endl;
    }
};

void nodo::insertarArco()
{
    string ini, fin; //Son los nombres del nodo inicio y final del arco
    arco* nuevo=new arco(); //"nuevo" es el arco que enlazara dos nodos
    nodo* aux; //Contador que recorre el directorio hasta encontar el nodo inicial
    nodo* aux2; //Contador que recorre el directorio hasta encontar el nodo final
    if(p==NULL) //Si el primer nodo del directorio es NULL
    {
        cout<<"Grafo vacio\n";
        return;
    }
    nuevo->sgte=NULL; //El "nuevo" arco no apunta a ningun arco
    cout<<"Ingrese el nombre del nodo inicio: ";
    cin>>ini;
    cout<<"Ingrese el nombre del nodo final: ";
    cin>>fin;
    aux=p; //aux se inicializa al primer nodo del directorio
    aux2=p; //aux2 se inicializa al primer nodo del directorio
    while(aux2!=NULL) //aux2 avanza hasta que apunte a NULL
    {
        if(aux2->nombre==fin) //Si encuentra un nodo con el mismo nombre "fin"
        {
        break; //Salta cuando encuentra un nodo con el mismo nombre
        }
        aux2=aux2->sgte; //Avanza al siguiente nodo
    }
    while(aux!=NULL) //aux avanza hasta que apunte a NULL
    {
        if(aux->nombre==ini) //Si encuentra un nodo con el mismo nombre “ini"
        {
            agregarArco(aux,aux2, nuevo); //Llama a la función agregarArco() que une con un arco los nodos aux y aux2
            return;
        }
        aux = aux->sgte; //Avanza al siguiente nodo
    }
};
// agregarArco une los nodos inicial y final
void nodo::agregarArco(nodo* aux, nodo* aux2, arco* nuevo)
{
    arco* q; //Contador que recorre todos los arcos de un nodo del directorio
    if(aux->ady==NULL) //Si el primer arco del nodo inicio aux es NULL
    {
        aux->ady=nuevo; //entonces el primer arco del nodo inicio aux apunta a "nuevo"
        nuevo->destino=aux2; //El destino del arco "nuevo" es el nodo final aux2
        cout<<"1er arco del nodo "<<aux->nombre<<endl;
    }
    else
    {
        q=aux->ady; //Si el nodo inicio aux ya tiene arco, inicializamos el puntero q al primer arco
        while(q->sgte!=NULL) //q avanza hasta que apunte a NULL
        {
            q=q->sgte;
        }
        q->sgte=nuevo; //El ultimo arco del nodo inicio aux apunta a "nuevo"
        nuevo->destino=aux2; //El destino del arco "nuevo" es el nodo final aux2
        cout<<"Arco agregado\n";
    }
};

void nodo::eliminarNodo()
{
	string nom; //El nombre del nodo que se borrara
	nodo* aux; //Contador que recorre el directorio buscando
	//el nodo a borrar
	nodo* ant; //Variable temporal que almacena el nodo
	//que se encuentra antes de aux
	aux=p; //El contador se inicializa con el primer nodo del directorio
	//En este caso la variable ant es NULL
	if(p==NULL)
	{
		cout<<"Grafo vacio\n";
		return;
	}
	cout<<"Ingrese en nombre de la variable:";
	cin>>nom;
	while(aux!=NULL) //Recorre todo el directorio
	{
		if(aux->nombre==nom) //Si el nombre de nodo es igual a "nom"
		{
			if(aux->ady!=NULL) //Y el nodo aux tiene arcos
		    	p->borrarTodosArcos(aux); //Eliminar todos los arcos
			p->eliminarConexiones(aux);
			if(aux==p) //Si el nodo a borrar es la cabeza de la lista
			{
				p=p->sgte; //La nueva cabeza es el siguiente nodo
				delete(aux); //Elimina el nodo cabeza anterior
				cout<<"Nodo cabeza eliminado\n";
				return;
			}
			else //Si el nodo a borrar no es la cabeza de la lista
			{
				ant->sgte = aux->sgte; //el nodo antes de aux ahora
				//apunta a lo que apuntaba aux
				delete(aux);
				cout<<"Nodo eliminado\n";
				return;
			}
		}
		else
		{
			ant=aux;
			aux=aux->sgte;
		}
	}
}
void nodo::eliminarConexiones(nodo *n){
        nodo *tem = p;
        string ini, fin;
        while(tem != NULL){
            if(tem->nombre != n->nombre)
            {
                        ini=tem->nombre; fin=n->nombre;
                        nodo *aux = p, *aux2 = p;
                arco *q, *r;
                while(aux2 != NULL){
                    if(aux2->nombre == fin)
                        break;
                    else
                        aux2 = aux2->sgte;
                }
                while(aux != NULL){
                    if(aux->nombre == ini){
                        q = aux->ady;
                        while(q != NULL){
                            if(q->destino == aux2){
                                if(q == aux->ady)
                                    aux->ady = aux->ady->sgte;
                                else
                                    r->sgte = q->sgte;
                                delete(q);
                                return;
                            }
                            r = q;
                            q = q->sgte;
                        }
                    }
                    aux = aux->sgte;
                }
            }
            tem = tem->sgte;
        }
    }




void nodo::mostrarArcos()
{
	nodo* aux; //Contador que recorre la lista directorio
	arco* ar; //Contador que recorre los arcos del nodo
	string nom; //nombre del nodo a analizar
	cout<<"Ingrese el nombre del nodo: ";
	cin>>nom;
	aux=p; //Inicializa el contador a la cabeza
	//de la lista directorio
	while(aux!=NULL)
	{
		if(aux->nombre==nom) //Si encuentra el nodo con
		//el mismo nombre
		{
			if(aux->ady==NULL) //Si la cabeza de la lista de
			//arcos es NULL
			{
				cout<<"El nodo no contiene arcos\n";
				return;
			}
			else
			{
				cout<<"Nodo\t|\tLista de adyacencia\n";
				cout<<aux->nombre<<"\t|"; //Imprime el nodo a analizar
				ar=aux->ady; //Obtiene el arco cabeza de la lista de arcos
				while(ar!=NULL)
				{
					cout<<ar->destino->nombre<<" "; //Imprime el nombre del
					//nodo destino del arco
					ar=ar->sgte; //Avanza al siguiente arco
				}
				cout<<endl;
				return;
			}
		}
		else
		aux=aux->sgte; //Avanza al siguiente nodo del directorio
	}
}
void nodo::eliminarArco()
{
	string ini, fin; //nodos inicial y final del arco
	nodo* aux; //Contador que buscara el nodo con nombre "ini"
	nodo* aux2; //Contador que buscara el nodo con nombre "fin"
	arco* q; //Contador que recorre la lista de arcos
	arco* r; //Variable temporal que recuerda al arco anterior a q
	cout<<"Ingrese el nombre del nodo inicio: ";
	cin>>ini;
	cout<<"Ingrese el nombre del nodo final: ";
	cin>>fin;
	aux=p; //Inicializa aux a la cabeza del directorio
	aux2=p; //Inicializa aux2 a la cabeza del directorio
	while(aux2!=NULL) //Localiza el nodo que tiene nombre "fin"
	{
		if(aux2->nombre==fin) //Ese nodo se asigna a aux2
		{
			break;
		}
		else
		aux2=aux2->sgte; //avanza al siguiente nodo
	}
	while(aux!=NULL) //Localiza el nodo que tiene nombre "ini"
	{
		if(aux->nombre==ini) //Ese nodo se asigna a aux
		{
			q=aux->ady; //Asigna a q la cabecera de la lista de arcos
			while(q!=NULL) //recorre la lista de arcos
			{
				if(q->destino==aux2) //Comprueba si el destino del arco es el nodo aux2
				{
					if(q==aux->ady) //Si q es el nodo cabecera de la lista de arcos
						aux->ady=aux->ady->sgte; //La nueva cabecera es el nodo al que apuntaba q
					else //Si q no es la cabecera de la lista de arcos
						r->sgte=q->sgte; //el nodo siguiente al nodo anterior a q sera el nodo que sigue a q, de esa forma hace un puente
					delete(q); //elimina el arco q
					cout<<"Arco  "<<aux->nombre<<"----->"<<aux2->nombre<<" Eliminado\n";
					return;
				}
				r=q; //Almacena el arco actual
				q=q->sgte; //Avanza al arco siguiente
			}
		}
		aux = aux->sgte; //Avanza al sigueinte nodo
	}
}

void nodo::borrarTodosArcos(nodo* aux){
        arco *q = aux->ady, *r;
        while(q->sgte != NULL){
            r = q;
            q = q->sgte;
            delete(r);
        }
}
int main()
{
	nodo* p=new nodo;
	//Insertando nodos
	p->insertarNodo();
	p->insertarNodo();
	p->insertarNodo();
	p->insertarNodo();
	p->insertarNodo();
	cout<<"Mostrando grafo:\n";
	p->mostrarGrafo();
	//Insertar arcos
	p->insertarArco();
	p->insertarArco();
	p->insertarArco();
	p->insertarArco();
	p->insertarArco();
	p->insertarArco();
	p->insertarArco();
	cout<<"Mostrando grafo:\n";
	p->mostrarGrafo();
	//p->eliminarArco();
	//p->borrarTodosArcos(nom);
	//p->borrarArcosDestino(nom);
	//p->borrarTodosArcos(nom);
	p->eliminarNodo();
    p->mostrarGrafo();

}