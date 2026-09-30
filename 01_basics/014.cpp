#include <iostream>
#include <string>

using namespace std;

//Написать рекурсивную функцию для вычисления факториала и для чисел Фибоначчи.
//ТО есть нужны две рекурсивные функции: для вычисления чисел фиббоначи и для факториала по отдельности

int Fibbonachi(int num){
    
    if(num <0){
        return 0;
    }
    if(num == 1){
        return 1;
    }
    
    return Fibbonachi(num-1) + Fibbonachi(num-2);
}

// 0 1 1 2 3 5 8

int Factorial(int num){
    int N = num;
    
    if(num == 1){
        return 1;
    }
    
    return N * Factorial(N - 1);
}

int main(){
    setlocale(LC_ALL, "Rus");
    
    int choose;
    cout<<R"(
            Which function u need?
            1. Fibbonachi
            2. Factorial
    
            Input:)";
    cin >> choose;
    
    if(choose == 1){
        int count;
        cout<<"How many fibo-values do you want?: ";
        cin>>count;
        
        cout << "\Fibbonachi " << count << " is " << Fibbonachi(count) << endl;
    }
    else if (choose == 2){
        int num;
        cout<<"Which num factorial do you need?: ";
        cin>>num;
        
        cout << "\nFactorial " << num << " is " << Factorial(num) << endl;
    }
    
    else{
        cout<<"\nAre you an idiot?\n"<<endl;
    }

    return 0;
}