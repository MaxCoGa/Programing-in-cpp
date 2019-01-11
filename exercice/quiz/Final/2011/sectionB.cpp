// ==========================================================================
// $Id: sectionB.cpp,v 1.1 2014/12/03 00:13:32 jlang Exp $
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
// $Log: sectionB.cpp,v $
// Revision 1.1  2014/12/03 00:13:32  jlang
// Created sample solution
//
// ==========================================================================
#include <iostream>


using std::cout;
using std::endl;
using std::ostream;



/**
 * Question 1
 */
class A {
  int* d_a;
  int d_sz;
 public:
  A(int sz=0) : d_sz(sz) {
    d_a = new int[d_sz];
  }
  // other stuff
  A& operator=( const A& o ) {
    if ( this != &o ) {
      d_sz = o.d_sz;
      delete d_a;
      d_a = new int[d_sz];
      for ( int i=0; i<d_sz; ++i ) d_a[i] = o.d_a[i];
    }
    return *this;
  }
};


void question1() {
  A a1(3), a2;
  a2=a1;
  a1=a1;
  return;
}



/**
 * Question 2
 */
class Integer {
  int i;
public: 
  // other stuff
  Integer operator++(int) {
    Integer tmp(*this); ++i; return tmp;
  }
};

void question2() {
  Integer myInt;
  myInt++;
  return;
}



/**
 * Question 3
 */
template <class T, const int SZ>
class B {
  static const int sz=SZ;
  T array[SZ];
};

void question3() {
  B<double,3> a;
  return;
};



/**
 * Question 4
 */
class Couple;
ostream& operator<<(ostream&, const Couple& );

class Couple {
  int a,b;
public:
  Couple(int a, int b) : a(a), b(b) {}
   // …
  friend ostream& operator<<(ostream&, const Couple& );
};

ostream& operator<<(ostream& os, const Couple& c) {
  os << '(' << c.a << ',' << c.b << ')'; return os;
}

void question4() {
  Couple  c(3,2);
  // Desired output:  c=(3,2)
  std::cout << "c=" << c << endl; 
  return;
}



int main() {
  question1();
  question2();
  question3();
  question4();
  // question5();
  return 0;
}
