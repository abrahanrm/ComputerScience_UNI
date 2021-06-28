#include<iostream>

using namespace std;


int busqBinaria(int[], int, int);

int main(){
    int A[]={13, 44, 75, 100, 120, 275, 325, 510};
    int n=44, ind;
    ind = busqBinaria(A, 7, n);
    if(ind!=-1) cout<<"La clave se encuentra en el indice"<<ind<<endl;//ind!=-1
    else cout<<"La clave no se encontro\n";
    return 0;
}


int busqBinaria(int A[], int ind, int clave){
    int bajo, central, alto, valorCentral;
    bajo=0;
    alto=ind;
    while(bajo<=alto){
        central = (bajo+alto)/2;
        valorCentral=A[central];
        if(A[central]==clave)
            return central;
        else if(A[central]<clave)
                bajo=central+1;
            else
                alto=central-1;
    }
    return -1;
}
