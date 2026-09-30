#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 21. BankAccount
 Поля:
 owner
 balance
 Методы:
 Deposit()
 Withdraw()
 GetBalance()
 Тренирует: инкапсуляцию, private/public, методы.
 Зачем: классический объект с состоянием.
 
 cin.ignore();
 getline(cin, Name);
 */

class BankAccount{
  
    string owner;
    int balance;
public:
    BankAccount(){
        owner = "---";
        balance = 0;
    }
    BankAccount(string owner, int balance){
        this->owner = owner;
        this->balance = balance;
    }
    void GetInfo(){
        cout<<"Owner: " << owner << " -- balance: " << balance << endl;
    }
    int GetBalance(){
        return balance;
    }
    string GetName(){
        return owner;
    }
    
    void Withdraw(int sum){
        this->balance -= sum;
        cout<<"Остаток = " << balance << " ";
    }
    
    void Deposit(int sum){
        this->balance += sum;
        cout<<"Остаток = " << balance << " ";
    }
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    BankAccount bacc[]{
      BankAccount("Denis Sementsov", rand()%100000+1),
      BankAccount("Kirill Sementsov", rand()%100000+1),
      BankAccount("Elizavets Sementsova", rand()%100000+1),
      BankAccount("Sergey Sementsov", rand()%100000+1),
      BankAccount("Denis Sementsov", rand()%100000+1),
      BankAccount("den", rand()%100000+1),
      BankAccount("Nadya Sementsova", rand()%100000+1)
    };
    int Count = sizeof(bacc)/sizeof(bacc[0]);
    
    string My_Name = "";
    int choice = 0;
    int sum = 0;
    bool is_find = false;
    cout<<"Hello, what is your name?"<<endl;
    
    getline(cin, My_Name);
    
    for (int i = 0; i < Count; i++) {
        if(My_Name == bacc[i].GetName()){
            cout<<R"(
                    Whar do u want?
                    Take money - 1
                    Deposite money 2 
                    My Balance - 3
                    Skip - 4
            )" << endl;
            cin >> choice;
            bool mistake = false;
            
            do{
                switch (choice) {
                    case 1:
                        
                        cout<<"How much do u want to take?"<<endl;
                        cin>>sum;
                        bacc[i].Withdraw(sum);
                        
                        mistake = false;
                        break;
                    case 2:
                    
                        cout<<"How much do u want to deposite?"<<endl;
                        cin>>sum;
                        bacc[i].Deposit(sum);
                        
                        
                        mistake = false;
                        break;
                    
                    case 3:
                        cout<<"====================="<<endl;
                        cout<< "My balance is " << bacc[i].GetBalance() << endl;
                        cout<<"Input Enter"<<endl;
                        cout<<"====================="<<endl;
                        cin.get();
                        
                        cout<<R"(
                                Whar do u want?
                                Take money - 1
                                Deposite money 2 
                                My Balance - 3
                                Skip - 4
                        )" << endl;
                        cin >> choice;
                        mistake = true;
                        break;
                        
                    case 4:
                        mistake = false;
                        break;
                        
                    default:
                        cout<<"Are u stupid?"<<endl;
                        mistake = true;
                        break;
                }
            }while(mistake);
            
            
            is_find = true;
        }
    }
    if(!(is_find)){
        cout<<"This owner doesn't exist!"<<endl;
    }
    
    
    return 0;
}
