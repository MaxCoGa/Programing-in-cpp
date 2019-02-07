#ifndef TRAPEZOIDAL
#define TRAPEZOIDAL
/**
 * Devoir 3 CSI 2772[A] Robert Laganiere
 * trapezoidal.h
 * function definition
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539)
 *
 */

 //3.
double line(double array[3], double x);
double quadratic(double array[3], double x);
double trigs(double array[3], double x);

//4. 
double *xrange(double xmin, double xmax, int nSteps);

//5.
double trapezoidal(double(*foo)(double array[3], double x), double (&param)[3], double *xVals, int nSteps, double **yVals);



#endif
