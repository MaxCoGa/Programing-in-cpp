/**
 * Devoir 3 CSI 2772[A] Robert Laganière
 * main.cpp
 * use for test only
 *
 *
 *
 * @author Lang
 *
 */
#include <iostream>


#include "trapezoidal.h"


using std::cout;
using std::endl;
using std::cin;

int main() {
	cout << "Select a function from below: " << endl;
	cout << "1)  y = ax + b " << endl;
	cout << "2)  y = ax^2 + bx + c " << endl;
	cout << "3)  y = a sin(bx) + c " << endl;
	auto select = -1;
	while (select < 1 || select>3) {
		cout << "Enter 1, 2 or 3: "; cin >> select;
		cout << endl;
	}
	double para[3];
	cout << "Enter parameter a: "; cin >> para[0];
	cout << "Enter parameter b: "; cin >> para[1];
	if (select != 1) {
		cout << "Enter parameter c: "; cin >> para[2];
	}
	double xVal;
	cout << "Enter x: "; cin >> xVal;
	cout << endl;

	auto foo = &line;
	switch (select) {
	case 2:
		foo = &quadratic;
		break;
	case 3:
		foo = &trigs;
		break;
	default:
		break;
	}
	auto yVal = foo(para, xVal);
	cout << "f(" << xVal << ") = " << yVal << endl << endl;
	double xmin = 1.0, xmax = -1.0;
	int nSteps = 0;
	while (xmax < xmin || nSteps < 2) {
		cout << "Enter xmin  xmax  nSteps: "; cin >> xmin >> xmax >> nSteps;
		//    cout << xmin << " " << xmax << " " << nSteps << endl;
	}
	auto xVals = xrange(xmin, xmax, nSteps);
	cout << "X = { ";
	for (int i = 0; i < nSteps; ++i) {
		cout << xVals[i] << " ";
	}
	cout << "}" << endl;
	double** yVals = new double*;//
	auto iVal = trapezoidal(foo, para,
		xVals, nSteps, yVals);
	cout << "Integral: " << iVal << endl;

	cout << "Y = { ";
	for (int i = 0; i < nSteps; ++i) {
		cout << (*yVals)[i] << " ";
	}
	cout << "}" << endl;

	delete[] xVals; delete[](*yVals); delete yVals;
	return 0;
}

