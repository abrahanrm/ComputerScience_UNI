class Nodo
{
    private:
        int data;
        Nodo* next;
    public:
        Nodo(int t)
        {
        data = t;
        next = 0; // 0 es el puntero NULL en C++
        }
        Nodo(int p, Nodo* n) // crea el nodo y lo enlaza a n
        {
        data = p;
        next = n;
        }
    int getDataNode() // devuelve el dato
    {
        return data;
    }
    Nodo* getNextNode() // devuelve la dirección
    {
        return next;
    }
    void setNextNode(Nodo* sgte)
    {
        next = sgte; //establece la direccion
    }
};

#include <iostream>
using namespace std;
int main()
{
Nodo* nodo1;
Nodo* nodo2;
Nodo* nodo3;
Nodo* nodo4;
nodo1=new Nodo(10);
nodo2=new Nodo(20,nodo1);
nodo3=new Nodo(30,nodo2);
nodo4=new Nodo(40,nodo3);
//Muestra direcciones de los nodos
cout<<"direccion1= "<<nodo1<<endl;
cout<<"direccion2= "<<nodo2<<endl;
cout<<"direccion3= "<<nodo3<<endl;
cout<<"direccion4= "<<nodo4<<endl<<endl;
//Muestra el dato de los nodos
cout<<"dato1= "<<nodo1->getDataNode()<<endl;
cout<<"dato2= "<<nodo2->getDataNode()<<endl;
cout<<"dato3= "<<nodo3->getDataNode()<<endl;
cout<<"dato4= "<<nodo4->getDataNode()<<endl<<endl;
//Muestra los enlaces de los nodos (direccion de los nodos al cual enlaza)
cout<<"enlace1= "<<nodo1->getNextNode()<<endl;
cout<<"enlace2= "<<nodo2->getNextNode()<<endl;
cout<<"enlace3= "<<nodo3->getNextNode()<<endl;
cout<<"enlace4= "<<nodo4->getNextNode()<<endl<<endl;
//Cambia el enlace de un nodo
nodo1->setNextNode(nodo4);
//Muestra los enlaces de los nodos
cout<<"enlace1= "<<nodo1->getNextNode()<<endl;
cout<<"enlace2= "<<nodo2->getNextNode()<<endl;
cout<<"enlace3= "<<nodo3->getNextNode()<<endl;
cout<<"enlace4= "<<nodo4->getNextNode()<<endl<<endl;
return 0;
}