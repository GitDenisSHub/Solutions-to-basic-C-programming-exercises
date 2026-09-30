#include <iostream>
using namespace std;


// НОД двух чисел не меняется, если заменить большее число на остаток от деления большего на меньшее.

//функция по поиску НОД по методу Евклида
int NOD_Evklid(int one, int two){

    //Переменная, перевод - остаток
    int remainder;
    int max, min;


    //сначала нужно определить какое число больше, а какое меньше
    //Далее их нужно будет менять местами
    if(one >= two){
        max = one;
        min = two;
    }
    else {
        max = two;
        min = one;
    }

    //Далее, мы определчем остаток и делаем метод Евклида, доходим до 0 и второе число будет нашим ответом
    while(remainder != 0){
        remainder = max % min;
        max = min;
        min = remainder;
    }

    //cout<<"НОД по методу Евклида равен = " << max << endl;;
    //cout<<"Во втором значени лежит нуль = " << min << endl;

    return max;

}

//Поиск НОК, исходя из формулы, которую давали выше(просто вывел из нее НОК)
int NOK(int nod, int one, int two){
    int nok = (one * two)/nod;
    return nok;
}


//Попробовать написать программу, которая использует ту формулу
int main(){
    setlocale(LC_ALL, "Rus");
    
    int a = 12345, b = 67890;
    cout<< "\nНОД по алгоритму евклида равен = " << NOD_Evklid(a,b) << endl;
    
    cout<<"\nНОК по той формуле равна " << NOK(NOD_Evklid(a,b), a, b) << endl;
    
    return 0;
}