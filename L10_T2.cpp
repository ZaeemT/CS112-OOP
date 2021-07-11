//  Muhammad Zaeem Tauqir
//      2020376
//  Lab # 10, Task: 2

#include<iostream>
using namespace std;

class Student{
    int roll_no = 0;

    public:
    void getNumber(){
        cout << "Enter roll no. : ";
        cin >> roll_no;
    }

    void putNumber(){
        cout << "\t Roll no. is : " << roll_no << endl;
    }

};

class Test : virtual public Student{
    int part1;
    int part2;

    public:
    void getMarks(){
        cout << "Enter marks: " << endl;
        cout << "Part 1: ";
        cin >> part1;
        cout << "Part 2: ";
        cin >> part2;
    }

    void putMarks(){
        cout << "\t Part 1: " << part1 << endl;
        cout << "\t Part 2: " << part2 << endl;
    }

    int return_marks(){
        return( part1 + part2 );
    }

};

class Sport : virtual public Student{
    int  score;

    public:
    void getScore(){
        cout << "Enter sport score: ";
        cin >> score;
    }

    void putScore(){
        cout << "\t Sport score: " << score << endl;
    }

    int return_score(){
        return score;
    }

};

class Result : public Test, public Sport{
    int total;

    public:
    void putMarks(){
        Test :: putMarks();
    }

    void putScore(){
        Sport :: putScore();
    }

    void total_score(){
        total = return_marks() + return_score();
        cout << "\t Total score: " << total << endl;
    }
    
};

int main(){
    Result obj;

    obj.getNumber();
    obj.getMarks();
    obj.getScore();

    cout << endl;
    
    obj.putNumber();
    obj.putMarks();
    obj.putScore();
    obj.total_score();

    return 0;
}