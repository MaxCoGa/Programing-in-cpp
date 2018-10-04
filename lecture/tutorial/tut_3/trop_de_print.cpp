#include <iostream>

using namespace std;

// note: (*a).b is equivalent to a->b
// 

struct point
{ char c ;
int x, y ;
} ;

// plusieurs fonctions avec la meme signature
// lesquels des suivantes causent des problemes? Pourquoi?

void print_point(point p) {
	std::cout << p.c << "(" << p.x << "," <<p.y << ")" << std::endl;
}

void print_point(point *p) {
	(*p).x = 7;
	std::cout << p->c << "(" << p->x << "," << (*p).y << ")" << std::endl;
}

void print_point(const point &p) {
	std::cout << p.c << "(" << p.x << "," <<p.y << ")" << std::endl;
	p.c = 'b';
}

void print_point(point &p) {
	std::cout << p.c << "(" << p.x << "," <<p.y << ")" << std::endl;
	p.c = 'b';
}

// modifie un point passe par copie d'un pointeur 
void swap_point(point *p) {
	int tmp = (*p).x;
	(*p).x = p->y;
	p->y = tmp;
}


int main() {
	point p = {'a', 10, 20};

	print_point(p); // par copie ou par reference? const?
	
	print_point(&p); // appel pour fonction nomme print_point qui prend un pointeur a un point

	swap_point(p); // ne marche pas
	swap_point(&p); // par pointeur
	
}
