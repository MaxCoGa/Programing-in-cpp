#include "screen.h"
#include "box.h"

#include <sstream>
#include <iostream>
#include <string>

/**
 * Devoir 4 CSI 2772[A] Robert Laganiere
 * screen.cpp
 * function
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */




//Make an error TODO
//PART 4 linkedlist: https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr //
void Screen::List::enqueu(Box b) {
	List *current = new List(b);
	if (isEmpty()) {
		head = last = current;
	}
	else {
		last->setNext(current);
		last = last->getNext();
	}
	size++;
}
//


//PART 4.1//
int Screen::add(Box b) {//cree une copie de la boite fournie et sauvegarde un pointeur à cette copie.
	l -> enqueu(b);//mettre la copie de la boite dans la list
	downLeft_ = b.getDownLeft();
	upRight_ = b.getUpRight();



	//int x = b.getOrUpDown(b, 1);
	//int y = b.getOrUpDown(b, 2);
	//std::cout << x << " " << y << std::endl;
	b.draw(*this);//pointeur make an error

	return 0;
}


//PART 4.2// TODO MAKE AN ERROR
bool Screen::reorder(int boxId, int orderChange) {// deplace le pointeur pour la boite boxId le nombre de places specifie par orderChangevotre  //LAST CHANGE TODO
	List *current, *tmp;
	current = l->getHead();
	//std::cout << current;
	if (boxId == 0 && orderChange != 0) {
		l->setHead(current->getNext());
		tmp = current;
	}
	else {
		for (int i = 0; i < boxId - 1; i++) {
			current = l->getNext();
		}
		tmp = current->getNext();
		current->setNext(tmp->getNext());
	}
	for (int i = 0; i < orderChange; i++) {
		current = current->getNext();
	}
	tmp->setNext(current->getNext());
	current->setNext(tmp);

	tmp = l->getHead();
	for (int i = 0; i < l->getSize(); i++) {
		tmp->getElement().draw(*this);
		tmp = tmp->getNext();
	}

	

	return true;
}


//PART 4.3//
void Screen::draw() {//affiche les boites de l'ecran Screen à la console dans l'ordre de la liste.
	
	//std::cout << "draw" << std::endl;
	//int z(0);
	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < lenght_; j++) {
			std::cout << array[i][j];
			//z++;
		}
		std::cout << std::endl;
		//std::cout << array[i]<< std::endl;//#include <string> remove the << error wow
	}
}

//PART 4.4//
void Screen::printOrder() {//imprime les couleurs des boites dans l'ordre qu'elles apparaissent dans la liste
	if (l->isEmpty() == false) {
		current = l->getHead();
		Box currentBox(current->getElement());
		for (int i = 0; i < l->getSize(); i++) {
			if (i == 0) {
				std::cout << currentBox.getColour();
			}
			else {
				std::cout << " - ";
				current = current->getNext();
				currentBox = current->getElement();
				std::cout << currentBox.getColour();
			}
		}
	}
	std::cout << std::endl;

}

//PART 4.5//
void Screen::setColour(const Point2D &p , char colour) {//change la couleur à la position donnee.
		//stringstream ss;
		//ss << colour;
		//int pos = p.d_y+p.d_x;
		/*int z(0);
		bool find(true);
		for (int x = 0; x < height_; x++) {
			for (int y = 0; y < lenght_; y++) {

				if (x == p.d_x && y == p.d_y) {
					if (find == true) {
						array[x] += colour;
						find = false;
					}
				}
				z++;
			}
		}*/
		//ss >> *(array + p.d_y + p.d_x);
		array[p.d_y][p.d_x] = colour;
		//ss >> array[p.d_y][p.d_x]; //array fonctionne a l'envers
		//std::cout << " WORK" << std::endl;
}


