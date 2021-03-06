#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Nodo
{
    private:
        T dato;
        Nodo<T>* enlace;
    public:
    Nodo(T t)
    {
        dato=t;
        enlace=NULL;
    }
    Nodo(T t, Nodo<T>* n)
    {
        dato=t;
        enlace=n;
    }
    T datoNodo()
    {
        return dato;
    }
    Nodo<T>* enlaceNodo()
    {
        return enlace;
    }
    void ponerEnlace(Nodo<T>* sgte)
    {
        enlace=sgte;
    }
    void ponerDato(T sgte)
    {
        dato=sgte;
    }
};
//------------------------------------------------------------------------------
//Clase fecha
class Fecha
{
    private:
        int month;
        int day;
        int year;
    public:
        
        void setFecha(int d, int m, int y)
        {
            day=d;
            month=m;
            year=y;
        }
        void setMonth(int m){
            month=m;
        }
        int getMonth(){
            return month;
        }
        void setDay(int d){
            day= d;
        }
        int getDay(){
            return day;
        }
        void setYear(int y){
            year=y;
        }
        int getYear(){
            return year;
        }
        
        bool dateValid(int d, int m, int y)
        {
            bool validation = true;
            if(!(y >= 1900 && y <=2100))
                validation = false;    
            if(d < 1)
                validation = false;
            switch(m)
            {
            case 2:
                if(leapYear(y))
                    if(d > 29)
                        validation = false;
                else
                    if(d > 28)
                        validation = false;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(d > 31)
                    validation = false;
                break;
            case 4: case 6: case 9: case 11:
                if(d > 30)
                    validation = false;
                break;
            default: // the month is not between 1 and 12
                validation = false;
                break;
            }
            return validation;
        }
        
        bool leapYear(int y)
        {
            return(y % 100 != 0 && y % 4 == 0) || (y % 400 == 0);
        }
};
//------------------------------------------------------------------------------------------
//La clase lista
class Lista
{
    private:
        Nodo<Fecha>* primero;
    public:
        Lista()
        {
            primero=NULL;
        }
        void startLista(Fecha );
        void visualizarLista();
        void insertarCabezaLista(Fecha );
        Nodo<Fecha>* primerNodo();
        Nodo<Fecha>* ultimoNodo();
        void swap(Nodo<Fecha>* c, Nodo<Fecha>* d);
        void bubble_sort(Nodo<Fecha>* head);
};

//Crear una lista
void Lista::startLista(Fecha f)
{
    primero=new Nodo<Fecha>(f,primero);
}

Nodo<Fecha>* Lista::primerNodo()
{
    return primero;
}

//Visualizar lista
void Lista::visualizarLista()
{
    Nodo<Fecha>* indice;// contador
    //cout<<"Direccion del nodo\tDato\tA donde apunta"<<endl;
    for(indice=primero; indice!=NULL; indice=indice->enlaceNodo()){
        cout<<indice<<"\t\t"<<indice->datoNodo().getDay()<<"/"<<indice->datoNodo().getMonth()<<"/"<<indice->datoNodo().getYear()<<"\t\t"<<indice->enlaceNodo()<<endl; 
    }
};

//insercion en la cabeza de la lista
void Lista::insertarCabezaLista(Fecha dato)
{
    Nodo<Fecha>* nuevo;
    nuevo=new Nodo<Fecha>(dato);
    nuevo->ponerEnlace(primero);
    primero=nuevo;
}

//Encuentra el ultimo nodo
Nodo<Fecha>* Lista::ultimoNodo()
{
    Nodo<Fecha>* p=primero;
    while(p->enlaceNodo()!=NULL)
    {
        p=p->enlaceNodo();
    }
    return p;
}

//************************************
void Lista::swap(Nodo<Fecha>* c, Nodo<Fecha>* d)
    {
        Fecha temp = c->datoNodo();
        c->ponerDato(d->datoNodo());
        d -> ponerDato(temp);
    }

void Lista:: bubble_sort(Nodo<Fecha>* head)
    {
        int swapped;
        Nodo<Fecha>* lPtr;
        Nodo<Fecha>* rPrt = NULL;

        if(head == NULL)
            return;
        do
        {	
            swapped = 0;
            lPtr = head;
            
            while(lPtr->enlaceNodo() != rPrt)
            {
                if (lPtr->datoNodo().getYear() > lPtr->enlaceNodo()->datoNodo().getYear()) 
                {
                    swap(lPtr, lPtr->enlaceNodo()); 
                    swapped = 1; 
                }
                
                if ( (lPtr->datoNodo().getYear() == lPtr->enlaceNodo()->datoNodo().getYear()) && lPtr->datoNodo().getMonth() > lPtr->enlaceNodo()->datoNodo().getMonth()) 
                {
                    swap(lPtr, lPtr->enlaceNodo()); 
                    swapped = 1; 
                }
                if ( (lPtr->datoNodo().getYear() == lPtr->enlaceNodo()->datoNodo().getYear()) && (lPtr->datoNodo().getMonth() == lPtr->enlaceNodo()->datoNodo().getMonth()) && lPtr->datoNodo().getDay() > lPtr->enlaceNodo()->datoNodo().getDay()) 
                {
                    swap(lPtr, lPtr->enlaceNodo()); 
                    swapped = 1; 
                }

                lPtr = lPtr->enlaceNodo();
            }
            rPrt = lPtr;
        }while(swapped);
    }
//***********************************

int main()
{
    Lista miLista;
    int n, d, m, y;
    int i=1;
    cout<<"Cuantas fechas desea ingresar?: ";
    cin>>n;

    do{
        Fecha fecha;
        cout<<"Ingrese fecha "<<i<<" de "<<n<<":"<<endl;
        cout<<"Day: ";
        cin>>d;
        cout<<"Month: ";
        cin>>m;
        cout<<"Year: ";
        cin>>y;
        fecha.setFecha(d, m, y);
        if(fecha.dateValid(d, m, y)){
            if(i==1){
                miLista.startLista(fecha); i++;// primerNodo()->ponerDato(fecha); i++; 
            }
            else{
                miLista.insertarCabezaLista(fecha);
                i++;
            }
        }
        else
            cout<<"Fecha invalida. Ingrese de nuevo."<<endl;
    }while(n!=0 && i<=n);
    miLista.visualizarLista();
    miLista.bubble_sort(miLista.primerNodo());
    cout<<"\t\t"<<">> Buble_sort"<<endl;
    miLista.visualizarLista();
    return 0;
}

