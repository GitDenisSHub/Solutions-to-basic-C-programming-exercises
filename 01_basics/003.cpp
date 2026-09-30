#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    int count = 1, size;
    cout<<"Input ur count - "; cin>>size;
    
    
    while(size != 0){
        
        for (int i = 0; i < count; i++) {
            cout<<"*";
        }
        cout<<endl;
        
        size--;
        count++;
    }
    
   
    
    return 0;
}