#include<iostream>

using namespace std;

void ordInsercion(int A[], int n)
{
    int i, j, aux;
    for(i=1; i<n; i++){
        j=i;
        aux=A[i];
        while(j>0 && aux<A[j-1]){
            A[j]=A[j-1];
            j--;
        }
        A[j]=aux;
    }
}

int main(){
    int A[5]={50, 20, 40, 80; 30};
     int n=5;
    ordSeleccion(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    return 0;

}
/*
void ordInsercion(int A[], int n)
{
    int i, j, aux;
    for(i=1; i<n; i++){
        j=i;
        aux=A[i];
        while(j>0 && aux<A[j-1]){ // con for
            A[j]=A[j-1];
            j--;
        }
        A[j]=aux;
    }
}
*/