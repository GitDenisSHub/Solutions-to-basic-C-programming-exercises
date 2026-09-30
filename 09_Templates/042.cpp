#include <iostream>
#include <string>
using namespace std;

/*
 42. Array<T>
 Собственный динамический массив:
 Array<int>
 Array<double>
 Array<string>
 Тренирует: шаблонные классы + динамическую память

 */

template <class T>
class Array{
    T* arr;
    int size;
    int capacity;
public:
    Array(const int capacity)
    : arr(new T[capacity]), capacity(capacity), size(0){ }
    
    int GetCapacity(){return capacity;}
    int GetSize(){return size;}
    
    void AddElement(const T element){
        if(size != capacity){
            arr[size] = element;
            size++;
        }
        else{
            int help_capacity = capacity;
            T* help_arr = arr;

            capacity *= 2;
            arr = new T[capacity];
            
            for (int i = 0; i < help_capacity; i++) {
                arr[i] = help_arr[i];
            }
            
            arr[size] = element;
            size++;
            delete[] help_arr;
            
        }
    }
    
    void GetArray(){
        for (int i = 0; i < size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    ~Array(){ delete[] arr;}
    
};

int main(){
    setlocale(LC_ALL, "Rus");
    
    Array<int> arr(5);
 
    arr.GetArray();
    cout << arr.GetSize() << endl;
    cout << arr.GetCapacity() << endl;
    
    arr.AddElement(55);
    arr.AddElement(55);
    arr.AddElement(66);
    arr.AddElement(99);
    arr.AddElement(99);
    
    arr.GetArray();
    cout << arr.GetSize() << endl;
    cout << arr.GetCapacity() << endl;
    
    arr.AddElement(555);
    arr.GetArray();
    cout << arr.GetSize() << endl;
    cout << arr.GetCapacity() << endl;
    return 0;
}
