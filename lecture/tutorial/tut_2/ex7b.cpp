#include <iostream>

using namespace std;

float somme (float adt[][4], int r, int c) { 
    int i, j; 
    float s ; 
    for (i=0 ; i<r ; i++) 
        for (j=0 ; j<c ; j++) 
            s += adt[i][j] ; 
    return s ; 
} 
main() {
    float t[3] [4] = { {0,1,2,3}, {4,5,6,7}, {8,9,10,11} } ;
    cout << endl << "somme=" << somme (t, 3, 4); 
	}

