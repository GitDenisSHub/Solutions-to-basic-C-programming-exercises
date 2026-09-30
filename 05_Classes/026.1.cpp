#include <iostream>
#include <ctime>
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
    
    Array(Array&& another)
        : data(std::move(another.data)), size(another.size)
    {
        cout<<"Конструктор перемещения"<<endl;
        
        for (int i = 0; i < this->size; i++) {
            cout<<this->data[i]<<" ";
        }
        cout<<endl;
        another.data = nullptr;
        another.size = 0;
        
        
        
    }
    
    Array& operator=(const Array& another){
        
        
        if(this != &another){
            if(another.data != nullptr){
                delete[] this->data;
                this->data = new int[another.size];
                this->size = another.size;
                
                cout<<"Оператор копирования"<<endl;
                for (int i = 0; i < this->size; i++) {
                    this->data[i] = another.data[i];
                }
            }
            else{
                cout<<"Ошибка! Второй объект не содержит данных! Копирование не произведено"<<endl;
            }
            
        }
        
        return *this;
        
    }
    
    Array& operator=(Array&& another)
    {
        cout<<"Оператор пермещения"<<endl;
        
        
        if(this != &another){
            if(another.data != nullptr){
                delete[] this->data;
                this->data = another.data;
                this->size = another.size;

                another.data = nullptr;
                another.size = 0;
                
                
            }
            else{
                cout<<"Ошибка! Второй объект не содержит данных! Копирование не произведено"<<endl;
            }
            
        }
        
        return *this;
        
    }
    
    void GetInfo(){
        cout<<"Выводим информацию"<<endl;
        if(this->data != nullptr){
            for (int i = 0; i < this->size; i++) {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"Данные отсутствуют!"<<endl;
        }
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
    x.GetInfo();
    
    Array y(std::move(x));
    
    
    y.GetInfo();
    
    y = std::move(x);
    
    x.GetInfo();
    y.GetInfo();
    
    return 0;
}
