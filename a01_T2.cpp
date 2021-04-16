//      Muhammad Zaeem Tauqir
//        2020376
// Assignment 1, TASK # 2

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct student{
    int reg;
    string name;
};


int main(int argc, char * argv[]){
    ifstream a;
    a.open(argv[1]);
    if( !a ){       // Checking if file opens.
        cerr << "Unable to open file!" << endl;
        exit (-1);
    }

    srand(time(0));
    int N = 0, count = 1, j = 0;
    double p;
    
    a >> N;
    if ( N < 0 ){       // Checking if number of students is not negative.
        cerr << "Negative number!" << endl;
        exit (-1);
    }

    student *arr = new student [N];

    if ( arr == NULL ){     // Checks if memory is correctly allocated.
        cerr << " Memory error! " << endl;
        exit(-1);
    }

    for(int i = 0; i < N; i++){
        a >> arr[i].reg;
        getline( a, arr[i].name);
    }

    if( argc == 3){
        p = *argv[2];
        p -= 48;
    
        if( p > 0 ){
            for(int i = 0; i < p; i++){
                j = rand() % N;
                cout << count << ". " << arr[j].reg << " " << arr[j].name << endl;
                count++; 
            }
        }
    }

    else if(argc == 2){
        j = rand() % N;
        cout << arr[j].reg << " " << arr[j].name << endl;
    }   

    delete [] arr;      // Clears memory.
    a.close();      
    return 0;
}