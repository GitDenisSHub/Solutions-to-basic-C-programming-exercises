#include <iostream>

using namespace std;

//Функция проверяет есть ли у числа дробная часть(чтобы понять делится ли она с остатком или нет)
bool CheckNum(const double &input_num){
    double help_num;
    int int_num;
    
    int_num = input_num;
    help_num = input_num - int_num;

// 0.00000 - потому что целое содержит не совсем нуль, поэтому его нужно сравнить с таким нулем, которое точно определяет int как int, а не как float(это может быть случайно)
    if(help_num > 0.0000000){
        return 1;
    }
    else return 0;    
}


int main(){
    setlocale(LC_ALL, "Rus");

    int num, count = 0;
    double after_the_point;
    bool answer;

    cout<<"Введите ваше число: "; cin >> num;
    cout<<"Ваше число - " << num << endl;;

//Проверяем, есть ли дробная часть - чтобы посчитать сколько делителей у числа
    for (int i = 1; i < num + 1; i++)
    {
        after_the_point = (double)num / i;
        if(CheckNum(after_the_point)){
            answer = false;      
        }
//Тут мы подсчитываем сколько таких делителей у числа
        else{
            count++;
            answer = true;
        }
//Простое число - число, которое делится на 1 и на само себя(значит, если по итогу  у числа больше этих двух делителей еще в процессе работы программы) - то смысла проверять дальше нет
        if(count>2){
            cout<<"Ваше число не простое!"<<endl;
            break;
        }
    }
//Окончательная проверка - если у числа в итоге 2 делителя - то число точно простое
    if(count == 2){
        cout<<"Ваше число простое!"<<endl;
    }  
    return 0;
}