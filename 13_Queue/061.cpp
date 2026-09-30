#include <iostream>
#include <cstring>
using namespace std;

/*
 61. Очередь на linked list
 Реализовать через:
 head
 tail
 Тренирует: динамическую очередь.

 */

class Queue{
public:
    Queue()
    : head(nullptr), tail(nullptr), count(0){}
    Queue(int data)
    : head(new Node(data)), tail(head), count(1){}
    
    void push(int data){
        if(count == 0){
            head = new Node(data);
            tail = head;
            count++;
        }
        else{
            tail->pNext = new Node(data);
            tail->pNext->pPrev = tail;
            tail = tail->pNext;
            count++;
        }
        
    }
    
    void pop(){
        if(count == 0){
            cout<<"Элементов больше нет! Удалять нечего!"<<endl;
        }
        else if(count == 1){
            delete head;
            tail = nullptr;
            head = nullptr;
            count--;
        }
        else{
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            
            count--;
        }
        
    }
    
    int back(){
        if(count == 0){
            cout<<"Элементов больше нету! Выводить нечего!";
            return 0;
        }
        else{
            return tail->data;
        }
        
    }
    int front(){
        if(count == 0){
            cout<<"Элементов больше нету! Выводить нечего!";
            return 0;
        }
        else{
            return head->data;
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
        Node(int data)
        : pNext(nullptr), pPrev(nullptr), data(data){}
        
    private:
        Node* pNext;
        Node* pPrev;
        int data;
        friend class Queue;
    };
    
private:
    Node* head;
    Node* tail;
    int count;
    
};

int main(){
    setlocale(LC_ALL, "Rus");
   
    
    Queue que;
    que.push(55);
    que.push(11);
    que.push(22);
    que.push(33);
    que.push(66);
    
    cout << que.front() << endl;
    cout << que.back() << endl;
   
    que.pop();
    que.pop();
    cout<<"============"<<endl;
    cout << que.front() << endl;
    cout << que.back() << endl;
    
    que.pop();
    que.pop();
    cout<<"============"<<endl;
    cout << que.front() << endl;
    cout << que.back() << endl;
    
    que.pop();
    cout<<"============"<<endl;
    cout << que.front() << endl;
    cout << que.back() << endl;
     
    que.push(33);
    que.push(66);
    return 0;
}
