#include<iostream>

using namespace std;


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}

/*
void ordBurbujaM(int A[], int n)
{
    //bool flag=true;
    int pasada, j;
    for(pasada=0; pasada<n-1; pasada++){
       for(j=0; j<n-1-pasada; j++){
           if(A[j]>A[j+1]){
                intercambiar(A[j],A[j+1]);
           }
       }
    }
}
*/

/*
Fabio Alberto Pantoja Limache20:34
void ordBurbujaM(int A[],int n){
	bool flag1 = true;bool flag2 = true;bool flag = true;int pasada,j;
	for(pasada=0;pasada<n-1 && flag;pasada++){
		flag1=false;
		for(j=0;j<n-1-pasada;j++)
			if(A[j]>A[j+1]){
				flag1=true;
				intercambiar(A[j],A[j+1]);
			}
		invertir(A,n);
		for(j=0;j<n-1-pasada;j++)
			if(A[j]>A[j+1]){
				flag2=true;
				intercambiar(A[j],A[j+1]);
			}
		invertir(A,n);
		flag = flag1||flag2;
		if(flag)
			continue;
	}
}

void invertir(int A[],int n){
	for(int i = 0;i<n;i++)
		A[i]=-A[i];
}
*/



void ordBurbujaM(int A[], int n)
{
    //bool flag=true;
    int pasada, j;
    for(pasada=0; pasada<n-1; pasada++){
        for(j=0; j<n-1-pasada; j++){
            if(A[j]>A[j+1]){
                intercambiar(A[j],A[j+1]);
            }
        }
        
        for(j=0; j<n-1-pasada; j++){
            if(A[j]<A[j+1]){
                intercambiar(A[j],A[j+1]);
            }
        }
    }
}


int main(){
    int A[7]={2, 5, 3, 9, 7, 4, 6};
     int n=7;
    ordBurbujaM(A,n);
    for(int i=0; i<n; i++){
        cout<<A[i]<<endl;
    }
    return 0;
}