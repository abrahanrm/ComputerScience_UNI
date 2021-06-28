#include <iostream>
#include <string>

    using namespace std;

    class Student
    {
    public:
        string getPaterno();
        string getMaterno();
        string getNombre();
        string getNota();
        void setPaterno(string stdPaterno);
        void setMaterno(string stdMaterno);
        void setNombre(string stdNombre);
        void setNota(string stdNota);
    private:
        string paterno;
        string materno;
        string nombre;
        string nota;
    };
    //funciones quicksort paterno
    int quick_sort_paterno(Student students[],int left, int right)
    {
        Student val = students[right];
        Student temp;

        int j = right;
        int i = left - 1;

        while (true)
        {
            while (students[++i].getPaterno() < val.getPaterno());

            while (students[--j].getPaterno() > val.getPaterno()) {
                if(j == left)
                    break;
            }

            if(i >= j)
                break;

            temp=students[i];
            students[i]=students[j];
            students[j]=temp;
        }

        temp=students[i];
        students[i]=students[right];
        students[right]=temp;

        return i;
    }

    void quicksort_paterno(Student students[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_paterno(students, left, right);
            quicksort_paterno(students, left, pivot - 1);
            quicksort_paterno(students, pivot + 1, right);
        }
    }

    void quick_sort_paterno(Student students[],int size){
        quicksort_paterno(students,0,size-1);
    }

    //funciones quicksort materno
    int quick_sort_materno(Student students[],int left, int right)
    {
        Student val = students[right];
        Student temp;
        int j = right;
        int i = left - 1;

        while (true)
        {
            while (students[++i].getMaterno() < val.getMaterno());
            while (students[--j].getMaterno() > val.getMaterno()) {
                if(j == left)
                    break;
            }

            if(i >= j)
                break;

            temp=students[i];
            students[i]=students[j];
            students[j]=temp;
        }

        temp=students[i];
        students[i]=students[right];
        students[right]=temp;
        return i;
    }

    void quicksort_materno(Student students[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_materno(students, left, right);
            quicksort_materno(students, left, pivot - 1);
            quicksort_materno(students, pivot + 1, right);
        }
    }

    void quick_sort_materno(Student students[],int size){
        quicksort_materno(students,0,size-1);
    }

    //funciones quicksort nombre
    int quick_sort_nombre(Student students[],int left, int right)
    {
        Student val = students[right];
        Student temp;
        int j = right;
        int i = left - 1;

        while (true)
        {
            while (students[++i].getNombre() < val.getNombre());
            while (students[--j].getNombre() > val.getNombre()) {
                if(j == left)
                    break;
            }
            if(i >= j)
                break;

            temp=students[i];
            students[i]=students[j];
            students[j]=temp;
        }
        temp=students[i];
        students[i]=students[right];
        students[right]=temp;
        return i;
    }

    void quicksort_nombre(Student students[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_nombre(students, left, right);
            quicksort_nombre(students, left, pivot - 1);
            quicksort_nombre(students, pivot + 1, right);
        }
    }

    void quick_sort_nombre(Student students[],int size){
        quicksort_nombre(students,0,size-1);
    }

    //funciones quicksort nota
    int quick_sort_nota(Student students[],int left, int right)
    {
        Student val = students[right];
        Student temp;
        int j = right;
        int i = left - 1;

        while (true)
        {
            while (students[++i].getNota() < val.getNota());
            while (students[--j].getNota() > val.getNota()) {
                if(j == left)
                    break;
            }
            if(i >= j)
                break;

            temp=students[i];
            students[i]=students[j];
            students[j]=temp;
        }

        temp=students[i];
        students[i]=students[right];
        students[right]=temp;

        return i;
    }

    void quicksort_nota(Student students[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_nota(students, left, right);
            quicksort_nota(students, left, pivot - 1);
            quicksort_nota(students, pivot + 1, right);
        }
    }

    void quick_sort_nota(Student students[],int size){
        quicksort_nota(students,0,size-1);
    }

    int main()
    {
        Student myStudent[50];
        string paterno;
        string materno;
        string nombre;
        string nota;
        int choice, pos;
        int temp=0;
        char ans1;
        do
        {
            cout<<"Ingresando estudiante"<<endl;
            cout<<"Paterno: ";
            cin>>paterno;
            cout<<"Materno: ";
            cin>>materno;
            cout<<"Nombre: ";
            cin>>nombre;
            cout<<"Nota: ";
            cin>>nota;
            myStudent[temp].setPaterno(paterno);
            myStudent[temp].setMaterno(materno);
            myStudent[temp].setNombre(nombre);
            myStudent[temp].setNota(nota);
            cout<<"Quieres agregar un nuevo estudiante? (s/n)";
            cin>>ans1;
            temp++;
        }while(ans1=='s'||ans1=='S');

        //quick_sort(myStudent, temp);
        do{
            cout<<"Escoja una de las siguientes opciones"<<endl;
            cout<<"1-)Listado sin ordenamiento"<<endl;
            cout<<"2-)Listado ordenado por apell.Paterno"<<endl;
            cout<<"3-)Listado ordenado por apell.Materno"<<endl;
            cout<<"4-)Listado ordenado por Nombre"<<endl;
            cout<<"5-)Listado ordenado por Nota"<<endl;
            cout<<"6-)Eliminar registro de estudiante"<<endl;
            cin>>choice;

            switch (choice)
            {
            
            case 1:
            {
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break; 
            }

            case 2:
            {
                    quick_sort_paterno(myStudent, temp);
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break; 
            }
            case 3:
            {
                    quick_sort_materno(myStudent, temp);
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break; 
            }
            case 4:
            {
                    quick_sort_nombre(myStudent, temp);
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break; 
            }
            case 5:
            {
                    quick_sort_nota(myStudent, temp);
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break; 
            }

            case 6:
                {
                    cout<<"Paterno:";
                    cin>>paterno;
                    cout<<"Materno:";
                    cin>>materno;
                    cout<<"Nombre:";
                    cin>>nombre;
                    cout<<"Nota:";
                    cin>>nota;
                    for(int i=0;i<temp;i++)
                    {
                        if((myStudent[i].getPaterno()==paterno)&&(myStudent[i].getMaterno()==materno)&&(myStudent[i].getNombre()==nombre)&&(myStudent[i].getNota()==nota))
                        {
                            pos=i;
                        }
                    }
                    for(int j=pos;j<temp;j++){
                                myStudent[j].setPaterno(myStudent[j+1].getPaterno());
                                myStudent[j].setMaterno(myStudent[j+1].getMaterno());
                                myStudent[j].setNombre(myStudent[j+1].getNombre());
                                myStudent[j].setNota(myStudent[j+1].getNota());
                    }
                    temp=temp-1;
                    cout<<"Eliminado"<<endl;
                    cout<<"paterno/materno/nombre/nota"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getPaterno()+ " " + myStudent[i].getMaterno() + " " + myStudent[i].getNombre()+ " " + myStudent[i].getNota()<<endl;
                    }
                    cout<<"Nro studiantes: "<<temp<<endl;
                    break;
                }
            }
            cout<<"Quiere continuar?(s/n)"<<endl;
            cin>>ans1;
        }while(ans1=='s' || ans1=='S');

        return 0;
    }

    string Student::getPaterno()
    {
        return paterno;
    }

    string Student::getMaterno()
    {
        return materno;
    }

    string Student::getNombre()
    {
        return nombre;
    }

    string Student::getNota()
    {
        return nota;
    }

    void Student::setPaterno(string stdPaterno)
    {
        paterno=stdPaterno;
    }

    void Student::setMaterno(string stdMaterno)
    {
        materno=stdMaterno;
    }

    void Student::setNombre(string stdNombre)
    {
        nombre=stdNombre;
    }

    void Student::setNota(string stdNota)
    {
        nota=stdNota;
    }