#include <iostream>
using namespace std;
int n;
int* temporal;


void mezclaLista(int a[],int Izq,int Centro,int Der)
{
    temporal=new int [n];
    int i,j,k;
    i=k=Izq;
    j=Centro+1;
    //Compara y copia el menor al temporal
    while(i<=Centro && j<=Der)
    {
    if (a[i]<=a[j]) {
        temporal[k]=a[i];
        k++;
        i++;
    }else{
        temporal[k]=a[j];
        k++;
        j++;
    }
    }
    //Lo que sobra se copia al final del temporal
    while (i<=Centro)
    {
    temporal[k++]=a[i++];
    }
    while (j<=Der)
    {
    temporal[k++]=a[j++];
    }
    //Copia el temporal al vector a
    for(k=Izq; k<=Der;k++)
    a[k]=temporal[k];

}

void imprimir(int a[])
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<"|";
    cout<<endl;
}
int main()
{
int vector[]={2,4,6,7,9,1,3,5,8};
n=sizeof(vector)/sizeof(int);
mezclaLista(vector,0,4,8);
imprimir(vector);
return 0;
}