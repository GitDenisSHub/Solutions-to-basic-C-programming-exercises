#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

/*
 Проверка палиндрома
 Проверить, читается ли строка одинаково слева направо и справа налево.
 Тренирует: рекурсию, индексы, строки.
 Зачем: задача на сравнение крайних элементов и постепенное сужение диапазона.
 */


bool Palindrome(char* str,int first, int last){
    
    if(first < last){
        if(str[first] != str[last]){
            cout<<"One "<< str[first]<<endl;
            return false;
        }
        else{
            cout<<"Two "<< str[first]<<endl;
            return Palindrome(str,++first, --last);
        }
    }
    else{
        cout<<"Three "<< str[first]<<endl;
        return true;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    char str[] = "qwertrewq";
    char str2[] = "qwerttrewq";
    char str3[] = "wejfnwkegj";
    
    cout<< Palindrome(str, 0, (int)strlen(str) - 1) << endl;
   
    return 0;
}
