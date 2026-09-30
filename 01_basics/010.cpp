Для работы с массивами символов

#include <iostream>
#include <ctime>

using namespace std;

//Проверить, является ли строка палиндромом (игнорируя пробелы и регистр).
//Нужно сделать как через массив символов, так и через строки

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    //Различные варианты строк
    char *str1 = "HeloleH";
    char* str1_1  = "HelleH";
    char* str1_2  = "Hel         le H";
    char *str2 = "HellLeH";
    char* str = str2;
    char help;
    
    
    bool is_palindrome = true;
    int i = 0;
    int j = strlen(str) - 1;
    
    while(i <= j){
        if(str[i] == ' '){
            i++;
            continue;
        }
        if(str[j] == ' '){
            j--;
            continue;
        }
        
        if(str[i] != str[j]){
            if(str[i] > str[j]){
                help = str[j] + 32;
                
                if(str[i] != help){
                    is_palindrome = false;
                    cout<<"It isn't pallindrome!"<<endl;
                    break;
                }
            }
            else{
                help = str[i] + 32;
                if(str[j] != help){
                    is_palindrome = false;
                    cout<<"It isn't pallindrome!"<<endl;
                    break;
                }
            }
        }
        
        i++;
        j--;
    }

    
    if(is_palindrome == true){
        cout<<"Good! It's Pallindrome!"<<endl;
    }
    
    
    return 0;
}