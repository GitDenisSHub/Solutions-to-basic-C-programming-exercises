#include <iostream>
#include <cstring>
using namespace std;

/*
 60. Своя очередь на массиве
 Push
 Pop
 Front
 Back
 Тренирует: FIFO.

 */

class Queue{
public:
    Queue()
    : count(-1){}
    
    void push(int data){
        if(count == -1){
            arr[0] = data;
            count++;
        }
        else{
            if((count+1) > 99){
                throw logic_error("Очередь переполнена!");
            }
            else{
                count++;
                arr[count] = data;
            }
        }
        
    }
    
    void pop(){
        if(count != -1){
            for (int i = 0; i < count; i++) {
                arr[i] = arr[i+1];
            }
            count--;
            if(count == -1){
                arr[0] = 0;
            }
        }
        else{
            cout<<"Очередь пуста! Удалять нечего!"<<endl;
        }
        
    }
    
    int front(){
        if(count == -1){
            cout<<"Элементы отсутствуют! ";
            return 0;
        }
        else{
            return arr[0];;
        }
    }
    int back(){
        if(count == -1){
            cout<<"Элементы отсутствуют! ";
            return 0;
        }
        else{
            return arr[count];
        }
        
    }
    
private:
    int arr[100];
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

    return 0;
}
