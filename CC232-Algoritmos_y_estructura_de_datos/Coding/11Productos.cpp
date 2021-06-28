#include<iostream>

using namespace std;

string Productos[25];
int Stock[25];
int indEle=0;
string artefacto;
int cant;
int pos;

void insertar();
void modificar();
void eliminar();
void consulta();
void incrementar();
void estadistica();
void listar();
int buscar();


int main(){
    string artefacto;
    int cant, opcion;
    do{
    cout<<"Que desea hacer? ";
    cout<<"1. Insertar\n";
    cout<<"2. Modificar\n";
    cout<<"3. Eliminar\n";
    cout<<"4. Consulta\n";
    cout<<"5. Incrementar\n";
    cout<<"6. Estadistica\n";
    cout<<"7. Listar\n";
    cout<<"8. Salir\n";
    cin>>opcion;
    switch(opcion){
        case 1:
            insertar();
            break;
        case 2:
            modificar();
            break;
        case 3:
            eliminar();
            break;
        case 4:
            consulta();
            break;
        case 5:
            incrementar();
            break;
        case 6:
            estadistica();
            break;
        case 7:
            listar();
            break;
        case 8:
            cout<<"Buenas noches";
            break;
        
        default:
            cout<<"No es una opcion";

      }
    }  while(opcion!=8);
    return 0;
}


void insertar(){
    cout<<"Ingrese el artefacto"<<indEle<<":";
    cin>>artefacto;
    cout<<"Ingrese la cantidad"<<indEle<<":";
    cin>>cant;
    Productos[indEle]=artefacto;
    Stock[indEle]=cant;
    indEle=indEle+1;
}

void modificar(){
    listar();
    cout<<"Cual producto desea modificar"<<indEle<<":";
    cin>>artefacto;
    cout<<"Ingrese la nueva cantidad"<<indEle<<":";
    cin>>cant;
    pos=buscar();
    Stock[pos]=cant;
    listar();
}

void eliminar(){
    int pos;
    listar();
    cout<<"Cual producto desea eliminar"<<indEle<<":";
    cin>>artefacto;
    pos=buscar();
    for(int i=pos; i<indEle; i++){
        Productos[i]=Productos[i+1];
        Stock[i]=Stock[i+1];
    }
    indEle=indEle-1;
    listar();
}

void consulta(){
    cout<<"¿Cual producto desea consultar?"<<indEle<<":";
    cin>>artefacto;
    pos=buscar();
    cout<<"Producto\tStock\n";
    cout<<artefacto<<"\t"<<Stock[pos]<<endl;
}

void incrementar(){
    cout<<"Cual producto desea incrementar"<<indEle<<":";
    cin>>artefacto;
    cout<<"Ingrese las unidades a incrementar"<<indEle<<":";
    cin>>cant;
    pos=buscar();
    Stock[pos] = Stock[pos]+cant;
    listar();
}


void estadistica(){
    listar();
    int suma=0;
    cout<<"Cantidad de productos: "<<indEle<<endl;
    for(int i=0; i<indEle; i++){
        suma = suma + Stock[i];
    }
    cout<<"Suma de stock: "<<suma<<endl;
}

    


void listar(){
    cout<<"Productos\tStock\n";
    for(int i=0; i<indEle; i++){
        cout<<Productos[i]<<"\t"<<Stock[i]<<endl;
    }
}

int buscar(){
    for(int i=0; i<indEle; i++){
        if(Productos[i]==artefacto)
         pos=i;
    }
    return pos;
}