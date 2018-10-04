// ==========================================================================
// $Id: programs.cpp,v 1.1 2016/09/28 03:42:31 jlang Exp $
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
// $Log: programs.cpp,v $
// Revision 1.1  2016/09/28 03:42:31  jlang
// Midterm revision based on comments by Z. Sebbani
//
// ==========================================================================
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

union ShortLong {
  long lVal;
  short sVal;
};

// Mark the illegal access to union variables and 
// indicate which variable was not supposed to be accessed
void unionError() {
  ShortLong SL;
  SL.lVal = 1024L;
  cout << SL.sVal << endl;
  SL.lVal *= SL.sVal;
  SL.sVal = static_cast<short>(1024);
  SL.sVal = ++SL.lVal; 
  return;   
}

enum class Colors {
  White, Black
};

// Complete the function such that it prints 
// the color, e.g., "Black on Black"
// 
void printEnum( Colors foreground ) {
  switch (foreground) {
    case Colors::White:
      cout << "White";
      break;
    case Colors::Black:
      cout << "Black";
      break;
  }
  cout << " on Black" << endl;
  return;
}

void enumScoped() {
  Colors foreground = Colors::White;
  printEnum( foreground );
  return;
}
  
  
enum class Color { Spades, Clubs, Hearts, Diamonds } ;
enum class Face { Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

struct Card {
  Color color;
  Face face;
};

bool checkPair(Card (&hand)[5]) {
	int i=0;
  for ( auto c : hand ) {
  	for ( int j=++i; j<5; ++j ) {
  		if ( c.face == hand[j].face ) return true;
		}
	}
	return false;
}



int main() {
  unionError();
  enumScoped();

	Card hand[]{{Color::Spades,Face::Seven},{Color::Hearts,Face::Eight},
			 {Color::Diamonds,Face::Ace},{Color::Hearts,Face::Ace},{Color::Hearts,Face::Queen}};
  if (checkPair(hand)) cout << "Hand with Pair" << endl;
  return 0;
}


