#include <iostream>

using namespace std ;

int addAndReturn( int& myVal )
{
     int temp = myVal;
     myVal += 1;
     return temp;
}

int main10(){

int i = 10;
cout << i << endl;
cout << addAndReturn( i ) << endl;
cout << i << endl << endl << endl;

cout << i << endl;
cout << addAndReturn( i ) << endl;
cout << i << endl << endl << endl;

cout << i << endl;
cout << addAndReturn( i ) << endl;
cout << i << endl << endl << endl;

return 0;
}


