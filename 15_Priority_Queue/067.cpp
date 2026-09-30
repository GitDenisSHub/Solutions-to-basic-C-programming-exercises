#include <iostream>
#include <string>
#include <ostream>
#include <ctime>
#include <climits>
using namespace std;

/*
 67. Приоритетная очередь на массиве
 Каждый элемент:
 value
 priority
 Реализовать добавление и удаление.
 Тренирует: priority queue.
 
 rear у меня больше не будет обозначать какие-то границы
 это будет указание на пустую ячейку и все!
 Но при выводе это будет последний элемент который будет требоваться для вывода

 69. Приоритетное удаление
Хранить элементы обычным образом, но при удалении искать максимальный приоритет.
Тренирует: второй вариант.


 Не идеальный, но полностью законченный рабочий код


 */

template <typename T>
struct Element{
    T data;
    int priority;
    
    Element()
    : data(T{}), priority(-1){}
    
    Element(T data, int priority)
    : data(data), priority(priority){}
    
    void PrintEl(){ cout<<this->data << " - priority is: " << this->priority << endl;}
    
    
};

template <typename T>
bool operator!=(const Element<T>& a, const Element<T>& b)
{
    return a.data != b.data || a.priority != b.priority;
}

template <typename T>
bool operator==(const Element<T>& a, const Element<T>& b)
{
    return a.data == b.data && a.priority == b.priority;
}

template <typename T>
ostream& operator<<(ostream& out, const Element<T>& el){
    
    out << el.data + " - priority is: " +  to_string(el.priority);
    return out;
}

template <class T>
class Priority_queue{
public:
    Priority_queue()
    : arr{T{}}, count(0), rear(-1){}
    Priority_queue(T element)
    : arr{element}, count(1){
        if(size == 1) rear = -1;
        else rear = 1;
    }
    

    void push(T element){
        if(count == 0){
            arr[0] = element;
            rear = 1;
            if(rear == size){ rear = -1;}
            count++;
        }
        else{
            
            if(count == size){ cout<< "Массив заполнен!"<<endl; }
            else{
                arr[rear] = element;
                count++;
                rear++;
                //rear = -1 означает, что массив заполнен весь и что для rear нету свободной позиции
                if(count == size){ cout<< "Массив заполнен!"<<endl; rear = -1;}
                else{
                    if(rear == size){ rear = 0;}
                    while(arr[rear] != T{}){
                        rear++;
                        if(rear == size){ rear = 0;}
                    }
                }
            }
        }
        
    }
    
    
    
    void pop(){
        if(count == 0){
            cout<<"Массив пуст, удалять нечего!"<<endl;
        }
        else{
            //Оптимизация, чтобы при сравнении не пришлось все время новый создавать
            T nothing = T{};

            int min_priority = INT_MAX;
            int min_index = -1;
        
            for (int i = 0; i < size; i++) {
                if(arr[i] != nothing && arr[i].priority < min_priority){
                    min_priority = arr[i].priority;
                    min_index = i;
                }
            }
            
            if(min_index != -1){
                if(count == 1){
                    arr[min_index] = T{};
                    rear = -1;
                }
                else{
                    arr[min_index] = T{};
                    if(rear == -1 || rear > min_index) rear = min_index;
                }
                count--;
            }

        }
    }

    
    void Front(){
        if(count == 0){
            cout<<"Элементы отсутствуют!"<<endl;
        }
        else{
            int i = 0;
            while(arr[i] == T{}){ i++;}\
            if(i != size){
                cout<<"Position is " << i << endl;
                cout << arr[i] << endl;
            }
        }

        
    }
    
    void Back(){
        if(count == 0){
            cout<<"Элементы отсутствуют!"<<endl;
        }
        else{
            int i = size - 1;
            while(arr[i] == T{}){ i--;}
            if(i != -1){
                cout<<"Position is " << i << endl;
                cout << arr[i] << endl;
            }
        }
    }
    
    
    void PrintQueue(){
        if(count == 0){ cout<<"Коллекция пуста! Выводить нечего!"<<endl;}
        else{
            int i = 0;
            while(i != size){
                
                if(arr[i] != T{}){
                    cout<<arr[i]<<endl;
                }
                
                i++;
            }
        }
    }
    
private:
    int size = 5;
    int count;
    T arr[5];
    int rear;
    
};



int main(){
    setlocale(LC_ALL, "Rus");

    
    Priority_queue<Element<string>> pq;
    
    cout << "=== ДОБАВЛЯЕМ 5 ЭЛЕМЕНТОВ ===" << endl;

    pq.push(Element<string>("A", 5));
    pq.push(Element<string>("B", 4));
    pq.push(Element<string>("C", 3));
    pq.push(Element<string>("D", 2));
    pq.push(Element<string>("E", 1));
    
    cout << "\n=== СОСТОЯНИЕ ===" << endl;
    pq.PrintQueue();
    
    cout << "\n=== УДАЛЯЕМ 2 ЭЛЕМЕНТА ===" << endl;

    pq.pop();
    pq.pop();
    
    cout << "\n=== СОСТОЯНИЕ ПОСЛЕ 2 POP ===" << endl;
    pq.Front();
    pq.Back();
    pq.PrintQueue();
    
    cout << "\n=== ДОБАВЛЯЕМ F ===" << endl;

    pq.push(Element<string>("F", 6));
   
    pq.PrintQueue();
  
    cout << "\n=== УДАЛЯЕМ ЕЩЁ 1 ===" << endl;

    pq.pop();

    cout << "\n=== СОСТОЯНИЕ ===" << endl;
    pq.Front();
    pq.Back();
    pq.PrintQueue();
    
    
    cout << "\n=== ДОБАВЛЯЕМ G ===" << endl;

    pq.push(Element<string>("G", 7));

    cout << "\n=== ФИНАЛ ===" << endl;
    pq.Front();
    pq.Back();
    pq.PrintQueue();
    
    cout << "\n=== ДОБАВЛЯЕМ H ===" << endl;

    pq.push(Element<string>("H", 8));
    
    cout << "\n=== ФИНАЛ ===" << endl;
    pq.Front();
    pq.Back();
    pq.PrintQueue();
    
    
    return 0;
}
