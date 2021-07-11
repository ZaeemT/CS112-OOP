/*  Muhammad Zaeem Tauqir
        2020376
    Lab # 9
*/

#include<iostream>
using namespace std;

class Vehicle{
    protected:

    int wheels;
    float weight;

    public:
    //constructor
    Vehicle(){
        wheels = 0;
        weight = 0.0;
    }
    Vehicle(int a, float b){
        wheels = a;
        weight = b;
    }

    int get_wheels(){
        return wheels;
    }

    float get_weight(){
        return weight;
    }

    float load_per_tyre(){
        return ( weight / wheels );
    }

};

class Car : public Vehicle {
    int passenger_load;

    public:
    //overloaded constructor

    Car( int a, float b, int c) : Vehicle( a, b) {
        passenger_load = c;
    }

    int get_passenger_load(){
        return ( passenger_load );
    }
};

class Truck : public Vehicle{
    int passenger_load;
    float max_load;

    public:
    //overloaded constructor

    Truck( int a, float b, int c ) : Vehicle (a, b){
        passenger_load = c;
        max_load = get_weight();
    }

    int get_passenger_load(){
        return passenger_load;
    }

    float efficiency(){
        float eff = 0.0;
        eff = max_load / ( max_load + load_per_tyre() );
        return (eff*100);
    }

};

int main() {
    Car obj1(4, 3500, 5);
    cout << "My car carries " << obj1.get_passenger_load() << " and its weight is " << obj1.get_weight() <<endl;
    cout << "My car wheel loading is " << obj1.load_per_tyre() << " per tyre." << endl;

    cout << endl;

    Truck obj2( 6, 12500, 8);
    cout << "The trailer's weight is " << obj2.get_weight() << "." << endl;
    cout << "The trailer's efficiency is " << obj2.efficiency() << "." << endl;


    return 0;
}