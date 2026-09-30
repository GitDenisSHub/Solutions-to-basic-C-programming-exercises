#include <iostream>
#include <string>

using namespace std;

//Написать функцию, которая проверяет сбалансированность скобок в строке ( ( [ { и т.д. — это уже
//требует структуры данных типа стек, если её не было, используй просто array/vector вручную).

bool Check_str(string str){
    //Должен быть массив, хранящий строки
    //Половина открывающие - вторая половина закрывающие, сравнение по одному
    int first = 0, second = 0;
    int i = 0;
   
    //Сначала мы пересчитаем все элементы, все скобки
    while(i < str.length()){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            first++;
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            second++;
        }
        i++;
    }
    //Создадим переменные под открывающие и под закрывающие скобки
    char *arr_сhar = new char[first];
    char *arr_char2 = new char[second];
    //Тут должна быть проверка то, больше ли открывающих, чем закрывающих
    //Если уже больше, то на это точно уже можно ловить
    bool is_more = false;
    
    int j = 0,k = 0;
    i = 0;
    
    
    while(i < str.length()){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            arr_сhar[k] = str[i];
            i++;
            k++;
            
            continue;
        }
        
        
        if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            arr_char2[j] = str[i];
            j++;
            i++;
            
            if(j > k){
                is_more = true;
            }
                
            continue;
        }
        i++;
    }
    
    
    //Выведем то, что получилось
    for (int i = 0; i < first; i++) {
        cout<<arr_сhar[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < second; i++) {
        cout<<arr_char2[i]<<" ";
    }
    cout<<endl;
    
    cout<<"Size first - " << first << endl << "Size second - " << second << endl;
    
    //Далее у нас идет прямое сравнение скобок между собой
    i = 0;
    j = second - 1;
    if(first != second || is_more == true){
        cout<<"Very bad!"<<endl;
        delete[] arr_сhar;
        delete[] arr_char2;
        return false;
    }
    else{
        while(first != 0 || second != 0){
            
            if(arr_сhar[i] == '(' && arr_char2[j] == ')'){
                i++;
                j--;
                first--;
                second--;
                continue;
            }
            else if(arr_сhar[i] == '[' && arr_char2[j] == ']'){
                i++;
                j--;
                first--;
                second--;
                continue;
            }
            else if(arr_сhar[i] == '{' && arr_char2[j] == '}'){
                i++;
                j--;
                first--;
                second--;
                continue;
            }
            //Если хотя бы одно не совпадение - то все, кранты
            cout<<"Very bad!"<<endl;
            delete[] arr_сhar;
            delete[] arr_char2;
            return false;
        
        }
        
    }
    cout<<"Good!"<<endl;
    delete[] arr_сhar;
    delete[] arr_char2;
    return true;
}


int main(){
    setlocale(LC_ALL, "Rus");
    
    string str = "(([{[]}]))";
    string str2 = "(([{[]}]])";
    string wrong_str2 = "([)]";
    string wrong_str = "())((()) ";
    
    Check_str(wrong_str2);
    
    return 0;
}