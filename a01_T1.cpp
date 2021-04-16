//      Muhammad Zaeem Tauqir
//        2020376
// Assignment 1, TASK # 1

#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char * argv[]){
    ifstream a;
    a.open(argv[1]);    // opening file
    if( !a ){       // checking if file opens
        cerr << "Unable to open file." << endl;
        exit(-1);
    }
    string line;
    int count=1;

    if ( argc == 2){
        while(  getline(a, line) ){ 
            cout << line << endl;
        }
    }
    else if ( argc == 3 ){
        while( getline(a, line)){ 
            cout << count << ". " << line << endl;
            count++;
        }
    }
    a.close();
    return 0;
}