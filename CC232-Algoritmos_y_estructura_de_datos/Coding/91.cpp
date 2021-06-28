typedef int TipoDato;
const int TAMPILA=20;
#include <iostream>
using namespace std;
class Pila
{
    private:
        int cima;
        TipoDato listaPila[TAMPILA];
    public:
        Pila()
        {   
            cima=-1;
        }
    void insertar(TipoDato);
    TipoDato quitar();
    bool pilaVacia();
    bool pilaLlena();
    void limpiarPila();
    TipoDato cimaPila();
    int mostrarCima();
    int tamanoPila();
};

//******************* funcion insertar ******************

bool Pila::pilaLlena()
{
    return cima==TAMPILA-1;
}

void Pila::insertar(TipoDato elemento)
{
    if (pilaLlena())
        cout<<"Desbordamiento (overflow)\n";
    else 
    {
        cima++;
        listaPila[cima]=elemento;
    }
}
//******************* funcion quitar *****************
bool Pila::pilaVacia()
{
    return cima==-1;
}

TipoDato Pila::quitar()
{
    TipoDato x, n=NULL;
    if (pilaVacia())
    {
        cout<<"Desbordamiento negativo (underflow)";
        return n;
    }
    else
    {
        x=listaPila[cima--];
        return x;
    }   
}

//******************* funcion mostrarPila ****************
int Pila::mostrarCima()
{
    return cima;
}

void mostrarPila(Pila &pila){
    TipoDato x;
    cout<<"\nElementos de la pila\n";
    while(!pila.pilaVacia())
    {
        x=pila.quitar();
        cout<<x<<" ";
        cout<<"Posicion cima Pila: "<<pila.mostrarCima()<<endl;
    }
}

//*********** funcion completarPila **************
void completarPila(Pila &pila)
{
    TipoDato x;
    int n, i;
    cout<<"Cuantos elementos ingresara (Mac. 6): ";
    cin>>n;
    cout<<"Digite el elemento y presione Enter\n";
    for (i = 0; i < n; i++)
    {
        cout<<"Indice "<<i<<" : ";
        cin>>x;
        pila.insertar(x);
        cout<<"Cima: "<<pila.mostrarCima()<<endl;
    }
    
}

// funciones tamanoPila, cimaPila, limpiarPila

int Pila::tamanoPila()
{
    return TAMPILA;
}

TipoDato Pila::cimaPila()
{
    if(pilaVacia())
        cout<<"Pila vacia, no hay elemetos\n";
    else
        return listaPila[cima];
    
}

void Pila::limpiarPila()
{
    cima=-1;
}
//**********************************************************+



//Prueba 1 (llenado de pila)
/*int main()
{
    Pila pila;
    pila.insertar(10);
    pila.insertar(11);
    pila.insertar(12);
    mostrarPila(pila);
    return 0;
}
*/

//Prueba 2 (creacion de una pila)
/*
int main()
{
    Pila pila;//crea una pila vacía
    completarPila(pila);
    mostrarPila(pila);
    return 0;
}
*/

//Prueba 3 (palindromo)
int main()
{
    Pila pilaChar; // crea pila vacía
    TipoDato ch; //Cantidad de caracteres de la palabra
    bool esPal; //Devuelve true si es palíndromo
    string palabra;
    string palabraSE;
    cout << "Escriba la palabra verificar si es palindromo:\n";
    getline(cin,palabra);
    for(int i = 0; i < palabra.length();i++)
    {
        char c;
        c = toupper(palabra[i]);
        if (c!=' ')
            {
            pilaChar.insertar(c);
            palabraSE+=c;
            }
    }
    // se comprueba si es palíndromo
    esPal = true;
    for (int i = 0; esPal && !pilaChar.pilaVacia(); i++)
    {
        char c;
        c = pilaChar.quitar();
        esPal = palabraSE[i] == c;
    }
    if (esPal)
    cout<< "La palabra " << palabra << "\nes un palindromo\n";
    else
    cout<< "La palabra " << palabra << "\nno es un palindromo\n";
    return 0;
}
