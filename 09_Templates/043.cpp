#include <iostream>
using namespace std;

/*
 43. Специализация
 Создать шаблон Printer<T>, а для char* сделать отдельную специализацию.
 Тренирует: specialization.

 */

template <class T>
class Printer{
    T value;
public:
    Printer(const T value)
    : value(value){ }
    
    void PrintValue(){
        cout<<"Our value is " << value << endl;
    }
};

template<>
class Printer<const char*>{
     const char* value;
public:
    Printer(const char* value)
    : value(value){ }
    
    void PrintValue(){
        cout<<"Our text is  " << value << endl;
    }
};
 
int main(){
    setlocale(LC_ALL, "Rus");
    
    Printer pr1(55);
    Printer pr2("Hello");
    
    pr1.PrintValue();
    pr2.PrintValue();

  
    return 0;
}
