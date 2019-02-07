#ifndef SCREEN_H
#define SCREEN_H
#include "box.h"

#include <cstddef>
#include <iostream>
#include <string>
#include <stdio.h>


/**
 * Devoir 4 CSI 2772[A] Robert Lagani�re
 * screen.h
 * function definition
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */

//linkedlist : https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
using namespace std;
struct Point2D;
class Box;


/*//coordonee
struct Point2D {
	int d_x;
	int d_y;
}x,y;//coordonee*/ //not use


class Screen {
private:
	class List{
		friend class Screen;
	private:
		int size;
		List *head;
		List *last;
		List *next;
		Box element;//current element is a Box object
	public:
		//constructeur
		List() : size(0) {}
		List(Box element, List * n) {
			this->element = element;
			this->next = n;
		}
		List(Box elem) : element(elem) {}//cant use this->element(element)

		bool isEmpty() {
			return size == 0;//true if size = 0, list is empty in this case
		}

		//Make an error TODO
		void enqueu(Box b);

		//getters
		Box getElement() {
			return element;
		}
		List *getHead() {
			return head;
		}
		List *getNext() {
			return next;
		}
		int getSize() {
			return size;
		}

		//setters
		void setNext(List *n) {
			next = n;
		}
		void setHead(List *n) {
			head = n;
		}

	};

		int lenght_;
		int height_;
		int dim_;
		Point2D downLeft_;
		Point2D upRight_;
		//char colour_;//not use TODO
		string array[1000][1000];
		List *l;//liste avec noeud
		List *current;
		Box currentBox;
		

public:
	
		//constructeurs
		Screen(); // constructeur par défaut
		//Screen(int);//constructeur à un argument

		Screen(int lenght, int height) : lenght_(lenght), height_(height) {
			//std::cout << "Screen Constructor" << std::endl;
			/*lenght_ = x;
			height_ = y;

			int dim = x * y;
			array = new string[dim];
			for (int i = 0; i < dim; ++i) {
				array[i] = " ";
			}
			int z(0);
			for (int i = 0; i < y;i++) {
				for (int j = 0; j < x; j++) {
					std::cout << **array[z] << std::endl;
					z++
				}*/
				//TESTING TODO

			//create a new list->l to save the current state of the screen each time that we add/move boxes
			height_ = height;
			lenght_ = lenght;
			//int dim = lenght * height;
			dim_ = height * lenght;

			l = new List();
			//array = new string*[dim_];//height TODO:array only use to help me for the time being
			//int z(0);
			for (int x = 0; x < height; x++) {
				//array[x] = new string[dim_];//lenght
				for (int y = 0; y < lenght; y++) {
					array[x][y] = " ";//TODO
					//z++;
				}
			}
			/*
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < lenght; j++) {
					//std::cout << array[i][j];
					//z++;
					array[i][j] = " ";
				}
				//std::cout << std::endl;
				//std::cout << array[i]<< std::endl;//#include <string> remove the << error wow
			}*/
		


			/*for(int i = 0; i < sizeY; ++i) {
			delete [] ary[i];
		}
		delete [] ary;*/
		//colour_ = 'a
			//std::cout << "l:" << lenght_ << " h:" << height_ << " c:" << colour_ << std::endl;
		}// constructeur à deux arguments

		Screen(const Screen&); // constructeur copieur
	

		int add(Box);
		bool reorder(int boxId, int orderChange);
		void draw();
		void printOrder();
		void setColour(const Point2D&, char);


		//not use
		/*char getColour() const {
			return colour_;
		}*/

		
		~Screen(){
			delete &l;
			delete[] array;
		}
		


		
};



#endif