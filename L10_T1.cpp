//  Muhammad Zaeem Tauqir
//      2020376
//  Lab # 10, Task: 1 

#include<iostream>
using namespace std;

class Person{
    string name;

    public:
    void getName(){
        cout << "Enter name: ";
        cin >> name;
    }

    void displayName(){
        cout<< "Name is: " << name << endl;
    }

    virtual bool isOutstanding() = 0;
    virtual void getData() = 0; 

};

class Student : public Person{
    float gpa = 0.0;

    public:

    void getData(){
        cout << "Enter student's GPA: ";
        cin >> gpa;
    }

    bool isOutstanding(){
        if ( gpa > 3.52 ){
            return true;
        }
        return false;
    }

};

class Professor : public Person{
    int pubs = 0;

    public:
    void getData(){
        cout << "Enter number of professor's publications: ";
        cin >> pubs;
    }

    bool isOutstanding(){
        if ( pubs > 100 ){
            return true;
        }
        return false;
    }

};

int main(){
    char more = 'y';
    Person *objs[100];
    char choice;
    int i = 0;

    while( more == 'y'){
        cout << "Enter student or professor (s/p)? ";
        cin >> choice;

        if( choice == 's' ){
            objs[i] = new Student;
        }
        else if( choice == 'p'){
            objs[i] = new Professor;
        }

        objs[i] -> getName();
        objs[i] -> getData();
        
        cout << "Enter another (y/n)? ";
        cin >> more;

        i++;
    }

    for(int j = 0; j <= i; j++){
        objs[j] -> displayName();

        if( objs[j] -> isOutstanding() == true ){
            cout << "This person is outstanding." << endl;
        }
    }


    return 0;
}