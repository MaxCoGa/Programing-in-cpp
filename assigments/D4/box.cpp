#include "screen.h"
#include "box.h"
#include <iostream>
#include <string>

/**
 * Devoir 4 CSI 2772[A] Robert Laganiere
 * box.cpp
 * function
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */

//using namespace Box;
//namespace Box {

/**/
//PART 3//
//constructeur vide init
Box::Box() {
	Point2D p2D = Point2D{ 0,0 };//init avec le constructeur  vide a 0,0(x,y)
	setDownLeft(p2D);//set le point x, ici 0
	setUpRight(p2D);//set le point y, ici 0
	//setLenght(0);//not use
	//setHeight(0);//not use
	//setColour('null');
};
//}

//PART 3//
//constructeur a 4 arguments
Box::Box(Point2D x, int lenght, int height, char colour) {
	colour_ = colour;
	setLenght(lenght);//not use
	setHeight(height);//not use
	setDownLeft(x);//valeur choisit random par le main.cpp
	//le point en haut à droite peut etre trouver avec le point x + lenght et le point x + height
	setUpRight({ x.d_x + lenght,x.d_y + height });
};


//PART 3//
//dessine la boite à l'ecran
void Box::draw(Screen &screen) {
	for (int x = this->downLeft_.d_y; x <= this->upRight_.d_y; x++) {//du point le plus haut jusqu'au plus bas
		for (int y = this->downLeft_.d_x; y <= this->upRight_.d_x; y++)//du point le plus a gauche jusqu'au plus a droite
			//Screen::setColour(const Point2D&, char)
			screen.setColour({ y,x }, colour_);
	}
};

//PART 3//
//set les valeurs de la boite courante
void Box::set(Point2D x, int lenght, int height, char colour) {
	this->setColour(colour);
	this->setHeight(height);
	this->setLenght(lenght);
	this->setDownLeft(x);
	this->setUpRight({ x.d_x + lenght,x.d_y + height });
};


//PART 3//
/*int getOrUpDown(Box b,int s) {
	switch (s) {
	case (1): return b.getDownLeft();
		break;
	case (2): return b.getUpRight();
		break;
	}
}*/