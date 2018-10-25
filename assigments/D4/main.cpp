// ==========================================================================
// $Id: main.cpp,v 1.2 2018/09/28 18:51:10 jlang Exp $
// CSI2372 Solution laboratory 4
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.site.uottawa.ca
// 
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: main.cpp,v $
// Revision 1.2  2018/09/28 18:51:10  jlang
// Complete Implementation
//
// Revision 1.1  2018/09/27 21:27:08  jlang
// Intermediate draft.
//
// ==========================================================================
#include <iostream>
#include <random>

#include "box.h"
#include "screen.h"

using std::cout;
using std::cin;
using std::endl;

using std::srand;
using std::rand;

int main() {
	auto width = 0, height = 0, nBoxes = 0;
	while (width <= 0) {
		cout << "Width of screen: ";
		cin >> width;
	}
	while (height <= 0) {
		cout << "Height of screen: ";
		cin >> height;
	}
	while (nBoxes <= 0) {
		cout << "Number of boxes: ";
		cin >> nBoxes;
	}
	Screen* sc = new Screen(width, height);
	srand(42);
	std::random_device rad{};
	std::mt19937 gen{ rad() };
	// Make standard dev screen width/3
	std::normal_distribution<> boxWidth{ 0.0,width / 3.0 };
	// Make standard dev screen height/3
	std::normal_distribution<> boxHeight{ 0.0,height / 3.0 };
	std::uniform_int_distribution<> xLoc(0, width - 1);
	std::uniform_int_distribution<> yLoc(0, height - 1);

	char colour = 'a';
	Box b;
	for (int i = 0; i < nBoxes; ++i) {
		b.set({ xLoc(gen), yLoc(gen) },
			std::fabs(boxWidth(gen)) + 1, std::fabs(boxHeight(gen)) + 1,
			colour++);
		sc->add(b);//TODO add LINKED LIST //make a call to function draw in box!!
		if (colour > 'z') colour = 'a';
	}

	sc->draw();
	

	while (true) {
		sc->printOrder();//a-b-c-d-e-f- etc
		int sBox = nBoxes;
		int delta = 0;
		while (sBox > nBoxes - 1) {
			cout << "Box to switch: ";
			cin >> sBox;
		}
		if (sBox < 0) break;
		cout << "Change in position: ";
		cin >> delta;
		sc->reorder(sBox, delta);//after choosing postion
		sc->draw();
		
	}
	return 0;
}