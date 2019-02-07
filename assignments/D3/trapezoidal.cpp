#include <iostream>
#include "trapezoidal.h"
#include <cmath>

/**
 * Devoir 3 CSI 2772[A] Robert Laganiere
 * trapezoidal.cpp
 * function
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */
using namespace std;

//3.
//line function
double line(double array[3], double x) {
	//cout << "line" << endl;//test line
	//y = ax + b
	return (array[0] * x + array[1]);
};

//quadratic function
double quadratic(double array[3], double x) {
	//cout << "quadratic" << endl;//test line
	//y = ax^2 + bx + c
	return (array[0] * pow(x, 2) + array[1] * x + array[2]);
};

//trigonometric function
double trigs(double array[3], double x) {
	//cout << "trigs" << endl;//test line
	//y = a sin(bx) + c
	return (array[0] * sin(array[1] * x) + array[2]);
};



//4. array of xVals
double* xrange(double xmin, double xmax, int nSteps) {//lower bound, upper bound, number of segment
	//cout << "xrange" << endl;
	//nSteps = (11);
	//xmax = (3.14);
	//xmin = (0);

	double h = (xmax - xmin) / (nSteps - 1);//find the h that we need for nSteps
	bool first(true);

	// dynamically allocate memory of size sz
	double* dyna = new double[nSteps];

	// assign values to allocated memory
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < nSteps; j++) {
			if (first) {
				*(dyna + i + j) = xmin;
				first = false;
			}
			else {
				xmin = xmin + h;
				*(dyna + i + j) = xmin;
			}
		}
	}

	//cout << "terminated normally" << endl;//test line only

	//print allocated memory
	//for (int j = 0; j < nSteps; j++) {
		//cout << *(dyna + 0 + j) << " ";
	//}
	//cout << endl;

	// deallocate memory
	//delete[] dyna;

	return dyna;
};

//5.
double trapezoidal(double(*foo)(double array[3], double xVal), double (&param)[3], double *xVals, int nSteps, double **yVals) {
	//cout << "trapozoidal" << endl;

	double ub = xVals[nSteps-1];//upper bound
	double lb = xVals[0];//lower bound
	//cout<<"upper bound: "<<ub<< " lower bound: "<<lb<<endl;//testline only

	//double a = param[0];
	//double b = param[1];
	//double c = param[2];
	//cout << "param abc: " << a <<" "<< b << " "<<c << endl;//tetsline only

	double h = (ub - lb) / (nSteps - 1);

	double sum(0);
	double x = lb;

	while (x < ub){
		sum += (foo(param, x) + foo(param, (x + h)));
		x = x + h;
		//cout << sum << " " << x << endl;//testline only
	}
	//integral
	double integral = sum * h / 2;




	
	bool first(true);
	//double y;
	//cin >> y;
	*yVals = new double[nSteps];

	//if (y != 0) {
		// dynamically allocate memory of size sz
		

		// assign values to allocated memory
		//for (int i = 0; i < 1; i++) {
			for (int j = 0; j < nSteps; j++) {
				if (first) {
					//cout << "loop 1" << endl;
					(yVals[0][j]) = (foo(param, xVals[j]));
					first = false;
				}
				else {
					//cout << "loop 2 ";
					(yVals[0][j]) = (foo(param, xVals[j]));;
				}
			//}
		//}
	}
	


	return integral;
};



/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int nSteps(3);
	double xmax(4);
	double xmin(3);

	double h = (xmax - xmin)/(nSteps-1);//find the h that we need for nSteps
	bool first(true);

	// dynamically allocate memory of size sz
	double* dyna = new double(static_cast<double>(nSteps));

	// assign values to allocated memory
	for (int i = 0; i < 1; i++){
		for (int j = 0; j < nSteps; j++){
				if(first){
					*(dyna + i + j) = xmin;
					first = false;
				}
				else{
					xmin = xmin + h;
					*(dyna + i + j) = xmin;
				}
		}
	}

	cout << "terminated normally" <<endl;

	//print allocated memory
	for( int j = 0; j<nSteps; j++){
		cout << *(dyna + 0 +j) << " ";
	}
	cout << endl;

	// deallocate memory
	delete[] dyna;

	return 0;
}
*/