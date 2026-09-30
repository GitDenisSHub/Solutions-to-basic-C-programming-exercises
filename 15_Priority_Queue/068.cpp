#include <iostream>
#include <string>
#include <ostream>

using namespace std;

/*
 68. Приоритетное включение
 При добавлении элемент сразу помещается на соответствующее место.
 Тренирует: один из вариантов реализации, который мы обсуждали.
 
 Нужно переделать push()
 Мы определяем приоритет элемента и ставим его в свою позицию
 притом последним относительно одинакового приоритета
 
 rear тут меняется и теперь он не будет показывать на свободное место
 потому что под каждый элемент он заново определяет его позицию

 70. Стабильный приоритет
Если два элемента имеют одинаковый приоритет, они должны выходить в порядке поступления.
Тренирует: сочетание priority + FIFO.


 */

template <typename T>
struct Element{
    T data;
    int priority;
    
    Element()
    : data(T{}), priority(-1){}
    
    Element(T data, int priority)
    : data(data), priority(priority){}

    
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
    : arr{T{}}, count(0){}
    Priority_queue(T element)
    : arr{element}, count(1){}
    
    void push(T element){
        if(count == 0){
            arr[0] = element;
            count++;
            return;
        }
        T nothing = T{};
        if(count == size){cout<< "Массив заполнен!"<<endl; }
        else{
            for (int i = 0; i < size; i++) {
                if(element.priority < arr[i].priority || arr[i] == nothing){
                    if(arr[i] != nothing){
                        for (int j = size - 1; j > i; j--) {
                            if(arr[j-1] != T{}){ arr[j] = arr[j-1];}
                        }
                    }
                    arr[i] = element;
                    count++;
                    break;
                }
            }
        }
    }
    
    
   //Нужно переделать так, чтобы просто выходил первый элемент и все
    //Потому что элементы уже отсортированы
    void pop(){
        if(count == 0){
            cout<<"Массив пуст, удалять нечего!"<<endl;
        }
        else{
            //Оптимизация, чтобы при сравнении не пришлось все время новый создавать
            T nothing = T{};
            //Тут после удаления нужен сдвиг влево всех элементов
            if(count == 1){
                arr[0] = T{};
            }
            else{
                arr[0] = T{};
                for (int i = 0; i < size-1; i++) {
                    arr[i] = arr[i+1];
                }
                arr[size-1] = T{};
            }
            count--;
        }
    }

    
    void Front(){
        if(count == 0){
            cout<<"Элементы отсутствуют!"<<endl;
        }
        else{
            cout<<"Position is " << 0 << endl;
            cout << arr[0] << endl;
        }

        
    }
    
    void Back(){
        if(count == 0){
            cout<<"Элементы отсутствуют!"<<endl;
        }
        else{
            int i = 0;
            T nothing = T{};
            while(i + 1 != count && arr[i+1] != nothing){
                i++;
            }
            cout<<"Position is " << i << endl;
            cout << arr[i] << endl;
        }
    }
    
    
    void PrintQueue(){
        if(count == 0){ cout<<"Коллекция пуста! Выводить нечего!"<<endl;}
        else{
            int i = 0;
            while(i != count){
                cout<<arr[i]<<endl;
                i++;
            }
        }
    }
    
private:
    int size = 5;
    int count;
    T arr[5];
    
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
