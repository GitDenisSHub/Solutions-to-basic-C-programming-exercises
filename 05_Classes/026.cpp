#include <iostream>
#include <ctime>
#include <string>
using namespace std;

/*
 26. Глубокое копирование
 Создать класс, содержащий динамический массив:
 class Array
     int* data
     int size
 Реализовать:
     • конструктор;
     • деструктор;
     • копирующий конструктор;
     • оператор =.
 Тренирует: владение динамической памятью, Rule of Three.
 Зачем: одна из самых важных задач на твой текущий уровень.
 Выводить сообщения при вызове каждого
 */

class Array{
    int size;
    int* data;
public:
    Array(const int size): size(size){
        cout<<"Конструктор с параметрами"<<endl;
        data = new int[this->size];
        
        for (int i = 0; i < this->size; i++) {
            data[i] = rand()%100+1;
        }
    }
    
    Array(const Array& another){
        cout<<"Конструктор копирования"<<endl;
        
        data = new int[another.size];
        this->size = another.size;
        
        for (int i = 0; i < this->size; i++) {
            this->data[i] = another.data[i];
        }
    }
    
    void operator=(const Array& another){
        
        if(this != &another){
            delete[] this->data;
            this->data = new int[another.size];
            this->size = another.size;
            
            cout<<"Оператор копирования"<<endl;
            for (int i = 0; i < this->size; i++) {
                this->data[i] = another.data[i];
            }
        }
        
    }
    
    void GetInfo(){
        cout<<"Выводим информацию"<<endl;
        for (int i = 0; i < this->size; i++) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
    ~Array(){
        cout<<"Вызов деструктора"<<endl;
        delete[] this->data;
    }
    
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    Array x(5);
    Array y(10);
    
    x.GetInfo();
    y.GetInfo();
    
    y = x;
    
    x.GetInfo();
    y.GetInfo();
    
    return 0;
}
