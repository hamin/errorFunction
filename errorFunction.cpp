/*Error Function Integrator - errorFunction.cpp
 *Haris Amin
 *02.03.07
 *Integrates the error function of
 *an interval given by the user.
 *The function is integrated using 
 *Simpson's rule. The results are then
 *printed on a text file labeled "results.dat"
 *which is compatible with GNUPlot.
 */

#include<iostream>
#include<cmath>
#include<fstream>
#include "myMath.h"

using namespace std;

void printData( double arg1[],double arg2[], int size ); // Prints two arrays to a gnuplot file.

int main()
{
	double beginPoint; // First point of the interval
	double endPoint;   // End point of the interval
	double stepSize;   // The size of the integration steps
	cout<<"This program will calculate the error function for values "<<endl;
	cout<<"within a given interval."<<endl;
	cout<<"Enter the beginning point of the interval ===>"<<"";
	cin >> beginPoint;
	cout<<"Enter the end point of the interval ===>"<<"";
	cin >> endPoint;
	cout<<"Enter the increment between the x values ===>"<<"";
	cin >> stepSize;

	
	int size = (int)( (fabs(endPoint - beginPoint) /stepSize) + 2 ); 
	//Note: You add 2 to include the starting point and ending point.
	
	double errorValues[size];					
	double values[size];						

	errorf(stepSize,values,errorValues,size,beginPoint);

	printData( values,errorValues,size);

	cout<<"GREAT!"<<endl;
	return EXIT_SUCCESS;
}

void printData( double arg1[],double arg2[], int size )
{
		ofstream myfile ("results.dat");
		if (myfile.is_open())
		{
	
			myfile<<"#Value"<<"	|	"<<"erf(x)\n";
			myfile<<"#-----"<<"		"<<"--------------\n";

			for( int i = 0; i < size; i++)
			{
				myfile<< arg1[i] <<" 		"<< arg2[i]<<endl;
			}
		}
		else cout << "Unable to open file";

		

}
