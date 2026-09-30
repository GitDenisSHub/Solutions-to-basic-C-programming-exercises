#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 25. Конструкторы
 Создать класс Person с:
     • конструктором по умолчанию;
     • конструктором с параметрами;
     • копирующим конструктором;
     • деструктором.
 Добавить вывод сообщений при вызове каждого.
 Тренирует: жизненный цикл объекта.
 */

class Person{
    string Name;
    int age;
public:
    
    Person()
    : Name("---"), age(0){cout<<"Конструктор по умолчанию"<<endl;}
    
    Person(string Name, int age)
    : Name(Name), age(age){cout<<"Конструктор с параметрами"<<endl;}
    
    
    Person(const Person& another){
        this->Name = another.Name;
        this->age = another.age;
        cout<<"Конструктор копирования"<<endl;
    }
     
    
    ~Person(){cout<<"Вызов деструктора"<<endl;}
    
    void GetInfo(){
        cout<<"Метод вывода информации об объекте"<<endl;
        cout<<Name<<" -- "<<age<<endl;
    }
    
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Person one("Denis", 24);
    Person two(one);
      
    one.GetInfo();
    two.GetInfo();
    
    return 0;
}
