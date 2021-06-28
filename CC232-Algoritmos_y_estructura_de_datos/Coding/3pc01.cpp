#include<iostream>
using namespace std;
class NodoPila
{
    public:
        char elemento;
        NodoPila* siguiente;
        NodoPila(char x)//constructor
        {
            elemento=x;
            siguiente=NULL;
        }
};
//Clase PilaDina
class PilaDina
{
public:
    NodoPila* cima;
    PilaDina()//constructor
    {
        cima=NULL;
    }
    void insertar(char);
    char quitar();
    char cimaPila();
    bool pilaVacia();
    //void limpiarPila();
};
//********************funcion insertar***************
void PilaDina::insertar(char elemento)
{
    NodoPila* nuevo;
    nuevo=new NodoPila(elemento);
    nuevo->siguiente=cima;
    cima=nuevo;
}

//********************funcion mostrarPila***********************
bool PilaDina::pilaVacia()
{
    return cima==NULL;
};
char PilaDina::cimaPila()
{
    if(pilaVacia())
        cout<<"Pila vacia\n";
    else 
        return cima->elemento;
}
void mostrarPila(PilaDina &pila) //muestra el elemento de la cima a la par que lo elimina
{
    char x;
    cout<<"\nElementos de la pila"<<endl;
    while (!pila.pilaVacia())
    {
        cout<<"Direccion cima: "<<pila.cima<<". Elemento en la cima: "<<pila.cimaPila()<<endl;
        x=pila.quitar();
        cout<<x<<endl;
    }
    cout<<"Al terminar queda:\n";
    cout<<"Direccion cima:"<<pila.cima<<". Elemento en la cima: "<<pila.cimaPila()<<endl;
};

//**************************funcion quitar********************************
char PilaDina::quitar()
{
    NodoPila* n;
    if(pilaVacia())
    {
        cout<<"Pila vacia, no se puede extraer\n";
    }
    else
    {
        n=cima;
        char x=cima->elemento;
        cima=cima->siguiente;
        delete n;
        //return x;
    }   
}

//################################################################################################################

int precedencia(char s)
{
    if(s=='*' || s=='/')
        return 2;
    if(s=='+' || s=='-')
        return 1;
    else return-1;
}

bool esOperador(char c)  
{  
    if(c == '+' || c == '-' || c == '*' || c == '/')  
        return true;     
    return false;  
}  
   
bool esDigito(char c)  
{    
    if(c >= '0' && c <= '9') 
        return true;  
    return false;  
}  

float operacion(char a, char b, char op){
      //Perform operation
      if(op == '+')
         return b+a;
      else if(op == '-')
         return b-a;
      else if(op == '*')
         return b*a;
      else if(op == '/')
         return b/a;
}

bool  esDesigual(char op1, char op2)  
{  
    int p1 = precedencia(op1);  
    int p2 = precedencia(op2);  
    if (p1 == p2)  
        return true;
    if (p1 > p2)  
        return true;
    return false;
}  
    
string convertidor(string infijo)  
{  
    PilaDina S; 
    string resultado ="";    
    char ch;  
    S.insertar('(');
    resultado += ')';  
    
    for(int i = 0; i<infijo.length(); i++)  
    {  
        if(infijo[i] == ' ' || infijo[i] == ',') 
            continue;
        else if(esOperador(infijo[i])) 
		{
			while(!S.pilaVacia() && S.cimaPila() != '(' && esDesigual(S.cimaPila(),infijo[i]))
			{
				resultado+= S.cimaPila();
				S.quitar();
			}
			S.insertar(infijo[i]);
		}

		else if(esDigito(infijo[i]))
		{
			resultado +=infijo[i];
		}

		else if (infijo[i] == '(') 
		{
			S.insertar(infijo[i]);
		}

		else if(infijo[i] == ')') 
		{
			while(!S.pilaVacia() && S.cimaPila() !=  '(') {
				resultado += S.cimaPila();
				S.quitar();
			}
			S.quitar();
		}
	}

	while(!S.pilaVacia()) {
		resultado += S.cimaPila();
		S.quitar();
	}

	return resultado;
}

float evaluar(string postfijo)
{
    PilaDina p; 
    char primero;  
    for(int i = 0; i<postfijo.length(); i++) 
    {
        if(esDigito(postfijo[i]))
        {
            p.insertar(postfijo[i]); 
            primero= postfijo[i];
            cout<<primero;
        }
        else if(esOperador(postfijo[i]))
        {
            char a = p.cimaPila();
            char b = postfijo[i-2];
            char c = operacion(a, b, postfijo[i]);
            p.quitar();
            p.cima->elemento = c;
        }
        else continue;
            
    }
    return primero + p.cimaPila();
}


int main()
{
   string infijo, postfijo;
   int valor;
    cout<<"Ingrese una expresion infija: ";
    getline(cin,infijo);
    postfijo=convertidor(infijo);
    cout<<"\nExpresion postfijo: "<<postfijo;
    valor=evaluar(postfijo);
    cout<<"\nevaluacion: "<<valor;
    return 0;
}