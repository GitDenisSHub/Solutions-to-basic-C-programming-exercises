#include <iostream>
#include <ctime>
#include <string>
using namespace std;



/*
 36. BankAccount + друг
 Сделать отдельную функцию, которая имеет доступ к private-данным аккаунта через friend.
 Тренирует: friendship.

 */

class BankAccount{
    string name;
    int money;
    friend void StealAcc(BankAccount& acc);
public:
    BankAccount(string Name, int Money)
    : name(Name), money(Money){ }
    
    void GetInfo(){
        cout<<"Name - " << name << " money - " << money << endl;
    }
};

void StealAcc(BankAccount& acc){
    cout<<"Ворую чужой аккаунт и порочу имя владельца! ХА-ХА-ХА!"<<endl;
    cout<<"Input bad name: "; cin >> acc.name;
    int myMoney = 0;
    cout<<"Сколько денег забрать?\nНа счету - " << acc.money << endl;
    cin>>myMoney;
    acc.money -= myMoney;
    cout<<"На счету осталось: "<< acc.money << endl;
    
    
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    BankAccount Bac("Denis", 10000);
    Bac.GetInfo();
    StealAcc(Bac);
    Bac.GetInfo();
    
    
    return 0;
}
