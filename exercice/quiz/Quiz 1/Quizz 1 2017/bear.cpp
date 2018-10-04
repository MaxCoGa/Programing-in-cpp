// ==========================================================================
// $Id: bear.cpp,v 1.1 2017/09/28 12:51:54 jlang Exp $
// CSI2372 Solution code for midterm A
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
// $Log: bear.cpp,v $
// Revision 1.1  2017/09/28 12:51:54  jlang
// First pass of midterm
//
// ==========================================================================
#include <iostream>


using std::cout;
using std::endl;


class Bear {
  int d_age;
public:
  Bear( int age ) : d_age(age) {}
  void print() {
    cout << d_age;
  }
};

class Cave {
  double d_depth{3.0};
  Bear d_b;
public:
  Cave( Bear b ) : d_b{b} { d_b.d_age = 0; }
  bool hasOldBear() {
    if (d_b.d_age>10) return true;
    else return false;
  }
  Bear getBear() { return d_b };
};



int main() {
  Cave c;
  Bear b;  
  if ( c.hasOldBear() ) {
    b = c.getBear();
    cout << "Old Bear!";
    b.print();
    cout << endl;
  } else {
    cout << "Young Bear!" << endl;
  }
  return 0;
}
