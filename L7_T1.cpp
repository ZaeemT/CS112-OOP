//  LAB: 7, Task # 1

#include<iostream>
using namespace std;

class Position{
    int x_coordinate;
    int y_coordinate;

    public:
    //default contructor
    Position(){
        x_coordinate = 0;
        y_coordinate = 0;
    }
    //constructor
    Position(int x, int y){
        x_coordinate = x;
        y_coordinate = y;
    }

    void dispaly(){
        cout << x_coordinate << ", " << y_coordinate << endl;
        //output x, y
    }

    Position operator+ (Position obj){
        Position result;
        result.x_coordinate = x_coordinate + obj.x_coordinate;
        result.y_coordinate = y_coordinate + obj.y_coordinate;

        return result;
    }
};


int main(){
    int x = 0, y = 0;

    cout << "Enter coordinates for initial point" << endl;
    cout << "Enter x-coordinate: ";
    cin >> x;
    cout << "Enter y-coordinate: ";
    cin >> y;

    Position obj1(x, y);
    cout << "Initial Position: ";
    obj1.dispaly();
    cout << endl;

    cout << "Enter number by which you want to move" << endl;
    cout << "Enter number for x-coordinate: ";
    cin >> x;
    cout << "Enter number for y-coordinates: ";
    cin >> y;
    cout << endl;

    Position obj2(x, y), obj3;

    obj3 = obj1 + obj2; 
    cout << "New position : ";
    obj3.dispaly();

    return 0;
}