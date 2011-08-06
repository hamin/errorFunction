/*Math Functions - myMath.cpp
 *Haris Amin
 *02.13.07
 *Defines three functions:
 *- func --> returns e^(-n*n)
 *- errorf --> calculates the error function
 *  for a desired range given by the user.
 *- simpInteg --> integrates a function using Simpson's rule . 
 */



#include "myMath.h"
#include <cmath>

double func(double n)
{
	return exp( - n * n );	
}

void errorf( double delta,double arg1[], double arg2[], int numSteps, double startP)
{
	const double PI = 4.0*atan(1.0);  // Numerical approximation for Pi
	double x = startP;
	double c = 2/sqrt(PI);
	int n = 16; // Number of panels
	
	for( int i = 0; i < numSteps; i++) 
	{
		arg1[i] = x;
		arg2[i] = c * simpInteg(func,0,x,n );  
		x = x + delta;	
	}	
}


double simpInteg(double (*f)(double), double a, double b, int n )
{

	double delta = fabs(b-a)/n;
	double integ = 0;

	double x = a + 2*delta;	
	for( int i = 0; i < (n/2)-1 ; i++) // Adds 2 times the values of even points
	{
		integ = integ + 2.0*f(x);  // First evaluates the function at the 
		x = x + (2 * delta);	   // current point and then goes to the next
	}				   // point 2*delta away.

	x = a + delta;			// Resets our starting point to the point a
	for( int i = 0; i < n/2 ; i++) // Adds 4 times the values of odd points
	{
		integ = integ + 4.0*f(x);   // First evaluates the function at the 
		x = x + (2 * delta);       // current point and then goes to the next
	}				   // point 2*delta away.

	return  (delta/3) * (f(a) + integ + f(b))  ;

	// Note: Simpson's Rule would normally call for delta to be divided by
	// 6. However, in our implementation the delta is actually twice the value
	// of each increment.
}
