#include <iostream>
#include <string>
using namespace std;



/*
 39. Вложенный класс + private
 Сделать так, чтобы вложенный класс имел доступ к определённым private-данным внешнего класса через явно организованный доступ.
 Тренирует: вложенные классы + friendship.

 */



class Computer{
public:
    
    class CPU{
        string NameCPU;
        Computer& comp;
    public:
        CPU(Computer& comp)
        : NameCPU("NONE"), comp(comp){cout<<"Конструктор по умолчанию CPU!"<<endl;}
        CPU(string name, Computer& comp)
        : NameCPU(name), comp(comp) {cout<<"Конструктор с параметром CPU!"<<endl;}
        string GetNameCPU(){ return NameCPU;}
        
        void WhereAmI(){
            cout<<"Имя компьютера внутри которого я лежу: ";
            cout<<comp.NameCOMPUTER<<endl;
        }
    };
    
    Computer(string name, string Name_CPU) : cpu(Name_CPU, *this), NameCOMPUTER(name){
        cout<<"Конструктор с параметром Computer и процессором!"<<endl;
    }
    Computer(string name) : cpu(*this), NameCOMPUTER(name){
        cout<<"Конструктор с параметром Computer без процессора!"<<endl;
    }
    string GetNameCPU(){
        cpu.WhereAmI();
        return cpu.GetNameCPU();
    }
    string GetNamePC(){
        return NameCOMPUTER;
    }
    
private:
    string NameCOMPUTER;
    CPU cpu;
    //friend class CPU;
};


int main(){
    setlocale(LC_ALL, "Rus");
    
    Computer comp("MyPC");
    cout << comp.GetNameCPU() << endl;
    
   
    return 0;
}
