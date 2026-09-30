#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//Написать свою функцию, которая разбивает строку на слова по пробелу (аналог split).

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    string str = "Hello my friends and war";
    string word[str.length()];
    
    
    int position = 0, count_of_word = 0;

    do{
        if(str[position] == ' ' || str[position] == '\0'){
            count_of_word++;
        }
        word[count_of_word] += str[position];
        position++;
    }while(str[position]);
    
    for (int i = 0; i <= count_of_word; i++) {
        cout<<"Word #" << i+1 << " " << word[i] << endl;
    }
    
    return 0;
}