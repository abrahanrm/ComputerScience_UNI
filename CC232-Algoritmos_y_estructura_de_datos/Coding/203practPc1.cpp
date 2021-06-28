#include<iostream>

using namespace std;

void mostrar1();

void mostrar0();


int primNumeros[6];

string indCol[6]={"A", "B", "C", "D", "E", "F"};

int tabla1[4][6] = {
    {4, 0, 1, 5, 4, 1},
    {4, 4, 0, 5, 5, 5},
    {3, 2, 5, 0, 1, 0},
    {0, 5, 0, 4, 3, 4}
};


void intercambiar(int &x, int &y)
{
    double aux=x;
    x=y;
    y=aux;
}


void ordSeleccion(int n)
{
    int i, j, indMin;
    for(i=0; i<n-1; i++){
        indMin=i;
        for(j=i; j<n-1; j++){
            if(tabla1[0][indMin]>tabla1[0][j+1])
                indMin=j+1;
        }
        intercambiar(tabla1[0][i], tabla1[0][indMin]);
        intercambiar(tabla1[1][i], tabla1[1][indMin]);
        intercambiar(tabla1[2][i], tabla1[2][indMin]);
        intercambiar(tabla1[3][i], tabla1[3][indMin]);
    }
}

void mostrar1(){

    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++){
            if(tabla1[0][i] == primNumeros[j]) cout<<indCol[j]<<" | ";
        }
    }
    cout<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
        cout<<tabla1[i][j]<<" | ";
        }
        cout<<endl;
    }
}

void mostrar0(){
    for ( int i = 0; i < 6; i++)
    {
        cout<<indCol[i]<<" | ";
    }
    cout<<endl;

    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
        cout<<tabla1[i][j]<<" | ";
        }
        cout<<endl;
    }
}


int main(){
    for (int k = 0; k < 6; k++){
    primNumeros[k]=tabla1[0][k];
    }
    string opcion;
    cout<<"Generando"<<endl;
    mostrar0();
    cout<<"Ordenando por 1er numero"<<endl;
    ordSeleccion(6);
    cout<<endl;
    mostrar1();
 
    return 0;
}