/*#include <iostream>

using namespace std;

int main(){
    int *p,v;
    v=7;
    p=&v;
    *p = *p +3;
    cout<<"Direccion de v= "<<p<<end1;
    cout<<"Direccion de v= "<<&v<<end1;
    cout<<"Valor de v= "<<v<<end1;
    cout<<"Valor de v= "<<*p<<end1;
    return 0;
}
*/

/*#include <iostream>

using namespace std;

int main(){
    int *p1,*p2;
    p1=new int(7); //variable dinamica
    p2=new int;
    cin>>*p2;
    *p1=*p1+*p2;
    cout<<*p1;
    return 0;
}
*/


/*
#include <iostream>

using namespace std;

int main(){
    cout<<"Asigna memoria"<<end1;
    int *p1;
    p1=new int(7);
    cout<<p1<<end1;
    cout<<*p1<<end1;
    cout<<&p1<<end1;
    cout<<"Libera memoria"<<end1;
    delete p1;
    cout<<p1<<end1;
    cout<<*p1<<end1;
    cout<<&p1<<end1;
    return 0;

}
*/


//matriz
/*
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];
    A[0]=7;
    cout<<A[0];
    return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main(){
    int *p, n;
    cin>>n;
    p=new int[n];//arreglo dinamico ,  p=new int[n]{} (se lleba de ceros la matriz)
    p[0]=7;
    cout<<p[0]<<end1;
    //borra en memoria y libera
    delete [] p
    return 0;
}
*/

//Similar al anterior 
/*
#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *p=new int[n];// variacion aqui
    p[0]=7;
    cout<<p[0]<<end1;
    //borra en memoria y libera
    delete [] p
    return 0;
}
*/

/*
//array dinamico multidimensionales
#include <iostream>

using namespace std;

int main(){
    int d1, d2, i, j;
    //cout<<"Ingrese dimensiones d1 y d2: "<<end1;
    cin>>d1>>d2;
    int **m;//puntero de punteros; m apunta a un espacio de memoria que contiene varias direcciones
    m = new int*[d1];
    for(i=0; i<d1; i++){
        m[i]=new int[d2];
    }
    cout<<"Escriba los datos"<<end1;
    for(i=0; i<d1; i++){
        for(j=0; j<d2; j++){
            cin>>m[i][j];
        }
    }
    cout<<"La matriz es:"<<end1;
    for(i=0; i<d1; i++){
        for(j=0; j<d2; j++){
            cout<<m[i][j]<<"";
        }
    }
    //liberando memoria
    for(i=0; i<d1; i++){
        delete [] m[i];
    }
    delete [] m;
    return 0;
}*/

//Clases y objetos

#include<iostream>

using namespace std;

class Punto{
    private:
        float x, y, z;
    public:
        float ObtenerX(){return x;} //selectores
        float ObtenerY(){return y;}
        float ObtenerZ(){return z;}
        void PonerX (float valx){x = valx;}
        void PonerY (float valy){y = valy;}
        void PonerZ (float valz){z = valz;}
        Punto();
        Punto(float,float, float);//constructor
        void EscribirPunto();
        void AsignarPunto(float, float, float);
};
Punto::Punto(){  //Constructor por defecto; :: indica que pertenece a la clase
    x=0;
    y=0;
    z=0;
}

Punto::Punto(float valx, float valy, float valz){
    x=valx;
    y=valy;
    z=valz;
}

Punto::EscribirPunto(){ //muestra los valores de x, y , z
    cout<<ObtenerX()<<" "<<ObtenerY()<<" "<<ObtenerZ()<<endl;
    
}
Punto::AsignarPunto(float valx, float valy, float valz){
    x=valx;
    y=valy;
    z=valz;
}
int main(){
    Punto p,p1;
    Punto p2 = Punto(5,6,7);
    p.AsignarPunto(2,3,4);
    p.EscribirPunto();
    p1.EscribirPunto();
    p2.EscribirPunto();
    return 0;
}


