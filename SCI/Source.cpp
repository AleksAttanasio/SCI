#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parameters.h"
#include "func_def.h"
#include "functions.h"
#include "data.h"
/*	
	================== Main ==================

	The main purpose of this routine is calculating a PWAS function in a particular point. A PWAS function is a PieceWise Affine
	function defined on a domain divided into Simplices. The value of the PWAS function is calculated by a linear interpolation
	of function values in the simplices corner containing the point. Finally the value of the function calculated in the point
	will be the summation of the products between the mu coefficients and the omegas (corner values of the function).
	The point is given by MATLAB with all the required paramters such as: partitions number, domain dimensions, function values 
	in the corner of the simplices and data needed for transform an unevenly divided domain in an evenly divided. 

	The following routine is able to, knowing the ordinates of a point, find in which simplex of the domain it is contained and, 
	after that, calculating the PWAS function in that point.

	=========================================
*/

int main()
{
	float zeta[N];
	float zeta_T[N];
	int i;
	int k;
	int j;
	int points = 1;
	int zround[N];
	float decimal_z[N];
	float sorted[N];
	float mu[N + 1];
	int address[N + 1];
	int nbit;
	int a_M[N + 1][N];
	int simplex[N + 1][N];
	int coeff[N];
	float f_PWAS;

	/*initializaion of points*/

	/* initialization of function*/

	while (true)
	{
		for (j = 0; j < npoints; j++)
		{
			for (k = 0; k < N; k++)
			{
				zeta[k] = 310.224 * pointsM[j][k] + 2047.48;  // converting from [496.36 3598.6] to [-5 5]
			}

			/*Transforming Z in a equally distributed space... */
			Transform(zeta, zeta_T);

			/* Preparing Z for elaboration... */
			PrepZ(zround, zeta_T, sorted, decimal_z);
			Sorting(sorted, N);

			/* A matrix... */
			ACalc(decimal_z, sorted, a_M);

			/* declaring simplex corner... */
			SimplexCalc(a_M, zround, simplex);

			/* calculating mu matrix... */
			MuCalc(mu, sorted);

			/* calculating numbe of points */
			points = PointsCalc(points, Np);
			nbit = decimal_binary(Np[0] - 1);
			nbit = DigitsCount(nbit);

			/* coefficent calculation... */
			CoeffCalc(coeff, Np);
			AddressCalc(address, coeff, simplex);

			f_PWAS = 0;

			for (i = 0; i < N + 1; i++)
			{
				k = address[i];
				f_PWAS = f_PWAS + (mu[i] * data[k]);
			}

			f_PWAS = 2047.5*f_PWAS + 1023.75;	// converting from [0 4095] to [-2 2]
		}
		return 0;
	}

}