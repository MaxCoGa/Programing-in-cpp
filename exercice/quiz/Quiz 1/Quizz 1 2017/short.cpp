// ==========================================================================
// $Id: short.cpp,v 1.2 2017/09/28 15:52:29 jlang Exp $
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
// $Log: short.cpp,v $
// Revision 1.2  2017/09/28 15:52:29  jlang
// Final version.
//
// Revision 1.1  2017/09/28 12:51:56  jlang
// First pass of midterm
//
// ==========================================================================
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool copyWord( const char* in, char* out) {
  cout << "work" << "\n";
  return true;
}

class AC {
  int d_i{23};
  int d_j;
public:
  AC( int k=15 ) : d_i{k}, d_j{k} {}  
  void print() {
    cout << d_i << " " << d_j << endl;
  }
};


int main() {
  // Call the function with the given arguments
  cout << "1." << "\n";

  char word[]{"Hello"};
  char* result = new char[128]{};
  bool cp;
  cp = copyWord( word, result );
  delete result;

  // What is printed by the following?
  cout << "2." << "\n";
  std::string s;
  s+="1 ";
  s+='2';
  s[1] = '0';
  cout << s.c_str() << endl;

  // What is printed by the following? 
  cout << "3." << "\n";
  double dd = 3.0;
  int ii = 2;
  char cc = 1;
  double rr = dd/ii+cc;
  cout << rr << endl;

  // What is printed by the following?
  //AC ac{10};
  //ac.print();

  // What is printed by the following?
  cout << "5." << "\n";
  int ras = 8;
  int rbs = 2;
  int rcs = 3;
  int rcd = ras >> --rcs << rbs/2;
  cout << rcd << endl;

  // What is printed by the following program?
  cout << "6." << "\n";
  int aa[]{2,4,6};
  int *pA = &aa[0];
  int **pB = &pA;
  ++pA;
  cout << **pB << endl;

  // Use auto in the following variable definition to define exactly
  // the same types
  //cout << "7." << "\n";
  int x = 0;
  cout << "7." << "\n";
  // int &i = x; 
  
	auto& i = x; ++x; cout << i << endl;
  cout << "8." << "\n";
  //x=1;
  // const int *j = &x;
  const auto j = &x; ++x; cout << *j << endl;
  // j++;
  
	return 0;
}
    
  


