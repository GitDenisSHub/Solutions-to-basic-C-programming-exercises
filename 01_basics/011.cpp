#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//Посчитать количество вхождений каждого символа в строке (можно использовать map, если уже проходили
//ТО есть нужно определить сколько раз в строке встречается кадый символ!

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time_t(NULL));
    
    //Само сообщение
    string msg;
    cout<<"Input ur line: ";
    getline(cin, msg);

    //Сколько максимум различных букв может быть
    int letter_count[msg.length()];
    char letter[msg.length()];
    
    

    for (int i = 0; i < msg.length(); i++) {
        //Нужна инициализация нулем
        letter_count[i] = 0;
        letter[i] = msg[i];
        
        
        if(msg[i] == '-') continue;
        
        for (int j = 0; j < msg.length(); j++) {
            if(msg[i] == msg[j]){
                letter_count[i]++;
                if(i != j){
                    msg[j] = '-';
                }
            }
        }
        msg[i] = '-';
        cout<<"The symol is " << letter[i] << " Count of this letter is " << letter_count[i] << endl << endl;;
        
    }
    cout<<"Ur line after the job is "<<msg<<endl;
    //ttrrhhooooff
    
    return 0;
}