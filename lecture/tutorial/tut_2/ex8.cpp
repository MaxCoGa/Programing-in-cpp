#include <iostream>

using namespace std;

int main() {

	int n = 0;
	cout << "Enter size of array: ";
	while(!(cin>> n)){
		cout<<"Wrong input! Please enter your number again: ";
		cin.clear();
		cin.ignore();
	}

	int * adt1, *adt2;


	adt1 = new int [n] ;
	adt2 = new int [n] ;

	cout << "Enter " << n << " integers for array: " << endl;
	for (int i=0; i<n; i++) {
		cin >> adt1[i] ;
		adt2[i] = adt1[i] * adt1[i] ;
	}


	delete adt1 ;

	for (int i=0; i<n; i++) {
		cout << adt2[i] << " ";
	}
	cout << endl;
	delete adt2 ;

}