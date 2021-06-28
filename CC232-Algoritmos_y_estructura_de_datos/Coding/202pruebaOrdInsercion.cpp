#include<iostream>

using namespace std;

void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}
/*
void ordInsercion(int A[], int n)
{
    int i, j, k, z, l;
    for(i=1; i<n; i++){
        for(j=i-1; j>=0; j--){
            if(A[i]<A[j] && ((A[i]>A[j-1])||j==0)){
                z=A[i];
                for(k=i; k>j; k--)
                {
                    A[k]=A[k-1];
                }
                A[j]=z;
            }  
        }

        for(int l=0; l<n; l++){
        cout<<A[l]<<"|";
        }
        cout<<endl;
    }
}
*/

//con doble for

void ordInsercion(int A[], int n)
{
    int i, j, k, aux;
    for(i=1; i<n; i++){
        aux=A[i];
        for(j=i-1; j>=0 && A[j]>aux; j--){
                A[j+1]=A[j];
        }
        A[j+1]=aux;

        for(int l=0; l<n; l++){
        cout<<A[l]<<"|";
        }
        cout<<endl;
    }
}

int main(){
    int A[5]={50, 20, 40, 80, 30};
    //int A[9]={2, 4, 7, 3, 1, 8, 5, 9, 6};
    int n=5;
     for(int i=0; i<n; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;
    ordInsercion(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    }
    return 0;
}