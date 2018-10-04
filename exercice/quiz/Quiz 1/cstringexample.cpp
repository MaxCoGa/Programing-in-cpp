//C-string example
#include <iostream>
#include <string>
using namespace std;
int main(){
    char t[] = "hello";
    char *c =t;//pointeur vers t
    while(*c){
        cout << *c << endl;
        c++;
    }
    cout << static_cast<int>(*c)<<endl;

    string s1 = "Allo";
    for (char c2:s1){
        cout << c2 <<endl;
    }

    //getCharacters(t[]) t[0]=126 => "1" "2" "6" 0

    
}