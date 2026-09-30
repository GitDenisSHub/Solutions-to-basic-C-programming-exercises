#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 20. Каталог товаров
 Создать Product и реализовать поиск:
     • по имени;
     • по цене;
     • по количеству.
 Тренирует: структуры, строки, функции, поиск.
 */

struct Product{
    static int count;
    
    Product(){
        this->Name = "----";
        this->price = 0;
        this->counts_of_position = 0;
        count++;
    }
    Product(string Name, int price, int counts_of_position){
        this->Name = Name;
        this->price = price;
        this->counts_of_position = counts_of_position;
        count++;
    }
    
    void GetInfo(){
        cout<<"Name: " << this->Name << " counts: " << this->counts_of_position << " Price: " << this->price << endl;
    }
    
    string GetName(){
        return Name;
    }
    
    int GetPrice(){
        return price;
    }
    
    int GetCount(){
        return counts_of_position;
    }
  
    
private:
    string Name;
    int price;
    int counts_of_position;
    
};
int Product::count = 0;

enum Search{
    Name = 1,
    price = 2,
    counts_of_position = 3
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Product prdct[]{
      Product("Sugar", 67, 30),
      Product("Bread", 49, 15),
      Product("Chips", 120, 20),
      Product("Milk", 78, 10),
    };
    
    int choice = 0;
    string Name;
    int price;
    int counts_of_position;
    bool is_find = false;;
    
    while(choice > 3 || choice < 1){
        cout<<"What do you need to find?";
        cout<<R"(
                Name = 1,
                price = 2,
                counts_of_position = 3)"<<endl;
        cin>>choice;
    }
    
    switch (choice) {
        case 1:
            cout<<"Input ur name: "; cin>>Name;
            for (int i = 0; i < Product::count; i++) {
                if(Name == prdct[i].GetName()){
                    is_find = true;
                    cout<<"Subject is find!"<<endl;
                    prdct[i].GetInfo();
                    
                }
                
            }
            break;
        case 2:
            cout<<"Input ur price: "; cin>>price;
            for (int i = 0; i < Product::count; i++) {
                if(price == prdct[i].GetPrice()){
                    is_find = true;
                    cout<<"Subject is find!"<<endl;
                    prdct[i].GetInfo();
                    
                }
                
            }
            break;
        case 3:
            cout<<"Input ur count: "; cin>>counts_of_position;
            for (int i = 0; i < Product::count; i++) {
                if(counts_of_position == prdct[i].GetCount()){
                    is_find = true;
                    cout<<"Subject is find!"<<endl;
                    prdct[i].GetInfo();
                    
                }
                
            }
            break;
            
        default:
            cout<<"Is it possible?"<<endl;
            break;
    }
    
    if(is_find == false){
        cout<<"Product don't exist!"<<endl;
    }
    
    
    
    
    return 0;
}
