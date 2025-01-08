#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ToDoList
{
    int id;
    string task;
};

int ID;

void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();
void updateTask();
int main()
{
    system("cls");
    while(true)
    {
        banner();
        cout<<"\n1: Add Task.";
        cout<<"\n2: Show Task.";
        cout<<"\n3: Search Task.";
        cout<<"\n4: Delete Task.";
        cout<<"\n5: Update Task.";

        int choice;
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addTask();
            break;
        case 2:
            showTask();
            break;
        case 3:
            searchTask();
            break;
        case 4:
            deleteTask();
            break;
        case 5:
            updateTask();
            break;

        default:
            break;
        }


    }
    return 0;
    
} 
void banner()
{
    cout<<"___________________________________________________";
    cout<<"\t                   -My Todo-";
    cout<<"___________________________________________________";
}

void addTask()
{
    system("cls");
    banner();
    ToDoList todo;
    cout<<"\nEnter new task: ";
    cin.get();
    getline(cin,todo.task);
    char save;
    cout<<"\nSave? (y/n): ";
    cin>>save;
    if(save=='y')
    {
        ID++;
        ofstream fout;
        fout.open("todo.txt",ios::app);//Make a new file todo.txt on the same folder for opening the message on it.(9:54)
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();


        char more;
        cout<<"Add more task? (y/n): ";
        cin>>more;

        if(more == "y")
        {
            addTask();
        }
        else
        {
            system("cls");
            cout<<"\nAdded successfully! ";
            return ;
        }

    }
    system("cls");
}

void showTask()
{
    system("cls");
    banner();
    ToDoList todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"\nTaks: ";

    while (!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.task != "")
        {
            cout<<"\t"<<todo.id<<": "<<todo.task<<"\n";
        }
        else
        {
            cout<<"\tEmpty! ";
        }
    }
    fin.close();
    char exit;
    cout<<"\nExit? (y/n): ";
    cin>>exit;
    if(exit!='y')
    {
        showTask();
    }
    system("cls");

}

int searchTask()
{
    system("cls");
    banner();
    int id;
    cout<<"\nEnter task id: ";
    cin>>id;
    ToDoList todo;
    ifstream fin("todo.txt");
    while (!fin.eof())
    {
        fin>>todo.id;
        fin.ignore();
        getline(fin,todo.task);
        if(todo.id==id)
        {
            system("cls");
            cout<<"\t"<<todo.id<<": "<<todo.task;
            return id;
        }
    }
    system("cls");
    cout<<"\nNot Found! ";
    return 0;    
}

void deleteTask()
{
    system("cls");
    int id=searchTask();
    if(id!=0)
    {
        char del;
        cout<<"\nDelete? (y/n): ";
        cin>>del;
        if(del=='y')
        {
            ToDoList todo;
            ofstream tempFile;
            tempFile.open("temp.txt"); //Create the temp.txt file on these folder like todo.txt 
            ifstream fin;
            fin.open("todo.txt");
            int index=1;
            while (!fin.eof())
            {
                fin>>todo.id;
                fin.ignore();
                getline(fin,todo.task);
                if (todo.id!=id)
                {
                    tempFile<<"\n"<<index;
                    tempFile<<"\n"<<todo.task;
                    index++;
                    ID--;
                }
                
            }
            fin.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt","todo.txt");
            system("cls");
            cout<<"\n\tDeleted Successfully! ";

        }
        else
        {
            system("cls");
            cout<<"\nNot Deleted! ";
        }
    }

}