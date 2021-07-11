#include<iostream>
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

    void move(){
        cout << "Fish Swims." << endl;
    }
};

class Bird : public Animal{
    int positionx;
    int positiony;
    bool canfly;

    public:

    void move(){
        cout << "Bird flies." << endl;
    }
};

class Mamal : public Animal{
    int positionx;
    int positiony;
    int nlegs;

    public:
    
    void move(){
       cout << "For mamal its complicated." << endl; 
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
};

class Kiwi : public Bird{
    public:

    void move(){
        cout << "Kiwi is a bird, but it cannot fly." << endl;
    }
};

class IDcard{
    int regno;

};

class Heart{
    string bloodtype;

};

class Gikian : public Mamal{
    IDcard *x;
    Heart y;

    public:
    
    void move(){
        cout << "Gikian in particular can walk." << endl;
    }
};


class Microbes{

};

int main(){
    Animal *A;    

    Fish f;
    A = &f;
    A->move();
    
    Bird b;
    A = &b;
    A->move();

    Mamal m;
    A = &m;
    A->move();

    cout << endl;

    Goldfish gf;
    A = &gf;
    A->move();

    Kiwi kw;
    A = &kw;
    A->move();

    Gikian boy;
    A = &boy;
    A->move();
    
    return 0;
}