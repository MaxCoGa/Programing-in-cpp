#include <iostream>

using namespace std;

int main() {
	int x[10];
	int y[10];
	int *p = y;
	
	// A. Formalisme tableau
	cout << "Enter 10 numbers: ";
	for (int i=0; i<10; i++) {
		cin >> x[i];
	}
	
	int min = x[0];
	int max = x[0];
	
	for (int j=1; j<10; j++) {
		if (x[j] < min) 
			min = x[j];
		if (x[j] > max)
			max = x[j];
	}
	cout << "Min/max: " << min << "/" << max << endl;
	
	// B. Formalisme pointeur (à compléter) // 2 façons
	
	for (int j=1; j<10; j++) {
		if (*(p+j) < min) 
			min = *(p+j);
		if (*(p+j) > max)
			max = *(p+j);
	}
	cout << "Min/max: " << min << "/" << max << endl;

	
	for (p +=1; p!= end(x); p++) {
		if (*p < min) 
			min = *p;
		if (*p > max)
			max = *p;
	}
	cout << "Min/max: " << min << "/" << max << endl;

	return 0;
}