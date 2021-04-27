// Muhammad Zaeem Tauqir
//  2020376
//  Mid, Task # 2

#include<iostream>
using namespace std;

//declaring class
class Vector;

class Point{
    float x;
    float y;
    float z;

    public:
    //constructors
    Point(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Point(float a){
        x = a;
        y = 0.0;
        z = 0.0;
    }
    Point(float a, float b){
        x = a;
        y = b;
        z = 0.0;
    }
    Point(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }

    float get_x () {
        return x;
    }
    float get_y () {
        return y;
    }
    float get_z () {
        return z;
    }
    void set_x (float a) {
        x = a;
    }
    void set_y (float a) {
        y = a;
    }
    void set_z (float a) {
        z = a;
    }

    void display_Point(){
        cout << "Point is : (" << x << ", " << y << ", " << z << ")" << endl; 
    }

    friend void movebyVector( Point &a, Vector &b);

    //Destructor
    ~Point(){}
};

class Vector{
    float x;
    float y;
    float z;

    public:
    //constroctor
    Vector(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Vector(float a){
        x = a;
        y = 0.0;
        z = 0.0;
    }
    Vector(float a, float b){
        x = a;
        y = b;
        z = 0.0;
    }
    Vector(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }

    float get_x () {
        return x;
    }
    float get_y () {
        return y;
    }
    float get_z () {
        return z;
    }

    //member funtion
    void display_vector(){
        cout << "Vector is : (" << x << ", " << y << ", " << z << ")" << endl; 
    }

    friend void movebyVector(Point &a, Vector &b);

    //destructor
    ~Vector(){}
};

void movebyVector(Point &a, Vector &b){
        Point result;
        result.set_x(a.get_x() + b.get_x()) ;
        result.set_y(a.get_y() + b.get_y());
        result.set_z(a.get_z() + b.get_z());
        cout << "New ";
        result.display_Point();
    }

int main(){
    Point obj1(2.0, 1.0, 0.0);
    Vector obj2(2.0, 0.0, 0.0);

    obj1.display_Point();
    obj2.display_vector();

    movebyVector(obj1, obj2);


    return 0;
}