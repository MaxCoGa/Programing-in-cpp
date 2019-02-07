#ifndef BOX_H
#define BOX_H
//#include "screen.h" if remove no error ????
#include <string>

/**
 * Devoir 4 CSI 2772[A] Robert Laganiere
 * box.h
 * function definition
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */


class Screen;

//PART 3//
struct Point2D {
	int d_x;
	int d_y;
};




class Box {

	private://attributs private
		int lenght_;
		int height_;
		//int downLeft;
		Point2D downLeft_;
		//int upRight;
		Point2D upRight_;
		char colour_;
		//Screen *screen;

	public:
		/*struct Point2D{
			int d_x;
			int d_y;
		}x,y;*/
		
		//constructeurs
		Box(); // constructeur par défaut
		Box(Point2D p2D, int lenght, int height, char colour);
		//Box(int);//constructeur à un argument
		//Box(int, int); // constructeur à deux arguments
		//Box(Point2D, int lenght, int height, char colour);//constructeur avec le point en bas a gauche, la longueur , la hauteur et la couleur
		//Box(const Box&); // constructeur copieur

		//dessine la boite à l'ecran
		void draw(Screen &);//Screen::setColour(const Point2D&, char);


		//setters
		void set(Point2D p2D, int lenght, int height, char colour);
		void setDownLeft(Point2D x) {
			downLeft_ = x;
		}
		void setUpRight(Point2D y) {
			upRight_ = y;
		}
		void setColour(char colour) {
			this->colour_ = colour;
		}
		void setLenght(int lenght) {
			this->lenght_ = lenght;
		}
		void setHeight(int height) {
			this->height_ = height;
		}

		//getters
		char getColour() const {
			return colour_;
		}
		int getLenght()const {
			return lenght_;
		}
		int getHeight()const {
			return height_;
		}
		Point2D getDownLeft()const {
			return downLeft_;
		}
		Point2D getUpRight()const {
			return upRight_;
		}
		/*int getDownLeft_()const {
			return downLeft;
		}
		int getUpRight_()const {
			return upRight;
		}*/

		/*int getOrUpDown(Box&, int) ;
		*/

		


};






#endif