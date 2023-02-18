#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bank_account
{
public:
    int number;
    int balance;
    Bank_account() {}
    Bank_account(int num, int bal)
    {
        number = num;
        balance = bal;
    }
    void display_bank_details()
    {
        cout << "Account Number:  " << number << endl;
        cout << "Bank Balance:  " << balance << endl;
    }
};

class Person : protected Bank_account
{
private:
    int UPI;
    friend class mediator;

public:
    Person(){};
    Person(int b_num, int b_bal, int U) : Bank_account(b_num, b_bal)
    {
        UPI = U;
    }
};
class mediator
{
public:
    vector<Person> transacters;
    void add_person(Person P)
    {
        transacters.push_back(P);
    }
    void add_multiple_people(int m)
    {
        for (int i = 0; i < m; i += 1)
        {
            Person P;
            cout << "enter person" << endl;
            cout << "enter UPI" << endl;
            cin >> P.UPI;
            cout << "enter balance" << endl;
            cin >> P.balance;
            cout << "enter bank account number" << endl;
            cin >> P.number;
            add_person(P);
        }
    }
    Person search(int UPI)
    {
        for (int i = 0; i < transacters.size(); i += 1)
        {
            if (transacters[i].UPI == UPI)
            {
                return transacters[i];
            }
        }
        exit(0);
    }
    void transfer_money(int UPI1, int UPI2, int amount)
    {
        Person sender = search(UPI1);
        Person reciever = search(UPI2);
        if (sender.balance < amount)
        {
            cout << "insufficient balance" << endl;
            return;
        }
        else
        {
            reciever.balance += amount;
            sender.balance -= amount;
        }
        sender.display_bank_details();
        reciever.display_bank_details();
    }
};
int main()
{
    mediator m;
    m.add_multiple_people(3);
    m.transfer_money(100, 200, 20);
}