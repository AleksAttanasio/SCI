
void MuCalc(float matrix[], float matrix_s[]);
/*	
	================== MuCalc ==================

	MuCalc is a function that calculates the Mu coefficents needed for the linear interpolation. It takes as arguments two matrix:
	the first will contain Mu coefficients and the second contains the decimal part of the ordinates of the point in descending 
	order of value. 
	Mu coefficients are found by following the Mu formula: 
	
	• Mu,0 = 1 - (d^),1
	• Mu,1 = (d^),1 - (d^),2
	• ...
	• Mu,(n-1) = (d^),(n-1) - (d^),n
	• Mu,n = (d^),n

	where Mu,n are the coefficients we're looking for, and (d^),n are the values contained in the second matrix described before.

	The MuCalc function work with two nested "for" cycles. In the second "for" there is a condition that make the function able to
	know if it has arrived to the last value of Mu coefficients.

	=============================================
*/

void Sorting(float number[], int n);
/*	
	================== Sorting ==================
	
	This function is a simple Bubble Sort that will put in descending order the decimal part values of the points ordinates. 

	=============================================
*/

int Rounded(float x);
/*	================== Rounded ==================

	Rounded is a renamed "floor" function from math.h. It's renamed to make the code easier to read.

	=============================================
*/
int step(float x);
/*
	================== step ==================

	Step function is referred to the mathematical function. It returns 1 when the value it takes is more - or equal - than zero,
	or 0 if the value it takes is strictly less than zero.

	=============================================
*/

int decimal_binary(int n);

/*
	================== decimal_binary ==================

	It converts the decimal numbers to binary numbers. It works with the reminder of the division by 2 of the current value. 

	====================================================
*/

int DigitsCount(unsigned int n);
/*
	================== DigitsCount ==================

	It takes a number as variable and return the number of digits it's composed of. It will be used for the address calculation
	in the next functions.

	====================================================
*/

void Transform(float *x, float *y);
/*
	================== Transform ==================

	The Transform function allows the main routine to move a point in an uneven domain to a even one. It works with the m and q
	parameters given by MATLAB. Since the transformation is different for every domain's partition the number of m and q
	coefficients depends on the number of partitions. The transformation is linear and works with a straight line. Every single
	ordinate of the point is transformed following the straight line related to the partition in which is located. The straight
	line is generally is written: y = m*x + 1.
	This function take as argument two pointers at two matrix: the first one is the starter matrix which contains the values of
	current point, the second will contain the transformed values. The function checks if the points belong to a certain partition
	and than transform the first values and put the results into the second.

	==============================================
*/

void SimplexCalc(int a_M[N+1][N], int zround[], int simplex[N+1][N]);
/*
	================== SimplexCalc ==================

	It takes the required values from A matrix and zround vector and, by the formula of simplex corners, it evaluates the 
	ordinates of the corner of every simplex corner. The formula for calculations is:
	
	SC,n = a,n + Zr 

	Where SC,n means Simplex Corner number n; a,n is the n coefficients of the A matrix and, finally, Zr is the integer part of
	the point Z ordinates.

	====================================================
*/

void ACalc(float decimal_z[], float sorted[], int a_M[N + 1][N]);
/*
	================== ACalc ==================

	This is the function that will calculate the values of the A matrix, useful for evaluating the ordinates of the corner of the
	simplex that contain the point. At the end of this function we will have a complete matrix containing in each line the values 
	of every single a,n. 
	ACalc works with the mathematical formula that allows the main routine to, subsequently, calculate the simplex corners 
	ordinates. This operation works with two for cycles. the first one will fill the first line with zeros in order so that
	a,0 will be a zero vector. The next numbers will be calculated by the following formula: 

	a,n		= step(decimal_z,1 - sorted,n);
			= step(decimal_z,2 - sorted,n);
			= ...
			= step(decimal_z,n - sorted,n);
	
	Where a,n is the n row in A matrix, and it's composed of the n values that comes out from the iterative operation:

	step(decimal_z,1 - sorted,n)

	====================================================
*/

int PointsCalc(int points, const int *y);
/*
	================== PointsCalc ==================
	
	Returns the number of corners in the domain partition. 

	================================================
*/

void PrepZ(int zround[], float zeta_T[], float sorted[], float decimal_z);

/*
	================== PrepZ ==================
	
	This function has the objective to prepare the values of the points ordinates to be elaborated.


	===========================================
*/

void CoeffCalc(int coeff[], const int *y);
	/*
	================== CoeffCalc ==================

	This function is useful for calculating these coefficients that will be needed in the AddressCalc function to evaluate the
	simplex corners' addresses. Instead of the others described above function, this works with a backward for cycle that fills 
	the vector for the bottom to the top. This calculation is made by following the iterated formula:

	t + n,t(z) + n,t*n,z(y) + n,t*n,z*n,y(x) ...

	where
	
	n,k is the k dimension partition; t,z,y... are the ordinates of the point. Every single step along a dimension is weighted 
	onto the previous dimension.
	====================================================
*/

void AddressCalc(int address[], int coeff[], int simplex[N + 1][N]);
/*
	================== AddressCalc ==================
	
	By knowing the previously found coefficients, this function returns the address. The address is found by counting the number 
	of steps it takes for reaching the wanted address starting from the 0 address. The number of steps to do depends on the
	domain dimensions too. The more are the dimensions the more are the steps to do for getting to the point.

	====================================================
*/
