#include <iostream>
#include <string>
using namespace std;
//use for 5
void func(int& i){
    cout << "f1"<<endl;
};
int func(const float* f){ //plutot promesse quon modifie pas le pointeur f
    cout << "f2"<<endl;
};
float func(double* d){
    cout << "f3"<<endl;
};


//part 2
unsigned int changeByteOrder( unsigned int val32 ) {
 return  (((val32 & 0xFF) << 24) | ((val32 & 0xFF00) << 8) |
 ((val32 & 0xFF0000) >> 8) | ((val32 & 0xFF000000) >> 24));
} 

void makeUpper( const unsigned char* input, unsigned char* output ) {
 while ( *input != 0 ) {
 *output = (*input>=97 && *input<=122)?*input-32:*input;
 ++output; ++input;
 }
 *output = *input;
 return;
} 


int main(){
    //1.
    cout << "1." << "\n";
    unsigned int a=0xFF, b=0x0F0F;
    a ^= b;//xor
    cout << a<< endl;//dec

    //2 not in quiz 1

//3 
cout << "3." << "\n";
union Combi {
 int i;
 short s;//two bytes only
};

Combi c;
c.i = 0xFF0001;
std::cout << c.s <<endl;//


//4
cout << "4." << "\n";
int A[][2] = {10,20,30,40};//array de array, mais 4 int so 2x2
int (*ptr)[2] = &A[0];//pointeur a un tab de taille 2    // A est un pointeur d'elem 2 qui pointe sur 10,20
int a_ = **(++ptr);//incremente ptr vers le deuxieme tableau   *ptr= adrs du deuxieme tab  **ptr= premier elem du deuxieme tab

cout << a_ <<endl;


//5 see 
cout << "5." << "\n";
float f=5.0f;
float g = func(&f);


//struct meme chose que class sauf variable public


//part 2¸
unsigned int p2(0xA50F8421);
changeByteOrder(p2);


}
