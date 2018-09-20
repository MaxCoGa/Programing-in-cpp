#include <iostream>

using namespace std;

bool copyFloats(const float *src, float *dest, int N) {
	int i, j;
	for (i=0; i<N; i++) {
		dest[i] = 0; 
	}
	for (i=0, j=0 ; j<N ; j++) {
		if (src[j] > 0) 
			{
			dest[i++] = src[j];//post increment
			}
		}
	return true;
}

int main() {
	float t1[10], t2[] = { -2.1, 4.3, 7.0, -12.0, 5.0, -1.0, 8.0, 10.0, -11.0, 20.0};
	
	if (copyFloats(t2, t1, 10)) {
		for (int i=0; i<10; i++) {
			cout << t1[i] << endl;
		}
	}
	
	return 0;
}