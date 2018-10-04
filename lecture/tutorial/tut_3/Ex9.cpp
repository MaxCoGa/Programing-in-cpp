#include <iostream>

using namespace std ;

int main11(){

char name[] = "emreknlk";

cout << name[3] << endl; //first line
cout << 3[name] << endl; //second line

cout << *(name+3) << endl; //third line
cout << *(3+name) << endl; //last line:)

return 0;
}

