#include <iostream>

using namespace std;

// note: (*a).b is equivalent to a->b
// but the latter looks cooler
// 

struct point
{ char c ;
int x, y ;
} ;


// plusieurs fonctions avec la meme signature. uh oh?
// lesquels des suivantes vont causer des collisions ?

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


// modifie un point passe par pointeur
void swap_point(point *p) {
	int tmp = (*p).x;
	(*p).x = p->y;
	p->y = tmp;
}


int main() {
	point p = {'a', 10, 20};
	print_point(&p);
	swap_point(&p);
	print_point(p);
	
}
