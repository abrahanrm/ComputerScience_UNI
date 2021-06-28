#include<iostream>

using namespace std;

//void intercambiar();


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void imprimir(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
}

void ordQuicksort(int A[], int primero, int ultimo)
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
    int A[12]={79, 21, 15, 99, 88, 65, 75, 85, 76, 46, 84, 24};
    //int A[9]={2, 4, 7, 3, 1, 8, 5, 9, 6};
    int n=12;
    imprimir(A, n);
    ordQuicksort(A, 0, n-1);
    imprimir(A, n);
    return 0;
}