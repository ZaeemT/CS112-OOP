// Muhammad Zaeem Tauqir
//      2020376
//  Lab # 6, Task # 2

#include<iostream>
using namespace std;

class Temperature{
    float temp;

    public:
    // Default constructor
    Temperature(){
        temp = 0.0;
    }

    Temperature(float x){
        temp = x;
    }

    friend void convert(Temperature a);
};

void convert(Temperature a){
    a.temp = (1.8)*(a.temp) + 32;
    cout << "Temperature in Fahrenheit : " << a.temp << endl;
}

int main(){
    float value = 0.0;

    cout << "Enter Temperature in Celsius : ";
    cin >> value;

    Temperature obj(value);
    convert(obj);

    return 0;
}