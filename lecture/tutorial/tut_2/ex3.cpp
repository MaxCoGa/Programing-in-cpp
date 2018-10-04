#include <iostream>

using namespace std;

int main(){ 
	int t[4] = {10, 20, 30, 40} ;
	int * ad [4] ;
	int i ;
	for (i=0 ; i<4 ; i++) ad[i] = t+i ; /* 1 */
	for (i=0 ; i<4 ; i++) cout << * ad[i] << ", " ; /* 2 */
	cout << "\n" ;
	cout << * (ad[1] + 1) << "; " << * ad[1] + 1 << "\n" ; /* 3 */
}