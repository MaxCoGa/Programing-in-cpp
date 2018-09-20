#include <iostream>

using namespace std;

float sum_array(const float *t, int d) {
	float sum = 0.0;
	for (int i=0; i<d; i++) {
		sum += *(t+i);
	}
	return sum;
}


int main() {

	// la somme des éléments de t
	float t[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	cout << sum_array(t, 12) << endl;
}