// Muhammad Zaeem Tauqir
//  2020376
//  Mid, Task # 1

#include<iostream>
using namespace std;

class Rational {
    int p;
    int q;

    public:
    //constructor
    Rational(){
        p = 0;
        q = 1;
    }

    void get(){
        bool if_valid = false;
        // check if entered denominator is valid or not.

        cout << "Enter P (numerator): ";
        cin >> p;

        do{
            cout << "Enter Q (denominator): ";
            cin >> q;

            if (q != 0) {
                if_valid = true;
            }
            else {
                cout << "Invalid denominator! Denominator must not be zero" << endl;
            }
        } while (if_valid == true);

        this -> Reduced_Form();
    }

    void Reduced_Form(){
        for (int i = q; i >= 2; i--) {
            if (p % i == 0 && q % i == 0) {
                p = p/i;
                q = q/i;
            }
        }
    }

    void display(){
        cout << p << "/" << q;
    }

    friend Rational add_rational (Rational n1, Rational n2);
    friend Rational sub_rational (Rational n1, Rational n2);
    friend Rational mult_rational (Rational n1, Rational n2);
    friend Rational div_rational (Rational n1, Rational n2);

    ~Rational(){}
};

Rational add_rational(Rational n1, Rational n2){
    Rational result;
    result.p = (n1.p * n2.q) + (n2.p * n1.q);
    result.q = n1.q * n2.q;
    result.Reduced_Form();

    return result;
}

Rational sub_rational (Rational n1, Rational n2) {
    Rational result;
    result.p = (n1.p * n2.q) - (n2.p * n1.q);
    result.q = n1.q * n2.q;
    result.Reduced_Form();

    return result;
}

Rational mult_rational(Rational n1, Rational n2){
    Rational result;
    result.p = n1.p * n2.p;
    result.q = n1.q * n2.q;
    result.Reduced_Form();

    return result;
}

Rational div_rational(Rational n1, Rational n2){
    Rational result;
    result.p = n1.p * n2.q;
    result.q = n1.q * n2.p;
    result.Reduced_Form();

    return result;
}

int main(){
    Rational R1;
    R1.get();
    cout << "R1 = ";
    R1.display();

    Rational R2;
    R2.get();
    cout << "R2 = ";
    R2.display();

    cout << "Addition on R1 and R2 is" << endl;
    Rational add_R;
    add_R = add_rational(R1, R2);
    cout << R1.display() << " + " << R2.display() << " = " << add_R.display() << endl;

    cout << "Subtraction on R1 and R2 is " << endl;
    Rational sub_R;
    sub_R = sub_rational(R1, R2);
    cout << R1.display() << " - " << R2.display() << " = " << sub_R.display() << endl;

    cout << "Multiplication on R1 and R2 is " << endl;
    Rational mult_R;
    mult_R = mult_rational(R1, R2);
    cout << R1.display() << " * " << R2.display() << " = " << mult_R.display() << endl;

    cout << "Division on R1 and R2 is " << endl;
    Rational div_R;
    div_R = div_rational(R1, R2);
    cout << R1.display() << " / " << R2.display() << " = " << div_R.display() << endl;

    return 0;
}