/*myMath Header File - myMath.h
 *Haris Amin
 *02.13.07
 *Contains the headers for the functions
 *called in myMath.cpp file. 
 */

#ifndef MYMATH_H	
#define MYMATH_H

double func(double n);
void errorf( double delta, double x[], double y[], int numSteps, double startP);
double simpInteg(double (*f)(double), double a, double b, int n );

#endif
