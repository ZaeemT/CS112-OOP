#include<iostream>
#include<fstream>
using namespace std;

class Animal{
    public:
    virtual void move() = 0;
};


class Fish : public Animal{
    int positionx;
    int positiony;
    bool isfreshwater;

    public:

    virtual void move(){
        cout << "Fish Swims." << endl;
        cout << positionx << " " << positiony << " " << isfreshwater << endl;
    }

    void set(int x, int y, bool z){
        positionx = x;
        positiony = y;
        isfreshwater = z;
    }
};

class Bird : public Animal{
    int positionx;
    int positiony;
    bool canfly;

    public:

    virtual void move(){
        cout << "Bird flies." << endl;
        cout << positionx << " " << positiony << " " << canfly << endl;
    }

    void set(int x, int y, bool z){
        positionx = x;
        positiony = y;
        canfly = z;
    }
};

class Mamal : public Animal{
    int positionx;
    int positiony;
    int nlegs;

    public:
    
    virtual void move(){
        cout << "For mamal its complicated." << endl; 
        cout << positionx << " " << positiony << " " << nlegs << endl;
    }

    void set(int x, int y, int z){
        positionx = x;
        positiony = y;
        nlegs = z;
    }
};


//forward declaration
class Microbes;

class Goldfish : public Fish{
    public:

    void move(){
        cout << "Goldfish also swims." << endl;
    }

    void dine_on( Microbes a[] ){

    }
   
    friend Goldfish & operator >> ( ifstream & input, Goldfish & a );
};

class Kiwi : public Bird{
    public:

    void move(){
        cout << "Kiwi is a bird, but it cannot fly." << endl;
    }
    
    friend Kiwi &operator >> (ifstream & input, Kiwi & k);
};


class IDcard{
    int regno;

    public:
    //constructor
    IDcard(){
        regno = 0;
    }
    IDcard( int a ){
        regno = a;
    }
};

class Heart{
    string bloodtype;

    public:
    //constructors
    Heart(){
        bloodtype = "N/A";
    }
    Heart( string a ){
        bloodtype = a;
    }
};


class Gikian : public Mamal{
    IDcard *x;
    Heart y;

    public:
    
    void move(){
        cout << "Gikian in particular can walk." << endl;
    }

    friend Gikian &operator >> (ifstream & input, Gikian & gk);
};


class Microbes{

};

//Operator Overloading
Goldfish &operator >> (ifstream & input, Goldfish & g){
    int elem1 = 0, elem2 = 0;
    bool elem3;

    input >> elem1 >> elem2 >> elem3;
    g.set(elem1, elem2, elem3);

    return g;
}

Kiwi &operator >> (ifstream & input, Kiwi & k){
    int elem1, elem2;
    bool elem3;

    input >> elem1 >> elem2 >> elem3;
    k.set(elem1, elem2, elem3);

    return k;
}

Gikian &operator >> (ifstream & input, Gikian & gk){
    int elem1, elem2, elem3;

    input >> elem1 >> elem2 >> elem3;
    gk.set(elem1, elem2, elem3);

    return gk;
}

//Counting num of elements of each type.
int get_num(ifstream & file, int n){
    int N = 0;
    int nfish = 0, nbird = 0, nmamal = 0;
    int elem1, elem2, elem3;
    while(!file.eof()){
        
        file >> N >> elem1 >> elem2 >> elem3;

        if( N == 1 ){
            nfish++;
        }
        else if(N == 2){
            nbird++;
        }
        else if(N == 3){
            nmamal++;
        }
    }
    
    if( n == 1 ){
        return nfish;
    }
    else if( n == 2){
        return nbird;
    }
    //else it will
    return nmamal;
}


int main(){
    int N = 0, i = 0;
    
    ifstream a;
    a.open("input_file.txt");   //Opening file.
    if( !a ){       // Checking if file opens.
        cerr << "Unable to open file!" << endl;
        exit (-1);
    }

    int num_fish = get_num(a, 1);
    int num_bird = get_num(a, 2);
    int num_mamal = get_num(a, 3);
    int total = num_fish + num_bird + num_mamal;

    Animal *A[total]; 

    while( !a.eof() ){
        //Reading the id.
        a >> N;
        
        if( N == 1 ){
            Goldfish *gf = new Goldfish;
            a >> *(gf);
            A[i] = gf;
        }
        else if( N == 2 ){
            Kiwi *(kw) = new Kiwi;
            a >> *(kw);
            A[i] = kw;
        }
        else if( N == 3 ){
            Gikian *(gk) = new Gikian;
            a >> *(gk);
            A[i] = gk;
        }   
        
        i++;
    }
    
    //Outputing with the concept of polymorphism.
    for(int c = 0; c < total; c++){
        A[c]->move();
    }

    //Closing the file.
    a.close();
    return 0;
}