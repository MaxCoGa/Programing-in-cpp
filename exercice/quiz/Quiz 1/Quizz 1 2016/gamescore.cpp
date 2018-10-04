// ==========================================================================
// $Id: gamescore.cpp,v 1.1 2016/09/28 03:42:31 jlang Exp $
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
// $Log: gamescore.cpp,v $
// Revision 1.1  2016/09/28 03:42:31  jlang
// Midterm revision based on comments by Z. Sebbani
//
// ==========================================================================

#include "gamescore.h"


// Add a new Game to the array of games, return true on success. 
// If the array is full return false and do not store the Game. 
bool GameScore::addGame( const Game& p ) {
  if ( d_numGamesStored == 10 ) return false;
  d_games[d_numGamesStored++] = p;
  return true;
}

// Return the Game with the highest score
// If no Game is stored, return a nullpointer
Game* GameScore::getHighScore() {
  if ( d_numGamesStored == 0 ) return nullptr;
  Game high{"",-1};
  for ( int i=0; i<d_numGamesStored; ++i ) {
    if ( d_games[i].score > high.score ) high = d_games[i];
  }
  return new Game(high);
}

 
 // Print all the games stored in the games
 void GameScore::print() {
	for ( int i=0; i<d_numGamesStored; ++i ) {
    cout << d_games[i].player << " " << d_games[i].score << endl;
  }
  return;
}

int main() {
  GameScore gs;
  Game gA{ "Sophia", 1200 };
  gs.addGame(gA);
  Game gB{ "Sophia", 1500 };
  gs.addGame(gB);
  Game gC{ "Emma", 1000 };
  gs.addGame(gC);
  Game gD{ "Liam", 1800 };
  gs.addGame(gD);
  Game gE{ "Oliver", 2500 };
  gs.addGame(gE);
  Game gF{ "Maya", 3000 };
  gs.addGame(gF);
  gs.print();
  cout << "-------------------------" << endl;
  Game* p = gs.getHighScore();
  cout << p->player << " "  << p->score << endl;
  delete p;
  return 0;
}
