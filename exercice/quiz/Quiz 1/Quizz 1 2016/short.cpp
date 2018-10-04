// ==========================================================================
// $Id: short.cpp,v 1.2 2016/09/28 03:56:14 jlang Exp $
// CSI2372 Midterm A 2016
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.eecs.uottawa.ca
// 
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: short.cpp,v $
// Revision 1.2  2016/09/28 03:56:14  jlang
// Updated short questions.
//
// Revision 1.1  2016/09/26 02:16:59  jlang
// Draft Midterm A
//
// ==========================================================================
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 1. Call the following function
void arrays( int (*a)[3], int (&b)[3] ) {
  cout << "work" << "\n";
}

void passArray() {
  cout << "1." << "\n";
  int argA[3], argB[3];
  arrays( &argA, argB ); 
}

//2,  What is printed by the following function
void printArray() {
  cout << "2." << "\n";
  int array[][2]{1,2,3,4,5,6};
  cout << (*(array+1))[2] << endl;
  return;
}

//3. What is printed by the following function
void printBool() {
  cout << "3." << "\n";
  bool bv = true;
  short sv = 2;
  int iv = 1;
  cout << (iv < sv && bv) << endl;
  return;
}

// 4.What is printed by the following function
void printInteger() {
  cout << "4." << "\n";
  unsigned int ua = 4, ub = 2;
  cout << (ua ^ ub | 1) << endl;
  return;
}

void printChar() {
  cout << "5." << "\n";
  char cA[]{"Hello World"};
  *(cA+5) = 0;
  cout << cA << endl;
}

void printAuto() {
  cout << "6." << "\n";
  char abc[]{"abc"};
  for ( auto v : abc ) {
    v++;
  }
  cout << abc << endl;
  for ( auto& v : abc ) {
    v++;
  }
 abc[3] = 0;
  cout << abc << endl;
}

void arrayInt() {
  cout << "7." << "\n";
  int aA[][2]{1,2,3,4,5,6};
  int (*ptrA)[2] = aA;
  cout << (*ptrA)[1] << endl;
  ++ptrA;
  cout << (*ptrA)[1] << endl;
  return; 
}

void intDiv() {
  cout << "8." << "\n";
  int i=7,j=2;
  auto k = i/j;
  auto m = i%j;
  cout << k << " and " << m << endl;
  return;
}


union ShortLong {
  long lVal;
  short sVal;
};


void autoDecl() {
  cout << "9." << "\n";
  int i = 2;
  int& j = i; 
    //cout << j++ << "\n";

  auto k = j;
    //cout << k << "\n";

  decltype(j) m = j;
  --i;
  cout << k << endl;
  cout << m << endl;
  return;
}


enum class Color { Spades, Clubs, Hearts, Diamonds } ;
enum class Face { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King , Ace } ;

struct Card
{
   Color col;
   Face face;
};

void makeHand() {
  Card hand[]{{Color::Spades,Face::Ace},{Color::Clubs,Face::Ace},
  {Color::Hearts,Face::Ace},{Color::Diamonds,Face::Ace}};

}
 




// add example with references and auto / decltype

int main() {
  passArray();
  int array[3];
  printArray();
  printBool();
  printInteger();
  printChar();
  printAuto();
  arrayInt();
  intDiv();
  autoDecl();
  return 0;
}


