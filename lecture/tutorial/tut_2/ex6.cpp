#include <iostream>

using namespace std;

//reference
void maxmin1 (int t[], int n, int & admax, int & admin) {
	admax = t[0];
	admin = t[0];
	for (int i=1; i<n; i++) {
		if ( *(t+i) < admin) admin = *(t+i);
		if ( *(t+i) > admax) admax = *(t+i);
	}
}

//pointeur
void maxmin2 (int t[], int n, int * admax, int * admin) {
	*admax = t[0];
	*admin = t[0];
	for (int i=1; i<n; i++) {
		if ( *(t+i) < *admin) *admin = *(t+i);
		if ( *(t+i) > *admax) *admax = *(t+i);
	}
}



int main() {
	
	int  max, min, t[8] = { 2, 5, 7, 2, 9, 3, 9, 4} ;
	
	for (int x : t) {
		cout << x << " ";
	}
	cout << endl;
	
	maxmin1 (t, 8, max, min);
	
	cout << "Max/min: " << max << "/" << min <<endl;
	
	maxmin2 (t, 8, &max, &min);
	
	cout << "Max/min: " << max << "/" << min <<endl;
	

}