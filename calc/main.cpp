#include <iostream>

using namespace std;

void calculate(){
    int a;
    int b;
    int action;
    cout<< "ввдите первое число\n";
    cin>> a; 
     cout<< "ввдите второе число\n";
    cin>> b; 
    cout<<"1=+, 2=-, 3=*, 4=/";
    cin>> action;

    if (action==1) {
        cout<<a+b;
    
    }
    else if (action==2) {
        cout<<a-b;
    
    }
    else if (action==3) {
        cout<<a*b;
    
    }
    else if (action==4) {
        if (b==0){
            cout<< "ты лох";
        }
        else
            cout<<a/b;
    
    }
    else cout<<"ты дурак";
}
int main() {
    while(true) {
        calculate();
    }
}