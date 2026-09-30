#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*
 62. Симуляция очереди
 Есть очередь покупателей. Каждый имеет время обслуживания.
 Симулировать их обслуживание.
 Тренирует: очередь + моделирование.

 */

template <class T>
class Queue{
public:
    Queue()
    : head(nullptr), tail(nullptr), count(0){}
    Queue(T data)
    : head(new Node(data)), tail(head), count(1){}
    
    void push(){
        if(count == 0){
            count++;
            string str = "Покупатель ";
            head = new Node(str);
            tail = head;
            
        }
        else{
            count++;
            string str = "Покупатель ";
            tail->pNext = new Node(str);
            tail->pNext->pPrev = tail;
            tail = tail->pNext;
            
        }
        
    }
    
    void pop(){
        if(count == 0){
           
            throw logic_error("Элементов больше нет! Удалять нечего!");
        }
        else if(count == 1){
            head->personalNum = 1;
            int time = rand()%5+1;
            cout << head->data + to_string(head->personalNum) << "---> " << time << " минут в кабинете" << endl;
            while(time != 0){
                cin.get();
                time--;
            }
            
            delete head;
            tail = nullptr;
            head = nullptr;
            count--;
            
        }
        else{
            int time = rand()%5+1;
            cout << head->data + to_string(head->personalNum) << "---> " << time << " минут в кабинете" << endl;
            while(time != 0){
                cin.get();
                time--;
            }
            
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            
            Node* currentNode = head;
            int i = 1;
            while(currentNode->pNext != nullptr){
                currentNode->personalNum = i;
                currentNode = currentNode->pNext;
                i++;
            }
            Node::number--;
            
            count--;
        }
        
    }
    
    T back(){
        if(count == 0){
            cout<<"Элементов больше нету! Выводить нечего!";
            return T{};
        }
        else{
            return tail->data  + to_string(tail->personalNum);
        }
        
    }
    T front(){
        if(count == 0){
            cout<<"Элементов больше нету! Выводить нечего!";
            return T{};
        }
        else{
            return head->data + to_string(head->personalNum);
        }
        
    }
    
    ~Queue(){
        while(count != 0){
            pop();
        }
    }
    
    
    class Node{
    public:
        Node()
        : pNext(nullptr), pPrev(nullptr), data(0){}
        Node(T data)
        : pNext(nullptr), pPrev(nullptr),personalNum(0), data(data) {number++; personalNum = number;}
        int GetNumber(){ return number;}
        
        static int number;
    private:
        Node* pNext;
        Node* pPrev;
        int personalNum;
        
        T data;
        friend class Queue;
    };
    
private:
    
    Node* head;
    Node* tail;
    int count;
};

template <class T>
int Queue<T>::Node::number = 0;


int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    
    Queue<string> que;
    que.push();
    que.push();
    que.push();
    que.push();
    que.push();
    que.push();
    
    try {
        cout<<"Обслуживание клиентов!"<<endl;
        while(Queue<string>::Node::number != 0){
            
            que.pop();
            //Queue<string>::Node::number--;
        }
    } catch (const std::exception& ex) {
        cout<<ex.what()<<endl;
    }
    
    
    
    return 0;
}
