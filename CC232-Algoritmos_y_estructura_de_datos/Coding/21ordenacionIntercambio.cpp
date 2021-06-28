#include<iostream>

using namespace std;

void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void ordIntercambio(int A[], int n)
{
    int i, j, k;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(A[i]>A[j]) intercambiar(A[i], A[j]);
            for(k=0; k<n; k++){
                cout<<A[k]<<"|";
            }
            cout<<endl;
        }
    }
}


int main(){
    int A[9]={2, 4, 7, 3, 1, 8, 5, 9, 6};
     int n=9;
     for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
    ordIntercambio(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    }
    return 0;
}