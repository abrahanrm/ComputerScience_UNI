#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void quickSortMain(char items[][10], int count);
void quickSort(char items[][10], int left, int right);
void listar();
int buscar();
void insertar();
int eliminar();


string paterno, materno, nombre;
int indAlum, nota, pos;
char Paterno[50][10];
char Materno[50][10];
char Nombre[50][10];
int Nota[50];

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
    return 0;
}


void insertar(){
    cout<<"Paterno"<<":";
    cin>>paterno; cout<<endl;
    cout<<"Materno"<<":";
    cin>>materno; cout<<endl;
    cout<<"Nombre"<<":";
    cin>>nombre; cout<<endl;
    cout<<"Nota"<<":";
    cin>>nota; cout<<endl;
    Paterno[indAlum]=paterno;
    Materno[indAlum]=materno;
    Nombre[indAlum]=nombre;
    Nota[indAlum]=nota;
    indAlum+1;
    cout<<"Ordenando..."<<endl;
    cout<<"Primer criterio: Paterno"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<"Segundo criterio: Materno"<<endl;
    quickSortMain(Materno, indAlum);
    listar();
    cout<<"Tercer criterio: Nombre"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<"Cuarto criterio: Nota"<<endl;
    quicksort(Notas, 0, indAlum-1);
    listar();
}

void eliminar(){
    cout<<"Paterno"<<":";
    cin>>paterno; cout<<endl;
    cout<<"Materno"<<":";
    cin>>materno; cout<<endl;
    cout<<"Nombre"<<":";
    cin>>nombre; cout<<endl;
    cout<<"Nota"<<":";
    cin>>nota; cout<<endl;
    pos=buscar();
    for(int i=pos; i<indAlum; i++){
        Paterno[i]=Paterno[i+1];
        Materno[i]=Materno[i+1];
        Paterno[i]=Paterno[i+1];
        Nombre[i]=Nombre[i+1];
        Nota[i]=Nota[i+1;]
    }
    indAlum=indAlum-1;

    cout<<"Ordenando..."<<endl;
    cout<<"Primer criterio: Paterno"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<"Segundo criterio: Materno"<<endl;
    quickSortMain(Materno, indAlum);
    listar();
    cout<<"Tercer criterio: Nombre"<<endl;
    quickSortMain(Paterno, indAlum);
    listar();
    cout<<"Cuarto criterio: Nota"<<endl;
    quicksort(Notas, 0, indAlum-1);
    listar();
}
/*
void eliminar(){
    int pos;
    listar();
    cout<<"Cual producto desea eliminar"<<indEle<<":";
    cin>>artefacto;
    pos=buscar();
    for(int i=pos; i<indAlum; i++){
        Paterno[i]=Paterno[i+1];
        Materno[i]=Materno[i+1];
        Paterno[i]=Paterno[i+1];
        Nombre[i]=Nombre[i+1];
        Nota[i]=Nota[i+1;]
    }
    indAlum=indAlum-1;
    listar();
}
*/
int buscar(){
    for(int i=0; i<indAlum; i++){
        if((Paterno[i]==paterno)&&(Materno[i]==materno)&&(Nombre[i]==nombre)&&(Nota[i]==nota))
         pos=i;
    }
    return pos;
}


void listar(){
    cout<<"Paterno\tMaterno\tNombre\tNota\n";
    for(int i=0; i<indAlum; i++){
        cout<<Paterno[i]<<"\t"<<Materno[i]<<"\t"<<Nombre[i]<<"\t"<<Nota[i]<<endl;
    }
}


/*
int main(void)
{
  //int i=0;
  cout<<"nombre1:";
  cin>>str[0]; 
  cout<<"nombre2:";
  cin>>str[1];
  cout<<"nombre3:";
  cin>>str[2]; 
  cout<<"nombre4:";
  cin>>str[3];


  quickSortMain(str, 4);

  for(int i=0; i<4; i++) {
     printf("%s ", str[i]);
  }
  return 0;
}

*/

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


