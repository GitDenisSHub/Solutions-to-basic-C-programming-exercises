#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
 64. Реализовать кольцевую очередь
 Массив фиксированного размера.
 Использовать:
 front
 rear
 и циклическое движение индексов.
 Тренирует: кольцевую организацию памяти.

 65. Заполнение и освобождение
Специально протестировать ситуации:
заполнить
удалить несколько
добавить снова
Тренирует: именно ту проблему, ради которой существует circular queue
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
    
private:
    int front;
    int rear;
    int size = 3;
    T arr[3];
};

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    CircularQueue<int> cq(55);
    cq.Front();
    cq.Back();
    cout<<" ================ " << endl;
    cq.push(99);
    cq.Front();
    cq.Back();
    cout<<" ================ " << endl;
    cq.push(888);
    cq.Front();
    cq.Back();
    
    cq.pop();
    cout<<" ================ " << endl;
    cq.push(555);
    cq.Front();
    cq.Back();
    
    cout<<" ================ " << endl;
    cq.pop();
    cq.Front();
    cq.Back();
    
    cout<<" ================ " << endl;
    cq.pop();
    cq.Front();
    cq.Back();
    
    cout<<" ================ " << endl;
    cq.pop();
    cq.Front();
    cq.Back();
    //0 - 1 - 2
    
    return 0;
}
