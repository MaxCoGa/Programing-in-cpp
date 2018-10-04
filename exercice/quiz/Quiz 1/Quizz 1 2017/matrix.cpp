// ==========================================================================
// $Id: matrix.cpp,v 1.1 2017/09/28 12:51:55 jlang Exp $
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
// $Log: matrix.cpp,v $
// Revision 1.1  2017/09/28 12:51:55  jlang
// First pass of midterm
//
// ==========================================================================
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


// What is printed by the program if the user enters 2 and 3?
// Improve the following code by using std::vector instead of a low-level array.
// In particular define a function
// std::vector<int> matrixV( int nRows, int nCols ) and call it properly from main.
// Can you use std::array instead of std::vector? Explain why in one sentence.



int* matrix( int nRows, int nCols ) {
  int *numbers = new int[nRows*nCols];
  int *element = numbers;
  for(int r=0; r<nRows; ++r) {
      for(int c=0; c<nCols; ++c) {
	            *(element++) = (r*nCols)+c;
      }
  }
  return numbers;
}




void deleteMatrix( int *numbers ) {
  delete[] numbers;
  return;
}

/*void deleteMatrix( int *numbers ) {
  delete[] numbers;
  return;
}*/


int main() {
  int nRows, nCols;
  cout << "Number of rows: ";
  cin >> nRows;
  cout << endl;
  cout << "Number of cols: ";
  cin >> nCols;
  cout << endl;
  auto numbers = matrix(nRows,nCols);
  for(int r=0; r<nRows; ++r) {
      for(int c=0; c<nCols; ++c) {
              cout << numbers[r*nCols+c] << " ";
      }
      cout << endl;
  }
  deleteMatrix( numbers );

  return 0;
}
