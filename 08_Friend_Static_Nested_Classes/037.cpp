#include <iostream>
#include <ctime>
#include <string>
using namespace std;



/*
 37. Счётчик объектов
 Класс считает количество существующих объектов через static.
 Тренирует: static-поле, конструктор, деструктор.

 */

class BankAccount{
    string name;
    int money;
    friend void StealAcc(BankAccount& acc);
    
    static int count;
public:
    BankAccount(string Name, int Money)
    : name(Name), money(Money){ count++;}
    
    void GetInfo(){
        cout<<"Name - " << name << " money - " << money << endl;
    }
    
    ~BankAccount(){ count--;}
};

int BankAccount::count = 0;

void StealAcc(BankAccount& acc){
    cout<<"Ворую чужой аккаунт и порочу имя владельца! ХА-ХА-ХА!"<<endl;
    
    cout<<"Сколько аккаунтов мы можем украсть: " << acc.count<<endl;
    
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
    {
        BankAccount Bac2("Kirill", 9999);
    }
    
    BankAccount Bac3("Sergey", 0);
    Bac.GetInfo();
    StealAcc(Bac);
    Bac.GetInfo();
    
    
    return 0;
}
