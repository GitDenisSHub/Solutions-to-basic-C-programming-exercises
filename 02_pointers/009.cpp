#include <iostream>

using namespace std;

/*
 9. Своя функция копирования строки
Реализовать аналог простого копирования C-строки без strcpy.
Тренирует: указатели, char*, '\0'.
Зачем: классическая задача на работу с памятью.
*/

void StrCpy(const char* one, char* two){

    int i = 0;
    while(*(one + i) != '\0'){
        two[i] = *(one + i);
        i++;
    }
    two[i] = '\0';
}

int main(){
    setlocale(LC_ALL, "Rus");
    const char *str = "Hello world!";
    char str2[100];
    
    StrCpy(str, str2);

    cout<<str2<<endl;
   
    return 0;
}
