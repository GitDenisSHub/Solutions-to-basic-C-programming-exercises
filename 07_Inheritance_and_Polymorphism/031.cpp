#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

/*
 31. Животные
 Базовый класс:
 Animal
 Производные:
 Dog
 Cat
 Bird
 Каждый переопределяет:
 Sound()
 Тренирует: наследование и виртуальные функции.
 */

class Animal{

public:
    
    virtual void Sound(){
        
    };
    
};

class Dog : public Animal{
    
public:
    void Sound() override{
        cout<<"Gav - Gav!"<<endl;
    }
};

class Cat : public Animal{
    
public:
    void Sound() override{
        cout<<"Meow - meow!"<<endl;
    }
};

class Bird : public Animal{
    
public:
    void Sound() override{
        cout<<"Chiric - Chiric!"<<endl;
    }
};





int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    
    Animal* animal;
    Dog a;
    Cat c;
    Bird b;
    a.Sound();
    c.Sound();
    b.Sound();
    
    animal = &a;
    animal->Sound();
    
    return 0;
}
