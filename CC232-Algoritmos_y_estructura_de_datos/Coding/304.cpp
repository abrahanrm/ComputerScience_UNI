#include<iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void quickSortMain(char items[][10], int count);
void quickSort(char items[][10], int left, int right);
char str[4][10];
int main(void)
{
  //int i=0;
  cout<<"nombre1:";
  cin>>str[0]; 
  cout<<"nombre2:";
  cin>>str[1];
  cout<<"nombre3:";
  cin>>str[2]; 
  cout<<"nombre4:";
  cin>>str[3];
  //char str[4][10] = { "this","is","a","test"};

  quickSortMain(str, 4);

  for(int i=0; i<4; i++) {
     printf("%s ", str[i]);
  }
  return 0;
}
void quickSortMain(char items[][10], int count)
{
  quickSort(items, 0, count-1);
}

void quickSort(char items[][10], int left, int right)
{
  int i, j;
  char *x;
  char temp[10];

  i = left;
  j = right;
  x = items[(left+right)/2];

  do {
    while((strcmp(items[i],x) < 0) && (i < right)) {
       i++;
    }
    while((strcmp(items[j],x) > 0) && (j > left)) {
        j--;
    }
    if(i <= j) {
      strcpy(temp, items[i]);
      strcpy(items[i], items[j]);
      strcpy(items[j], temp);
      i++;
      j--;
   }
  } while(i <= j);

  if(left < j) {
     quickSort(items, left, j);
  }
  if(i < right) {
     quickSort(items, i, right);
  }
}

/*
#include <iostream>
    #include <string>

    using namespace std;

    class Student
    {
    public:
        string getPaterno();//string getName();
        string getMaterno();//string getSurname();
        string getNombre();//string getID();
        int getNota();
        void setPaterno(string stdPaterno);
        void setMaterno(string stdMaterno);
        void setNombre(string stdNombre);
        void setNota(string stdNota);
    private:
        string paterno;
        string materno;
        string nombre;
        int nota;
    };

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

    void quicksort(Student students[],int left, int right)
    {
        if (left < right)
        {
            int pivot = quick_sort_help(students, left, right);
            quicksort(students, left, pivot - 1);
            quicksort(students, pivot + 1, right);
        }
    }

    void quick_sort(Student students[],int size){
        quicksort(students,0,size-1);
    }

    int main()
    {
        Student myStudent[100];
        string name;
        string surname;
        string id;
        int choice;
        int temp=0;
        char ans1;
        do
        {
            cout<<"Please enter Student's name: ";
            cin>>name;
            cout<<"Please enter Student's surname: ";
            cin>>surname;
            cout<<"Please enter Student's ID: ";
            cin>>id;
            myStudent[temp].setName(name);
            myStudent[temp].setSurname(surname);
            myStudent[temp].setID(id);
            cout<<"Want to add new Student? (y/n)";
            cin>>ans1;
            temp++;
        }while(ans1=='y'||ans1=='Y');

        quick_sort(myStudent, temp);
        do{
            cout<<"What do you want to search with?"<<endl;
            cout<<"1-)Search with name:"<<endl;
            cout<<"2-)Search with surname:"<<endl;
            cout<<"3-)Search with ID (binary!):"<<endl;
            cout<<"4-)Show List!"<<endl;
            cin>>choice;

            switch (choice)
            {
            case 1:
                {
                    cout<<"Enter the student name:";
                    cin>>name;
                    for(int i=0;i<temp;i++)
                    {
                        if(myStudent[i].getName()==name)
                        {
                            cout<<myStudent[i].getID() + " " + myStudent[i].getName() + " " + myStudent[i].getSurname()<<endl;
                        }
                    }
                    break;
                }
            case 2:
                {
                    cout<<"Enter the student surname:";
                    cin>>surname;
                    for(int i=0;i<temp;i++)
                    {
                        if(myStudent[i].getSurname()==surname)
                        {
                            cout<<myStudent[i].getID() + " " + myStudent[i].getName() + " " + myStudent[i].getSurname()<<endl;
                        }
                    }
                    break;
                }
            case 3:
                {
                    cout<<"Enter the student ID:";
                    cin>>id;
                    int left=0;
                    int right = temp;
                    int mid = (right + left)/2;
                    while(left <= right){
                        if(myStudent[mid].getID()>id)
                        {
                            right = mid - 1;
                            mid = (right+left)/2;
                        }
                        if(myStudent[mid].getID()<id)
                        {
                            left = mid + 1;
                            mid = (right+left)/2;
                        }
                        if(myStudent[mid].getID()==id)
                        {
                            cout<<myStudent[mid].getID()+ " " + myStudent[mid].getName()+ " " + myStudent[mid].getSurname()<<endl;
                            break;
                        }
                    }
                    break;
                }
            case 4:
                {
                    cout<<"id/name/surname"<<endl;
                    for(int i=0;i<temp;i++)
                    {
                        cout<<myStudent[i].getID()+ " " + myStudent[i].getName() + " " + myStudent[i].getSurname()<<endl;
                    }
                    break;
                }    
            }
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>ans1;
        }while(ans1=='y' || ans1=='Y');

        return 0;
    }

    string Student::getName()
    {
        return name;
    }

    string Student::getSurname()
    {
        return surname;
    }

    string Student::getID()
    {
        return ID;
    }

    void Student::setName(string stdName)
    {
        name=stdName;
    }

    void Student::setSurname(string stdSurname)
    {
        surname=stdSurname;
    }

    void Student::setID(string stdID)
    {
        ID=stdID;
    }
*/