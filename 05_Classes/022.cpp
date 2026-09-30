#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 22. Counter
 Класс хранит число и умеет:
 Тренирует: состояние объекта и методы.
 
 Increase() → увеличить хранящееся число на 1.
 Decrease() → уменьшить хранящееся число на 1.
 Reset() → сбросить число обратно в 0.
 GetValue() → вернуть текущее значение числа
 */

class Counter{
    int value;
public:
    Counter(){
        this->value = 0;
    }
    Counter(int value){
        this->value = value;
    }
    int GetValue(){
        return value;
    }
    void Reset(){
        this->value = 0;
    }
    void Increase(){
        this->value += 1;
    }
    void Decrease(){
        this->value -= 1;
    }
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Counter cnt(5);
    cout<< cnt.GetValue()<<endl;
    
    cnt.Increase();
    cnt.Increase();
    cnt.Increase();
    
    cout<< cnt.GetValue()<<endl;
    
    cnt.Decrease();
    
    cout<< cnt.GetValue()<<endl;
    
    cnt.Reset();
    
    cout<< cnt.GetValue()<<endl;
    
    return 0;
}
