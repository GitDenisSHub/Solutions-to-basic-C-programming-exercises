#include <iostream>
#include <string>
using namespace std;

/*
 41. Pair<T1,T2>
 Создать собственный шаблонный класс пары.
 Тренирует: class templates.

 */

template <class T1, class T2>
class MyClass{
    T1 First;
    T2 Second;
public:
    MyClass()
    : First(T1{}), Second(T2{}){}
    
    MyClass(T1 first, T2 second)
    : First(first), Second(second){ }
    
    T1 GetFirst(){ return First;}
    T2 GetSecond(){ return Second;}
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    MyClass obj(25, "Denis");
    MyClass<string, int> obj2;
    
    cout << obj.GetFirst() << endl;
    cout << obj.GetSecond() << endl;
    
    cout << obj2.GetFirst() << endl;
    cout << obj2.GetSecond() << endl;
   
    return 0;
}
