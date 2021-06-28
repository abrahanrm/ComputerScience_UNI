#include <iostream>
using namespace std;
class Nodo
{
    private:
        int dato;
        Nodo* next;
    public:
        Nodo(int t)
        {
        dato = t;
        next = 0; // 0 es el puntero NULL en C++
        }
        Nodo(int p, Nodo* n) // crea el nodo y lo enlaza a n
        {
        dato = p;
        next = n;
        }
    int getDatoNodo() 
    {
        return dato;
    }
    Nodo* getNextNodo() 
    {
        return next;
    }
    void setNextNodo(Nodo* sgte)
    {
        next = sgte;
    }
    void setDatoNodo(int n)
    {
        dato = n; 
    }
};
//################

class Lista
{
    private:
        int dato;
        Nodo* head;
        Nodo* tail;
    public:
        Lista()
        {
            //head = new Nodo(0);
            //tail = new Nodo(0);
            head = NULL;
            tail=NULL;
        }

    Nodo* getHead(){
       return head;
    }

    void createList(int n) // devuelve el dato
    {
        for (int i = 0; i < n; i++)
        {
            cout<<"dato_nodo"<<i<<": ";
            cin>>dato;
            front(dato);
        }
    }

    void front(int n)
    {
       Nodo* tmp=new Nodo(0);
        tmp -> setDatoNodo(n);
        tmp -> setNextNodo(head);
        head = tmp;
    }

    void linkList(Nodo* a, Nodo* b){
        if (a->getNextNodo() == NULL)
            a->setNextNodo(b);
        else
        linkList(a->getNextNodo(),b);
    }
        
    void swap(Nodo* c, Nodo* d)
    {
        int temp = c->getDatoNodo();
        c->setDatoNodo(d->getDatoNodo());
        d -> setDatoNodo(temp);
    }

    void bubble_sort(Nodo* head)
    {
        int swapped;

        Nodo* lPtr; 
        Nodo* rPrt = NULL; 
        do
        {	
            swapped = 0;
            lPtr = head;
            while(lPtr->getNextNodo() != rPrt)
            {
                if (lPtr->getDatoNodo() > lPtr->getNextNodo()->getDatoNodo()) 
                {
                    swap(lPtr, lPtr->getNextNodo()); 
                    swapped = 1; 
                }
                lPtr = lPtr->getNextNodo();
            }
            rPrt = lPtr;

        }while(swapped);
    }

    void display(Nodo* head)
    {
        if(head == 0)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->getDatoNodo() << "|";
            display(head->getNextNodo());
        }
        
    }
};



int main()
{
    int nA, nB;
    cout<<"Lista #1:"<<endl;
    cout<<"nro de nodos:";
    cin>>nA;
    Lista listaA; Lista listaB; Lista listaAB;
    listaA.createList(nA);
    listaA.display(listaA.getHead());
    cout<<"Lista #2:"<<endl;
    cout<<"nro de nodos:";
    cin>>nB;
    listaB.createList(nB);
    listaB.display(listaB.getHead());
    //listaA.createList(nA+nB);
    listaA.linkList(listaA.getHead(),listaB.getHead());
    cout<<"Lista#1 + Lista#2: ";
    listaA.display(listaA.getHead());
    listaA.bubble_sort(listaA.getHead());
    cout<<"Bubble_sort:";
    listaA.display(listaA.getHead());
    return 0;
}