#include <iostream>
#include <cstring>
using namespace std;

/*
 57. Проверка скобок
 Твоя задача:
 ([{}])
 → true
 ([)]
 → false.
 Тренирует: применение стека к реальной задаче.
 
 чере стек, сначала записываем открывающие, потом по очереди проверяем закрывающие с последней открывающей - сошлось,
 значит удаляем последнюю открывающую и так далее, пока количество открывающих не станет 0)
 */

template <class T>
class Stack{
public:
    Stack()
    : head(nullptr), counter(0){}
    Stack(T data)
    : head(new Node(data)), counter(0){}
    
    void push(T data){
        if(head == nullptr){
            if(data == '(' || data == '{' || data == '['){
                head = new Node(data);
                counter++;
            }
            else{
                throw logic_error("Оштибка! Первым должен быть открывающий символ!");
            }
        }
        else{
            if(data == '(' || data == '{' || data == '['){
                Node* currentNode = head;
                while(currentNode->pNext != nullptr){
                    currentNode = currentNode->pNext;
                }
                currentNode->pNext = new Node(data);
                counter++;
            }
            else if(data == ')' || data == '}' || data == ']'){
                
                T last = this->top();
                
                if(last == '(' && data == ')'){
                    this->pop();
                    
                }
                else if (last == '[' && data == ']'){
                    this->pop();
                    
                }
                else if(last == '{' && data == '}'){
                    this->pop();
                    
                }
                else{
                    throw logic_error("Строка не прошла проверку на скобки!");
                }
                
            }
            else{
                cout<<"Принимаются только скобки! Не нужно фигню добавлять!"<<endl;
            }

        }
    }
    
    void pop(){
        if(head == nullptr){
            cout<<"Коллекция пуста! Удалять нечего!"<<endl;
        }
        else if(head->pNext == nullptr){
            delete head;
            head = nullptr;
            counter--;
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            delete currentNode->pNext;
            currentNode->pNext = nullptr;
            counter--;
        }
        
    }
    
    int top(){
        if(head == nullptr){
            //throw logic_error("Стек пуст!");
            return ' ';
        }
        else{
            Node* currentNode = head;
            while(currentNode->pNext != nullptr){
                currentNode = currentNode->pNext;
            }
            cout<<currentNode->data<<endl;
            return currentNode->data;
        }
        
    }
    
    bool empty(){
        if(head == nullptr){
            return true;
        }
        else return false;
    }
    
    
    void clear(){
        while(head != nullptr){ pop();}
    }
    
    ~Stack(){ clear();}
    
    class Node{
        Node* pNext;
        T data;
        friend class Stack;
    public:
        Node()
        : pNext(nullptr), data(T{}){ }
        Node(T data)
        : pNext(nullptr), data(data){}
        
    };

private:
    Node* head;
    int counter;
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    const char* str = "(([{[]}]))";
    const char* str2 = "(([{[]}]])";
    const char* wrong_str2 = "([)]";
    const char* wrong_str = "(((((";
    const char* wrong_str3 = "((((())";
    
    Stack<char> stk;
    
    try {
        for (int i = 0; i < strlen(wrong_str3); i++) {
            stk.push(wrong_str3[i]);
            //stk.top();
        }
        if(stk.empty()){
            cout<<"Строка успешно прошла проверку!"<<endl;
        }
        else{
            cout<<"Открывающих скобок оказалось больше, чем закрывающих!"<<endl;
        }
        
    } catch (const std::exception& ex) {
        cout<<ex.what()<<endl;
    }
    
    
    return 0;
}
