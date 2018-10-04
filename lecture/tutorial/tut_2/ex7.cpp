#include <iostream>

using namespace std;

float somme (float *adt, int r, int c) { 
    int i ; 
    float s ; 
    for (i=0 ; i<r*c ; i++) s += adt[i] ; //ou s += *(adt+i)      // où r*c = nombre total //d'Elem adt[i] passe par totu les elem
    return s ; 
} 

main() {
    float t[3] [4] = { {0,1,2,3}, {4,5,6,7}, {8,9,10,11} } ;
    cout << endl << "somme=" << somme ((float *)t, 3, 4); 
}
