#include <iostream>
#include <string>
using namespace std;



/*
 38. Вложенный класс
 Создать:
 Computer
     class CPU
 и использовать CPU внутри Computer.
 Тренирует: nested classes.

 */



class Computer{
public:
    
    class CPU{
        string Name;
    public:
        CPU()
        : Name("NONE"){cout<<"Конструктор по умолчанию CPU!"<<endl;}
        CPU(string name)
        : Name(name) {cout<<"Конструктор с параметром CPU!"<<endl;}
        string GetName(){ return Name;}
    };
    
    Computer(string Name_CPU) : cpu(Name_CPU){
        cout<<"Конструктор с параметром Computer!"<<endl;
    }
    string GetNameCPU(){
        return cpu.GetName();
    }
    
private:
    string Name;
    CPU cpu;
};


int main(){
    setlocale(LC_ALL, "Rus");
    
    Computer comp("AMD");
    cout << comp.GetNameCPU() << endl;
   
    return 0;
}
