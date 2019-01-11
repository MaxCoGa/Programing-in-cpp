// ==========================================================================
// $Id: sectionA.cpp,v 1.1 2014/12/03 00:13:32 jlang Exp $
// CSI2372 Example Sol. Final Fall 2011
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
// Creator: Jochen Lang
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: sectionA.cpp,v $
// Revision 1.1  2014/12/03 00:13:32  jlang
// Created sample solution
//
// ==========================================================================
#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::ostream;


/**
 * Question 1
 */
void question1() {
  std::vector<string> svec;
  svec.push_back("world"); 
  svec.push_back(" ");
  svec.push_back("hello"); 
  for ( std::vector<string>::reverse_iterator riter = svec.rbegin();
	riter != svec.rend(); ++riter ) {
    cout << *riter;
  }
  cout << endl;
  return;
}


/**
 * Question 2
 */
bool isZero( int i ) {
  if ( i==0 ) return true;
  return false;
}
// Give typedef
typedef bool (*zeroComp) ( int ); 

void question2() {
  zeroComp ptrIsZero = isZero;
  ptrIsZero(1);
  return;
}


/**
 * Question 3
 */
bool isOne( int i ) {
  if ( i==1 ) return true;
  return false;
}

void question3() {
  std::vector<int> ivec( 10, 1 );
  std::replace_if(ivec.begin(), ivec.end(), isOne, 0);
  for ( auto e : ivec ) cout << e << " ";
  cout << endl;
}


/**
 * Question 4
 */
void question4() {
  class A { virtual ~A() {}; }; class B { virtual ~B() {};};
  A *objA = new A();
  try {
    B* objB= dynamic_cast<B *>(objA);
    cout << "Should have checked: " << reinterpret_cast<size_t>(objB) << endl;
  } catch ( std::bad_cast& except ) {
    cout << "Cast failed!" << endl; 
  }
  return;
}


/**
 * Question 5
 */
void question5() {
  int tab[5]= {1,4,2,7,8}; 
  std::vector<int> v(5);
  std::copy(tab,tab+5,v.begin());
  for ( auto e : v ) cout << e << " ";
  cout << endl;
  return;
}


/**
 * Question 6
 */
// Replace auto_ptr with unique_ptr for C++11
void question6() {
  std::auto_ptr<int> pi(new int(4));
  std::auto_ptr<int> pj = pi;
  cout << pi.get() << endl;
  return;
}



/**
 * Question 7
 */
int fct(int x) {
  if ( x < 0 ) throw 'N';
  x+= 2;
  return 3*x;
}

void question7() {
  try {
    fct(-1);
  } catch ( const char& c ) {
    std::cout <<"caught: " << c << endl;
  }
  return;
}


/**
 * Question 8
 */
class Point {
  int d_x, d_y;
public:
  Point ( int _x, int _y ) : d_x(_x), d_y(_y) {}
  operator int() const { return d_x*d_x+d_y*d_y; }
};

void question8() {
  Point p(1,2);
  cout << "Point to int " << static_cast<int>(p) << endl;
  return;
}


/**
 * Question 9
 */
void question9() {
  int *tmp = new int[3*5];
  int **tab = new int*[3];
  for (int i=0;i<3;++i) {
    tab[i] = &tmp[i*5];
  }
  delete[] *tab;
  delete[] tab;
  return;
}


/**
 * Question 10
 */
int& func(int& a) // Only change this line
{
   a++;  
   return a;
}

void question10() {
  int i=1,j;
  j = func(i);
  return;
}


/**
 * Question 11
 */
// In C++11 you could simply say auto
void question11() {
  std::map<int,float> m;
  std::pair<std::map<int,float>::iterator,bool> ret = 
    m.insert(std::make_pair<int,float>(3,4.5));
  return;
}

int main() {
  question1();
  question2();
  question3();
  question4();
  question5();
  question6();
  question7();
  question8();
  question9();
  question10();
  question11();
  return 0;
}
