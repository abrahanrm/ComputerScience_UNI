#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;


void quickSortMain(char items[][10], int count);
void quickSort_str(char items[][10], int left, int right);
void quicksort(int A[], int primero, int ultimo);
void listar();
void insertar();



string paterno, materno, nombre;
int nota, pos;
int indAlum=0;
char Paterno[50][10];
char Materno[50][10];
char Nombre[50][10];
int Nota[50];

int main(){
    int opcion;
    do{
    cout<<"Que desea hacer?\n";
    cout<<"1. Ingresar alumno\n";
    cout<<"2. Salir\n";
   
    cin>>opcion;
    switch(opcion){
        case 1:
            insertar();
            break;
        case 2:
            cout<<"Buenas noches";
            break;
        
        default:
            cout<<"No es una opcion";

      }
    }  while(opcion!=2);
    return 0;
}


void insertar(){
    cout<<"Paterno"<<":";
    cin>>Paterno[indAlum];
    cout<<"Materno"<<":";
    cin>>Materno[indAlum];
    cout<<"Nombre"<<":";
    cin>>Nombre[indAlum]; 
    cout<<"Nota"<<":";
    cin>>Nota[indAlum]; 
    indAlum=indAlum+1;

    cout<<"Lista sin ordenamiento"<<endl;
    listar();
    cout<<endl;
    cout<<"Lista con ordenamiento"<<endl;
    cout<<"Primer criterio: Paterno"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<endl;
    cout<<"Segundo criterio: Materno"<<endl;
    quickSortMain(Materno, indAlum);
    listar();
    cout<<endl;
    cout<<"Tercer criterio: Nombre"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<endl;
    cout<<"Cuarto criterio: Nota"<<endl;
    quicksort(Nota, 0, indAlum-1);
    listar();
}

void listar(){
    cout<<setw(20)<< "Paterno"<<setw(20)<< "Materno"<<setw(20)<<"Nombre"<<setw(20)<<"Nota"<<endl;
    for(int i=0; i<indAlum; i++){
        cout<<setw(20)<< Paterno[i] <<setw(20)<<  Materno[i]<<setw(20)<<Nombre[i]<<setw(20)<<Nota[i]<<endl;
    }
}


void quickSortMain(char items[][10], int count)
{
  quickSort_str(items, 0, count-1);
}

void quickSort_str(char items[][10], int left, int right)
{
  int i, j;
  char *x;
  char temp[10];

  i = left;
  j = right;
  x = items[(left+right)/2];

  do {
    while((strcmp(items[i],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(items[j],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
      strcpy(temp, items[i]);
      strcpy(items[i], items[j]);
      strcpy(items[j], temp);
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j) {
     quickSort_str(items, left, j);
  }
  if(i < right) {
     quickSort_str(items, i, right);
  }
}


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}


void quicksort(int A[], int primero, int ultimo)
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
        quicksort(A, primero, j);
    }
    if(i<ultimo){
        quicksort(A, i, ultimo);
    }
}


