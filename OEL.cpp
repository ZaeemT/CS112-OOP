//  Muhammad Zaeem Tauqir
//      2020376
//  Open ended lab

#include<iostream>
using namespace std;

class BankAccount{
    protected:
    
        string name;
        string address;
        bool isFiler;
        float balance;
    
    public:

        void newAccount(){
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter address : ";
            cin >> address;
            char choice;
            cout << "Is filer (T/F) : ";
            cin >> choice;
            if(choice == 'T'){
                isFiler = true;
            }
            else{
                isFiler = false;
            }
            cout << "Enter balance : ";
            cin >> balance;
            
        }

        virtual void deposit( float a ) = 0;
        virtual void withdraw( float a ) = 0;
        virtual void transfer( float a ) = 0;
        virtual void annualUpdate() = 0;

        void withholdingTax( float a ){
            float taxFees = 0.0;
            if( isFiler == true){
                taxFees = a * 0.005;
                balance = balance - taxFees;
            }
            else if(isFiler == false){
                taxFees = a * 0.01;
                balance = balance - taxFees;
            }
            
            cout << "Tax fees : " << taxFees << endl;
        }
};

class CurrentAccount : public BankAccount{
    public: 

    void deposit(float a){
        cout << "Initial balance : " << balance << endl;
        balance = balance + a;
        withholdingTax(a);
        cout << "Your current balance is : " << balance << endl;
    }

    void withdraw(float a){
        cout << "Initial balance : " << balance << endl;
        balance = balance - a;
        withholdingTax(a);
        cout << "Your current balance is : " << balance << endl;
    }

    void transfer(float a){
        cout << "Initial balance : " << balance << endl;
        balance = balance - a;
        withholdingTax(a);
        cout << "Your current balance is : " << balance << endl;
    }

    void annualUpdate(){
        cout << "Profit and zakat not applicable on current account." << endl;
    }

};

class SavingAccount : public BankAccount{
    public:

        void transactionFees(){
            cout << "Transaction fees : 200 " << endl;
            balance = balance - 200;
        }

        void deposit(float a){
            cout << "Initial balance : " << balance << endl;
            balance = balance + a;
            withholdingTax(a);
            transactionFees();
            cout << "Your current balance is : " << balance << endl;
        }

        void withdraw(float a){
            cout << "Initial balance : " << balance << endl;    
            balance = balance - a;
            withholdingTax(a);
            transactionFees();
            cout << "Your current balance is : " << balance << endl;
        }

        void transfer(float a){
            cout << "Initial balance : " << balance << endl;
            balance = balance - a;
            withholdingTax(a);
            transactionFees();
            cout << "Your current balance is : " << balance << endl;
        }

        void annualUpdate(){
            cout << "Initial balance : " << balance << endl;
            float profit = balance * 0.1;
            cout << "Profit : " << profit << endl;
            balance = balance + profit;

            float zakat = balance * 0.025;
            cout << "Zakat : " << zakat << endl;
            balance = balance - zakat;
            cout << "Your current balance is : " << balance << endl;
        }

};

void displayMenu(){
    cout << "\t BANK MAIN MENU " << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Create account." << endl;
    cout << "2. Deposit." << endl;
    cout << "3. Withdraw." << endl;
    cout << "4. Transfer." << endl;
    cout << "5. Apply annual update." << endl;
    cout << "6. EXIT." << endl;
    cout << "--------------------------------" << endl;
    cout << " Choose an option : ";
}



int main(){
    int N = 5;
    BankAccount *objs[N];
    char more = 'y';
    int option = 0, i = 0;
    float amount = 0.0;
    char type;

    do{
        more = 'y';

        while( more == 'y'){
            displayMenu();
            cin >> option;

            switch(option){
                case 1:
                    //Creating new account
                    cout << "Select account type (current/C or saving/S): ";
                    cin >> type;
                    
                    if(type == 'C'){
                        CurrentAccount *cAcc = new CurrentAccount;
                        objs[i] = cAcc;
                        objs[i]->newAccount();
                    }
                    else if(type == 'S'){
                        SavingAccount *sAcc = new SavingAccount;
                        objs[i] = sAcc;
                        objs[i]->newAccount();
                    }
                    else{
                        cout << "Invalid entry!" << endl;
                    }
                    break;

                case 2:
                    //Deposit
                    cout << "Enter the amount you want to deposit : ";
                    cin >> amount;
                    objs[i]->deposit(amount);
                    cout << endl;
                    break;
                
                case 3:
                    //withdraw
                    cout << "Enter the amount you want to withdraw : ";
                    cin >> amount;
                    objs[i]->withdraw(amount);
                    cout << endl;
                    break;

                case 4:
                    //transfer
                    cout << "Enter the amount you want to transfer : ";
                    cin >> amount;
                    objs[i]->transfer(amount);
                    cout << endl;
                    break;

                case 5:
                    //Annual update
                    cout << "Profit and Zakat" << endl;
                    objs[i]->annualUpdate();
                    cout << endl;
                    break;

                default:
                    //quit
                    exit(-1);
                    break;
            }

            cout << "Want to perform any more operations on this account? (y/n) ";
            cin >> more;
            
        }

        i++;

    } while( N == i );

    return 0;
}