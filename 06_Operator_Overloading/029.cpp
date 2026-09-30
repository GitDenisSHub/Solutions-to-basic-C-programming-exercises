#include <iostream>
#include <ctime>
using namespace std;

/*
 29. Fraction
 Класс математической дроби:
 numerator - числитель
 denominator - знаменатель
 Перегрузить:
 +
 -
 *
 /
 ==
 !=
 Тренирует: ООП + операторы + математическую логику.
 */

class Fraction{
    int numerator;
    int denominator;
    
public:
    Fraction()
    : numerator(0), denominator(1){cout<<"Вызов конструктора по умолчанию!"<<endl;}
    
    Fraction(int numerator, int denominator)
    : numerator(numerator), denominator(denominator){cout<<"Вызов конструктора!"<<endl;}
    
    void GetInfo(){
        cout<<"Number is " << numerator << " / " << denominator << endl;
    }
    
    bool operator==(const Fraction& another){
        cout<<"Вызов оператора сравнения!"<<endl;
        //Перекрестное умножение
        return this->numerator*another.denominator == this->denominator*another.numerator;
        //return (double)this->numerator/this->denominator == (double)another.numerator/another.denominator;
    }
    
    bool operator!=(const Fraction& another){
        
        //Перекрестное умножение
        return !(this->numerator*another.denominator == this->denominator*another.numerator);
        //return !((double)this->numerator/this->denominator == (double)another.numerator/another.denominator);
    }
    
    Fraction operator+(const Fraction& another){
        cout<<"Вызов оператора сложения!"<<endl;
        int num = 0, denom = 0;
        
        if(this->denominator != 0 && another.denominator != 0){
            if(this->denominator != another.denominator){
                denom = this->denominator * another.denominator;
                num = (this->numerator * (denom/this->denominator)) + (another.numerator * (denom/another.denominator));
            }
            else{
                denom = this->denominator;
                num = this->numerator + another.numerator;
            }
            
            return Fraction(num , denom);
        }
        else{
            cout<<"Ошибка! Один из знаменателей равен нулю!"<<endl;
            return Fraction(0 , 1);
        }
    }
    
    Fraction operator-(const Fraction& another){
        cout<<"Вызов оператора вычитания!"<<endl;
        int num = 0, denom = 0;
        
        if(this->denominator != 0 && another.denominator != 0){
            if(this->denominator != another.denominator){
                denom = this->denominator * another.denominator;
                num = (this->numerator * (denom/this->denominator)) - (another.numerator * (denom/another.denominator));
            }
            else{
                denom = this->denominator;
                num = this->numerator - another.numerator;
            }
            
            return Fraction(num , denom);
        }
        else{
            cout<<"Ошибка! Один из знаменателей равен нулю!"<<endl;
            return Fraction(0 , 1);
        }
    }
    
    Fraction operator*(const Fraction& another){
        cout<<"Вызов оператора умножения!"<<endl;
        int num = 0, denom = 0;
        
        if(this->denominator != 0 && another.denominator != 0){
            
            num = this->numerator * another.numerator;
            denom = this->denominator * another.denominator;
            
            return Fraction(num , denom);
        }
        else{
            cout<<"Ошибка! Один из знаменателей равен нулю!"<<endl;
            return Fraction(0 , 1);
        }
    }
    
    Fraction operator/(const Fraction& another){
        cout<<"Вызов оператора деления!"<<endl;
        int num = 0, denom = 0;
        
        if(this->denominator != 0 && another.denominator != 0){
            
            num = this->numerator * another.denominator;
            denom = this->denominator * another.numerator;
            
            
            return Fraction(num , denom);
        }
        else{
            cout<<"Ошибка! Один из знаменателей равен нулю!"<<endl;
            return Fraction(0 , 1);
        }
    }
};
    

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
   
    Fraction num(4, 6);
    num.GetInfo();
    Fraction num2(5, 8);
    num2.GetInfo();
    
    Fraction c;
    c.GetInfo();
    c = num / num2;
    c.GetInfo();
    
    return 0;
}
