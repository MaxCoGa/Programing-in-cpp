// ==========================================================================
// $Id: gamescore.h,v 1.1 2016/09/28 03:42:31 jlang Exp $
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
// $Log: gamescore.h,v $
// Revision 1.1  2016/09/28 03:42:31  jlang
// Midterm revision based on comments by Z. Sebbani
//
// Revision 1.1  2016/09/26 02:16:59  jlang
// Draft Midterm A
//
// ==========================================================================
#ifndef _GameScore_h_
#define _GameScore_h_


#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/**
* stores a player and his/her score
*/
struct Game {
  string player;
  int score;
};

class GameScore {
	// Array of games stored in GameScore
  Game d_games[10];
  // Counter of games added to GameStore
  int d_numGamesStored=0;

public:
 // Add a new Game to the array of games, return true on success. 
 // If the array is full return false and do not store the Game. 
 bool addGame( const Game& p );

 // Return the Game with the highest score
 // If no Game is stored, return a nullpointer
 Game* getHighScore();
 
 // Print all the games stored in the games
 void print();
}; 

#endif
