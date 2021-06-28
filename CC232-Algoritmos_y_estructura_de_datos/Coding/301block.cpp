#include<iostream>

using namespace std;

string Paterno[50];
string Materno[50];
string Nombre[50];
int nota[50];

struct Alumno
{
    string paterno;
    string materno;
    string nombre;
    int nota;
}


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void imprimir(int Alumno a, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
}

void quick_sort(int A[], int primero, int ultimo)
{
    int i, j, central;
    int pivote;
    central=(primero+ultimo)/2;
    pivote=A[central];
    i=primero;
    j=ultimo;
    do{
        while (A[i]<pivote) i++;
        while (A[j]>pivote) j--;
        if(i<=j){
            intercambiar(A[i],A[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(primero<j){
        ordQuicksort(A, primero, j);
    }
    if(i<ultimo){
        ordQuicksort(A, i, ultimo);
    }
}

void quick_sort_string(char A[], int primero, int ultimo)
{
    int i, j, central;
    int pivote;
    central=(primero+ultimo)/2;
    pivote=A[central];
    i=primero;
    j=ultimo;
    do{
        while (A[i]<pivote) i++;
        while (A[j]>pivote) j--;
        if(i<=j){
            intercambiar(A[i],A[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(primero<j){
        ordQuicksort(A, primero, j);
    }
    if(i<ultimo){
        ordQuicksort(A, i, ultimo);
    }
}


int main(){
    string artefacto;
    int cant, opcion;
    do{
    cout<<"Que desea hacer? ";
    cout<<"1. Ingresar alumno\n";
    cout<<"2. Eliminar alumno\n";
    cout<<"3. Salir\n";
   
    cin>>opcion;
    switch(opcion){
        case 1:
            insertar();
            break;
        case 2:
            eliminar();
            break;
        case 3:
            cout<<"Buenas noches";
            break;
        
        default:
            cout<<"No es una opcion";

      }
    }  while(opcion!=3);
    return<< 0;
}


void insertar(){
    cout<<"Paterno"<<":";
    cin>>Paterno; cout<<endl;
    cout<<"Materno"<<":";
    cin>>Materno; cout<<endl;
    cout<<"Nombre"<<":";
    cin>>Nombre; cout<<endl;
}

void eliminar(){
    cout<<"Paterno"<<":";
    cin>>Paterno; cout<<endl;
    cout<<"Materno"<<":";
    cin>>Materno; cout<<endl;
}

void listar(){
    cout<<"Paterno\tMaterno\tNombre\tNota\n";
    for(int i=0; i<indEle; i++){
        cout<<Paterno[i]<<"\t"<<Materno[i]<<endl;
    }
}