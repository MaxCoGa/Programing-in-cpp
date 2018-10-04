// ==========================================================================
// $Id: double_vector.cpp,v 1.1 2017/09/28 15:52:29 jlang Exp $
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
// $Log: double_vector.cpp,v $
// Revision 1.1  2017/09/28 15:52:29  jlang
// Final version.
//
// ==========================================================================
#include <iostream>
#include <cmath>

using namespace std;

double length( double vec[], size_t dim ) {
  double res;
  for ( int i=0; i<dim; ++i ) {
    res += *vec * *vec;
    ++vec;
  }
  return std::sqrt( res );
}

void print( double vec[], size_t dim ) {
  for ( int i=0; i<dim; ++i ) {
		cout << *vec++ << " ";
  }
  cout << endl;
  return ;
}

double* append( double vecA[], size_t dimA, double vecB[], size_t dimB ) {
	double* res = new double[dimA+dimB];
	double* e = res;
	for ( int i=0; i<dimA; ++i ) { 	 
		*e++ = vecA[i];
	}
	for ( int i=0; i<dimB; ++i ) { 	 
		*e++ = vecB[i];
	}
  return res;
}

int main() {
  double a[]{ 2.0, -3.0, 2.0 };
  double b[]{ -1.0, -1.0, 2.0, 1.0 };
  print( a, end(a)-begin(a) );
  print( b, end(b)-begin(b) );
	cout << length(a,end(a)-begin(a)) << endl;
	cout << length(b,end(a)-begin(a)) << endl;
	auto c = append( a, end(a)-begin(a), b, end(b)-begin(b));
	print( c, static_cast<size_t>(end(a)-begin(a)) + 
		static_cast<size_t>(end(b)-begin(b)));
  return 0;
}
    
  


