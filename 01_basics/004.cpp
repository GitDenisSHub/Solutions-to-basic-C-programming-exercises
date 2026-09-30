	#include <iostream>
	
	using namespace std;
	
	//Посчитать сумму цифр числа и проверить, что число является палиндромом (совпадает при чтении в обратную сторону).
	
	
	
	
	int main(){
	    setlocale(LC_ALL, "Rus");
	    int number, number_help, sum_of_elements = 0, count = 0;
	    number = number_help = 1001;
	    
	    //Сначала подсчитываем сколько там всего цифр
	    while(number_help != 0){
	        number_help /= 10;
	        count++;
	    }
	    //Выделяем массив для того,чтобы хранить все цифры
	    int *elements_of_number = new int[count];
	    
	    //сначала нужно разобрать число, начиная с конца, используя /10
	    for (int i = 0; i < count; i++) {
	        //Вытаскиваем число
	        elements_of_number[i] = number%10;
	        //Суммируем его в сумматор цифр
	        sum_of_elements += elements_of_number[i];
	        number /=10;
	    }
	    
	    //Выводим символы в обратном порядке
	    //Цикл проверки числа на палиндромность
	    for (int i = count-1, j = 1; i >= 0; i--, j++) {
	        //Выводим цифру в консоль
	        //cout<< "Ur " << j << " element is " << elements_of_number[i] <<endl;
	    }
	    
	    
	    bool IsPalindrome = true;
	    //Цикл проверки числа на палиндромность
	    for (int i = count -1, j = 0; i>=0; i--, j++) {
	        
	        if(i != j){
	            if(elements_of_number[j] != elements_of_number[i]){
	                cout<<"Число не является палиндромом!"<<endl;
	                IsPalindrome = false;
	                break;
	            }
	            if(elements_of_number[j] == elements_of_number[i]){
	                //cout<<"Числа совпали"<<endl;
	                IsPalindrome = true;
	                
	            }
	        }
	    }
	    if(IsPalindrome){
	        cout<<"Число является палиндромом!"<<endl;
	    }
	    
	    //Выводим сумму цифр
	    cout<<"\n\nSum of elements of this number is " << sum_of_elements<<endl;
	    
	    //Очищаем выделенную память
	    delete[]elements_of_number;
	    elements_of_number = nullptr;
	    
	    return 0;
}