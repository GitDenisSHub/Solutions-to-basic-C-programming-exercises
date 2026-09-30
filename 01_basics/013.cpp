#include <iostream>
#include <string>

using namespace std;

//Реализовать шифр Цезаря (сдвиг букв по алфавиту).
//При этом есть важный момент: когда мы доходим до конца алфавита, нужно вернуться в его начало


//Большие буквы в Аски с 65-90
//Маленькие буквы с 97-122

int main(){
    setlocale(LC_ALL, "Rus");
    
    //Нужно запрашивать саму строчку + величину сдвига(N позиций для смена)
    string msg = "Hello world!";
    
    //В англ алфавите 26 букв
    int N = 50;
    int help_N = N;
    
    
    //Запрос на ввод текста (опционально)
    //cout<<"Input ur massage: "; cin >> msg;
    //cout<<"Input values of change: "; cin>>N;
    
    cout<<"Ur string is \""<<msg<<"\""<<endl;
    
    //Тут будет цикл смены символов
    int position = 0, remainder = 0;
    
    //Заранее проверяем N
    
    
    
    while(msg[position] != '\0'){
        
        //Сначала с большими буквами
        if(msg[position] >= 65 && msg[position] <= 90){
            
            while(help_N != 0){
                //Делаем по ним смещение
                msg[position] += 1;
                
                //Если вышли за рамки больших букв
                if(msg[position] > 90){
                    //Считаем на сколько позиций вышли
                    remainder = msg[position] - 90;
                    //Начинаем с начала и прибавляем разницу
                    msg[position] = 65 + remainder - 1;
                }
                help_N--;
            }
            
            
        }
        
        
        //Потом с маленькими буквами
        if(msg[position] >= 97 && msg[position] <= 122){
            while(help_N != 0){
                //Делаем по ним смещение
                msg[position] += 1;
                //Если вышли за рамки больших букв
                if(msg[position] > 122){
                    //Считаем на сколько позиций вышли
                    remainder = msg[position] - 122;
                    //Начинаем с начала и прибавляем разницу
                    msg[position] = 97 + remainder - 1;
                }
                
                help_N--;
            }
        }
        
        help_N = N;
        position++;
    }
    
    cout<<"Ur string after the change is \""<<msg<<"\""<<endl;

    return 0;
}