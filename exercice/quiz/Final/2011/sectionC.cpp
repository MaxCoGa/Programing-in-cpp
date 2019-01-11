// ==========================================================================
// $Id: sectionC.cpp,v 1.1 2014/12/03 00:13:33 jlang Exp $
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
// $Log: sectionC.cpp,v $
// Revision 1.1  2014/12/03 00:13:33  jlang
// Created sample solution
//
// ==========================================================================
#include <iostream>
#include <list>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

template <typename T, int N=3>
class BookShelf {

  std::list<T> shelves[N];

public:

  T operator()(int shelfNumber, int elementNumber) const;
  BookShelf<T,N> operator+=(const T& element);
  BookShelf<T,N> operator--();
  int getNumberOfShelves() const {return N;}
  bool find(const T &element) const;

  friend ostream& operator<<( ostream& os, const BookShelf& bs ) {
    for ( int i=0; i<N; ++i ) {
      for ( auto l : bs.shelves[i] ) cout << l << " ";
      cout << endl;
    }
    return os;
  }
};

class Livre {
  char name = rand() % 26 + 'a';

public:
  bool operator==( const Livre& ol ) const {
    return name == ol.name;
  }

  friend ostream& operator<<( ostream& os, const Livre& l ) {
    os << l.name; 
    return os;
  }
};


template <typename T, int N>
T BookShelf<T,N>::operator()(int shelfNumber, int elementNumber) const {
  if ( shelfNumber >= N ) throw string("Illegal Shelf Number");
  if ( shelves[shelfNumber].size() <= elementNumber ) 
    throw string("Illegal Element Number");
  int cnt = 0;
  for ( auto iter = shelves[shelfNumber].cbegin();
	iter != shelves[shelfNumber].cend(); ++iter ) {
    if (cnt == elementNumber) return *iter;
  }    
}


template <typename T, int N>
BookShelf<T,N> BookShelf<T,N>::operator+=(const T& element) {
  size_t small = shelves[0].size();
  int smallIndex = 0;
  for ( int i=1; i<N; ++i ) {
    if ( shelves[i].size() < small ) {
      small = shelves[i].size();
      smallIndex = i;
    }
  }
  shelves[smallIndex].push_back( element );
  return *this;
}


template <typename T, int N>
BookShelf<T,N> BookShelf<T,N>::operator--() {
  size_t big = shelves[0].size();
  int bigIndex = 0;
  for ( int i=1; i<N; ++i ) {
    if ( shelves[i].size() > big ) {
      big = shelves[i].size();
      bigIndex = i;
    }
  }
  shelves[bigIndex].pop_back();
  return *this;
}


template <typename T, int N>
bool BookShelf<T,N>::find(const T &element) const {
  for ( int i=1; i<N; ++i ) {
    if ( std::find( shelves[i].cbegin(), shelves[i].cend(), element )
	 != shelves[i].cend()) {
      return true;
    }
  }
  return false;
}



int main() {
  BookShelf<Livre,5> bookcase;
  for ( int i=0; i<100; ++i ) bookcase += Livre();
  cout << bookcase;
  cout << bookcase(2,5) << endl;
  Livre book;
  if ( bookcase.find( book )) cout << book <<" found" << endl;
  else cout << book << "not found" << endl;
  for ( int i=0; i<100; ++i ) --bookcase;
  cout << bookcase;
}
