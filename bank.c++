#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string adress;
    int age;
    int  account_number;

protected:
    int balence;

private:
    string password;

public:
BankAccount(string account_holder,string adress,int age,string password){

    this->account_holder=account_holder;
    this->adress=adress;
    this->age=age;
    this->password=password;
    this->balence=0;
    this->account_number=rand()%1000000000;

    cout<<"Your account no is  "<<this->account_number<<endl;

}
int show_balence(string password)
{
    if(this->password==password){
        return this->balence;

    }
    else{
        return -1;
    }
}
void add_money(string password ,int amount){
    if(this->password==password){
        this->balence+=amount;
        cout<<"Add Money Succesfully"<<endl;
    }
    else{
        cout<<"passWord didn't match"<<endl;
    }
}

void deposit_money(string password,int amount){
    if (amount<0)
    {
        cout<<"Invalid Amount"<<endl;
        return;
    }
    if(this->balence<amount){
        cout<<"Insufficiant Balance "<<endl;
        return;
    }
     if(this->password==password){
        this->balence-=amount;
        cout<<"Deposit Money Succesfully"<<endl;
    }
    else{
        cout<<"passWord didn't match"<<endl;
    }
}
friend class MyCash;

};

class MyCash{
protected:
    int balance;

public:
void add_money_from_bank(BankAccount *myAccount,string password,int amount){
    
    if(amount<0){
        cout<<"Invalid Amount"<<endl;
    }
    if (myAccount->balence < amount)
    {
        cout<<"Insufficiant balance "<<endl;
    }
    

    if(myAccount->password==password){
        this->balance+=amount;
        myAccount->balence -=amount;
        cout<<"Add Money from Bank is succesfull"<<endl;

    }
    else{
        cout<<"Password didn't match"<<endl;
    }
}
int show_balance(){
    return balance;
}

};

BankAccount* create_account(){
    string account_holder,password,address;
    int age;
    cout<<"Create Account"<<endl;
    cin>>account_holder>>address>>age>>password;
    BankAccount *myAccount = new BankAccount(account_holder,address,age,password);
    return myAccount;
}

void add_money(BankAccount *myAccount){
    string password;
    int amount;
    cout<<"ADD Money"<<endl;
    cin>>password>>amount;
    myAccount->add_money(password,amount);
      cout<<"Your bank account balence "<<myAccount->show_balence("abc")<<endl;
}

void deposit_money(BankAccount *myAccount){
    string password;
    int amount;
    cout<<"Deposit Money"<<endl;
    cin>>password>>amount;
    myAccount->deposit_money(password,amount);
      cout<<"Your bank account balence "<<myAccount->show_balence("abc")<<endl;
}

void add_money_from_bank(MyCash *myCash,BankAccount *myAccount){
    string password;
    int amount;
    cout<<"Add Money From Bank "<<endl;
    cin>>password>>amount;
    myCash->add_money_from_bank(myAccount,password,amount);
    cout<<"Your bank balance is "<<myAccount->show_balence("abc")<<endl;
    cout<<"MY cash Balance is "<<myCash->show_balance()<<endl;

}

int main(){
    BankAccount *myAccount=create_account();
    MyCash *myCash= new MyCash();
    while (true)
    {
        cout<<"Select  Option "<<endl;
        cout<<"1. Add Money To Bank "<<endl;
        cout<<"2. Deposit Money From Bank "<<endl;
        cout<<"3. Add Money to MyCash From Bank "<<endl;

        int option;
        cin>>option;
        if(option == 1){
            add_money(myAccount);
        }
        else if(option == 2){
            deposit_money(myAccount);
        }
        else if(option == 3){
            add_money_from_bank(myCash,myAccount);
        }else{
            cout<<"InValid Option "<<endl;
        }
    }
    
    add_money(myAccount);
    deposit_money(myAccount);
    MyCash *myCash =new MyCash();
    add_money_from_bank(myCash,myAccount);
    return 0;
}