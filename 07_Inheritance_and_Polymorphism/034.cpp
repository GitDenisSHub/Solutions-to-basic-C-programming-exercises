#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;



/*
 34. Виртуальный деструктор
 Создать иерархию классов с динамическими ресурсами и проверить поведение при удалении через указатель базового класса.
 Тренирует: виртуальные деструкторы.
 Зачем: крайне важная деталь ООП на C++.

 */

class One{
    
public:
    virtual void Method(){cout<<"Выделяем динамическую память!"<<endl;}
    
    virtual ~One(){ cout<<"Освобождаем динамическую память!!"<<endl;}
};

class Two : public One {
    
public:
    void Method() override {cout<<"Выделяем ресурсы!"<<endl;}
    
    ~Two() override { cout<<"Освобождаем ресурсы!"<<endl;}
    
};


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    /*
    One one;
    one.Method();
    Two two;
    two.Method();
    */
    Two* two = new Two;
    
    One* one = new Two;
    
    
    
    delete two;
    delete one;
    return 0;
}
