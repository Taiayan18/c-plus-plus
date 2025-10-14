#include <iostream>
#include <string.h>
using namespace std;

class Servicing
{
public:
    int Number, Balance, Rate, limit, month;
    string Name;

    void seving()
    {

        cout << endl
             << "Enter Account Number: ";
        cin >> Number;

        cout << "Enter Your name: ";
        cin >> Name;

        cout << "Enter Your Accoutn Balance: ";
        cin >> Balance;

        cout << "Enter Account Rate: ";
        cin >> Rate;

        cout << "seving Account is sccesfully" << endl;
    }

    void checking()
    {

        cout << endl
             << "Enter Account Number: ";
        cin >> Number;

        cout << "Enter Your name: ";
        cin >> Name;

        cout << "Enter Your Accoutn Balance: ";
        cin >> Balance;

        cout << "Enter Overdraf Limit: ";
        cin >> limit;

        cout << "Checking Account is sccesfully" << endl;
    }

    void Fixed()
    {

        cout << endl
             << "Enter Account Number: ";
        cin >> Number;

        cout << "Enter Your name: ";
        cin >> Name;

        cout << "Enter Your Accoutn Balance: ";
        cin >> Balance;

        cout << "Enter Term (in month): ";
        cin >> month;

        cout << "Enter Interest rate (%): ";
        cin >> Rate;

        cout << "Fixed Deposit Account is sccesfully" << endl;
    }

    void deposit()
    {
        int amount;

        cout << endl
             << "Enter your Amount Deposit: ";
        cin >> amount;

        Balance += amount;

        cout << " Amount Deposit Sccesfully" << endl;
    }

    void Withdraw()
    {
        int amount;

        cout << endl
             << "Enter your Amount withdraw: ";
        cin >> amount;

        Balance -= amount;

        cout << " Amount Deposit Sccesfully" << endl;
    }

    void info()
    {
        cout << endl
             << "[Seving Account]" << endl;
        cout << "Account Number     :" << Number << endl;
        cout << "Account Holder     :" << Name << endl;
        cout << "Account Balance    :" << Balance << endl;
        cout << "Intrest rate       :" << Rate << endl;
    }

    

    void Exit()
    {
        cout << "Your Exit ! Thank You." << endl;
    }
};

class seving : public Servicing
{
public:
    seving(int Number, string Name, int Balance, int Rate);
};

class checking : public Servicing
{
public:
    checking(int Number, string Name, int Balance, int limit);
};

int main()
{

    int choice;

    Servicing Account;
    do
    {
        cout << endl
             << "==== Bank Account Managment System ====" << endl;
        cout << "1. Create Savings Account" << endl;
        cout << "2. Create Checking Account" << endl;
        cout << "3. Create Fixed Deposit Account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << "6. Display Account Info" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Your Choise: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Account.seving();
            break;
        case 2:
            Account.checking();
            break;

        case 3:
            Account.Fixed();
            break;

        case 4:
            Account.deposit();
            break;
        case 5:
            Account.Withdraw();
            break;

        case 6:
            Account.info();
            break;


        case 7:
            Account.Exit();
            break;

        default:cout<<"Invalid Number"<<endl;
            break;
        }

    } while (choice != 8);

    return 0;
}