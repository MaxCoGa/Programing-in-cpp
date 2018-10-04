#include <iostream>
#include <string>
using namespace std;

    int fct1(int x){
        x=x+3;
        return x;
    }
    int fct2(int *x){
        *x=*x+7;
        return *x;
    }
    int fct3(int &x){
        x=x+6;
        return x+1;
    }


int main(){
    

    int a(8);
    int b;

    b = fct1(a);
    cout << "fct1: " << "b:"<<b<<" a:"<<a << endl; 

    b = fct2(&a);
    cout << "fct2: " <<"b:"<<b<<" a:"<<a << endl; 

    b = fct3(a);
    cout << "fct3: " <<"b:"<<b<<" a:"<<a << endl; 


}