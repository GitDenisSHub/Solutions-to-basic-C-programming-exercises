#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

/*
 13. Рекурсивное переворачивание строки
Вывести строку в обратном порядке рекурсивно.
Тренирует: рекурсивные вызовы и состояние стека вызовов.
Зачем: очень хорошо связывает рекурсию с тем самым стеком, который ты уже изучил.

*/

void Rec_Str(char* str, int size){
    
    int index = size;
    cout<<str[index]<<" ";
    
    if(index == 0){
        cout<<endl;
        return;
    }
    return Rec_Str(str, --index);
}



int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
 
    char str[] = "Hello world!";
    Rec_Str(str, strlen(str) - 1);
    
    return 0;
}
