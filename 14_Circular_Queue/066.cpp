#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
 66. Симуляция кольца
 Люди стоят в кругу. Каждый K-й человек удаляется.
 Тренирует: циклическую обработку данных.
 Это уже практически подвод к задаче Иосифа.

 - нужен метод для удаления элемента из середины очереди
 - нужен метод, который удаляет каждого третьего, изменяет параметры очереди, расстановку элементов
 - сделаем симулацию, не изменяя саму очередь непосредственно, просто будем исключать отдельные индексы


Рабочая версия для конкретного случая, не идеальная
«Моя симуляция работает для текущей модели очереди, но не покрывает все состояния настоящей кольцевой очереди».e
 */

template <class T>
class CircularQueue{
public:
   CircularQueue()
    : front(-1), rear(0), arr{T{}}{}
   CircularQueue(T data)
    : front(0), rear(1), arr{data} {}
    
    void Front(){
        
        if(front != -1){
            cout << arr[front] << endl;
            cout<<"Position is " << front << endl;
        }
        else{
            cout<<"Элементы отсутствуют!"<<endl;
        }
    }
    
    void Back(){
        
        if(front != -1){
            if(rear == 0){
                cout << arr[size-1] << endl;
                cout<<"Position is " << size-1 << endl;
            }
            else{
                cout << arr[rear-1] << endl;
                cout<<"Position is " << rear-1 << endl;
            }
            
        }
        else{
            cout<<"Элементы отсутствуют!"<<endl;
        }
    }
   
    void pop(){
        if(front == -1){
            cout<<"Массив пуст, удалять нечего!"<<endl;
        }
        else{
            if(front+1 == rear || (front+1 == size && rear == 0)){
                arr[front] = T{};
                cout<<"Массив очищен!"<<endl;
                front = -1;
            }
            else if(front+1 == size){
                arr[front] = T{};
                front = 0;
            }
            else{
                arr[front] = T{};
                front++;
            }
            
        }
        
    }
    
    void push(T data){
        if(front == -1){
            front = 0;
            rear = 1;
            arr[0] = data;
        }
        else{
            if(rear > size-1){
                rear = (rear )%size;
                if(rear == front && front != -1){
                    cout<<"Масств заполнен!"<<endl;
                }
                else{
                    arr[rear] = data;
                    rear++;
                }
            }
            else if(rear == front){
                cout<<"Массив заполнен!"<<endl;
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }
    }
    
    void Simulation(){
        //Массив исключенных элементов
        int del[size];
        //Элемент-переборщик и общее количество элементов
        int current = front, count = rear - 1;
        //Счетчик убранных элементов
        int toDel = 0;
        bool is_find = true;
        //Переменная для шагов
        int step = 0;
        
        //Делаем до тех пор, пока у нас не остался 1 элемент(нулевой)
        //Собираем массив, делаем порядок когда удаляютя элементы (это верно)
        while(count > 0){
            //Вывод работает верно!
            for (int i = 0; i < rear; i++) {
                is_find = false;
                for (int j = 0; j < toDel; j++) {
                    if(i == del[j]){ is_find = true; break;}
                }
                if(!is_find){ cout<< arr[i] << " "; }

            }
            cout << endl << endl;
            //Делаем по 2 шага вперед
            step = 0;
            while(step < 2){
                //Определяем, есть ли элемент уже в массиве, чтобы не удалять его дважды
                bool is_there = true;
                
                
                
                
                
                
                
                
                //Главный смысл - выйнести отсюда значение, которого нету
                while(is_there){
                    is_there = false;
                    for (int i = 0; i < toDel; i++) {
                        if(current == del[i]){
                            current++;
                            if(current == rear){ current = 0;}
                            is_there = true;
                        }
                    }
                }

                current++;
                //Сначала нужно обезопасить ход, чтобы код не работал с неправильными значениями
                //Если он упирается в стену(rear) - начинаем с нуля
                if(current == rear){ current = 0;}
                is_there = true;
                
                //Тут проверить окончательно - живое ли это число?
                while(is_there){
                    is_there = false;
                    for (int i = 0; i < toDel; i++) {
                        if(current == del[i]){
                            current++;
                            if(current == rear){ current = 0;}
                            is_there = true;
                        }
                    }
                }
        
                step++;
            }
            //Это работает очень странно - почему я тут вычита 1??
            del[toDel] = current;
            cout<<"Удаляем элемент - " << current << endl;
            
            
            
            
            
            
            
            
            
            
            
            
            toDel++;
            //Тут я вычитаю, чтобы контролировать количество выведеных чисел
            count--;
        }
    }
    
private:
    int front;
    int rear;
    int size = 10;
    T arr[10];
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    CircularQueue<string> cq("Denis");
    cq.push("Kirill");
    cq.push("Max");
    cq.push("Liza");
    cq.push("Sergey");
    cq.push("Alex");
    cq.push("Peter");

    
    cq.Front();
    cq.Back();
    
    cq.Simulation();
   
    
    return 0;
}
