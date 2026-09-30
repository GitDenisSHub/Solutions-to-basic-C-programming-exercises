#include <iostream>

using namespace std;

/*
 swap через ссылку и указатель
Написать swap(int&, int&), меняющую местами два числа.
Тренирует: ссылки, передачу параметров.
Зачем: базовая проверка понимания, что ссылка позволяет функции работать с исходной переменной.
*/

void swap(int& a, int& b){
    int help = a;

    a = b;
    b = help;
    
}

void swap(int* a, int* b){
    int help = *a;

    *a = *b;
    *b = help;
}

int main(){
    setlocale(LC_ALL, "Rus");
    
    int a = 5, b = 10;
    cout<<a<<" "<<b<<endl;
    
    swap(a, b);
    
    cout<<a<<" "<<b<<endl;
    
    swap(&a, &b);
    
    cout<<a<<" "<<b<<endl;
    
    return 0;
}
