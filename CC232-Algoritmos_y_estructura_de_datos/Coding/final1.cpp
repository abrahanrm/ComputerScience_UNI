#include<iostream>
#include<string>
using namespace std;
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
    void agregarArco(nodoG* , nodoG* , arcoG* ); 
};
class nodoG::arco
{
    public:
    nodoG* destino; 
    arco* sgte; 
};
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

int main()
{
    nodoG* p=new nodoG;
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
}