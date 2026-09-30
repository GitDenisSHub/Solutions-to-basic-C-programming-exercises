#include <iostream>

using namespace std;

/*
 8. Своя функция strlen
 Реализовать определение длины C-строки через указатель.
 Тренирует: указательную арифметику.
 Зачем: увидеть отличие указателей от обычных индексов
*/

int Strlen(const char* str){
    int i = 0;
    while(*(str + i) != '\0'){
        i++;
    }
    return i;
}


int main(){
    setlocale(LC_ALL, "Rus");
    const char *str = "Hello world!";
    cout<<"Count of the letter of the word is " << Strlen(str)<<endl;
   
    return 0;
}
