#include <iostream>

using namespace std;


int main() {
	//formalisme tableau
	// la somme des éléments de t
	float t[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};//tableau de longueur 3 de longueur 4. Donc 3 tableau de longueur 4 chaque.

	int i, j ;
	float som = 0 ;
	for (i=0 ; i<3 ; i++)
		for (j=0 ; j<4 ; j++)
			som += t[i] [j] ;


	//formalisme pointeur
	float t2[3][4] = { {0,1,2,3}, {4,5,6,7}, {8,9,10,11} } ;
	
	cout << som << endl;
	
	float * adt ;
	som = 0 ;
	adt = (float *) t ;
	for (i=0 ; i<12 ; i++)
		som += * (adt+i);

	cout << som << endl;
}