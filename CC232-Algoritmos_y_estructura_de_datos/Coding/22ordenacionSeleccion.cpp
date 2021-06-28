#include<iostream>

using namespace std;


void intercambiar()
{
    double aux=x;
    x=y;
    y=aux;
}

void ordSeleccion()
{
    int indMenor, i, j;
    for(i=0; i<n-1; i++){
        indMenor=i;
        for(j=1+i; j<n; j++){
            if(a[j]<a[indMenor])
                indMenor=j;
        if(indMenor!=i)
            intercambiar(A[i],A[indMenor]);
        }

    }
}

int main()
{
	int A[5]={51,21,39,80,36};
	int n=5;
	ordSeleccion(A,n);
	for (int i=0;i<n;i++)
		cout<<A[i]<<endl;	
}



