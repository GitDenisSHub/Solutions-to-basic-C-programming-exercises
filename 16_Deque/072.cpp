#include <iostream>


using namespace std;

/*
 72. Дек на двусвязном списке
 Использовать head и tail.
 Тренирует: естественную реализацию дека.
 Реализовать PushFront, PushBack, PopFront, PopBack, print_deque

 */

class Deque{
public:
    Deque()
    : head(nullptr), tail(nullptr), count(0){}
    Deque(int value)
    : head(new Node(value)), tail(head), count(1){}
    
    void push_front(int data){
        if(count == 0){
            head = tail = new Node(data);
            count++;
        }
        else{
            head->pPrev = new Node(data);
            head->pPrev->pNext = head;
            head = head->pPrev;
            count++;
            
        }
    }
    
    void push_back(int data){
        if(count == 0){
            head = tail = new Node(data);
            count++;
        }
        else{
            tail->pNext = new Node(data);
            tail->pNext->pPrev = tail;
            tail = tail->pNext;
            count++;
        }
    }
    
    void pop_front(){
        if(count == 0){cout<<"Удалять нечего! Очередь пуста!"<<endl;}
        else if(count == 1){ delete head; head = tail = nullptr; count--; cout << "Мы удалили последний элемент очереди!"<<endl;}
        else{
            head = head->pNext;
            delete head->pPrev;
            head->pPrev = nullptr;
            count--;
        }
    }
    
    void pop_back(){
        if(count == 0){cout<<"Удалять нечего! Очередь пуста!"<<endl;}
        else if(count == 1){ delete head; head = tail = nullptr; count--; cout << "Мы удалили последний элемент очереди!"<<endl;}
        else{
            tail = tail->pPrev;
            delete tail->pNext;
            tail->pNext = nullptr;
            count--;
        }
    }
    
    
    void print_deque(){
        Node* currentNode = head;
        if(count == 0) { cout<<"Очередь пуста! Выводить нечего!"<<endl;}
        else{
            while(currentNode != nullptr){
                cout<<currentNode->data<<" ";
                currentNode = currentNode->pNext;
                
            }
            cout<<endl;
        }
    }
    
    void clear(){
        while(count != 0){ pop_back();}
    }
    
    ~Deque(){ clear(); print_deque();}
    
    class Node{
    public:
        Node()
        : pNext(nullptr), pPrev(nullptr), data(0){}
        Node(int data)
        : pNext(nullptr), pPrev(nullptr), data(data){}
        
    private:
        int data;
        Node* pNext;
        Node* pPrev;
        friend class Deque;
        
    };
private:
    int count;
    Node* head;
    Node* tail;
    
};

int main() {
    setlocale(LC_ALL, "Rus");

    Deque deq(55);
    deq.push_front(99);
    deq.push_back(777);
    deq.push_front(1);
    
    deq.pop_front();
    deq.pop_back();
    deq.pop_front();
    deq.pop_back();
    
    deq.print_deque();

    
    cout<<"================"<<endl;
    return 0;
}
