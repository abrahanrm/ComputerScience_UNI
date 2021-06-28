#include<iostream>

using namespace std;

void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

void imprimir(){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
}




void ordShell(int A[], int n)
{
    bool flag = true;
    int s = n/2, c=1;
    cout<<"Recorrido\tSalto\tIntercambios\tLista\n"
    while(s>0){
        cout<<c<<"\n";
        while(flag){
            flag=false;
            for(int i=s; i<n; i++){
                if(A[i-s]>A[i]){
                    intercambiar(A[i-s], A{i});
                    flag=true;
                }
            }
        }
    }
}

int main(){
    int A[5]={6, 1, 5, 2, 4};
    //int A[9]={2, 4, 7, 3, 1, 8, 5, 9, 6};
    ordShell(A, n);
    imprimir();
    return 0;
}