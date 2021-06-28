#include<iostream>

using namespace std;


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void ordBurbujaM(int A[], int n)
{
    bool flag=true;
    int pasada, j;
    for(pasada=0; pasada<n-1 && flag; pasada++){
       flag=false;
       for(j=0; j<n-1-pasada; j++){
           if(A[j]>A[j+1]){
               flag=true;
               intercambiar(A[j],A[j+1]);
           }
       }
    }
}

int main(){
    int A[5]={50, 20, 40, 80, 30};
     int n=5;
    ordBurbujaM(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    }
    return 0;
}