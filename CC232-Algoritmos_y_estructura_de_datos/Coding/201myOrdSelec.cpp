#include<iostream>

using namespace std;

void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void ordSeleccion(int A[], int n)
{
    int i, j, k, indMin;
    bool flag;
    for(i=0; i<n-1; i++){
        indMin=i;
        flag=true;
        for(j=i; j<n && flag; j++){
           if(A[indMin] > A[j]){
             indMin=j;  
           }
        }
        intercambiar(A[indMin], A[i]);
        for(k=0; k<n; k++){
        cout<<A[k]<<"|";
        }
        cout<<endl;
    }
}


int main(){
    int A[5]={51, 21, 39, 80, 36};
     int n=5;
     for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
    ordSeleccion(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    }
    return 0;
}