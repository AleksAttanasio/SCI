#include <math.h>

void MuCalc(float matrix[], float matrix_s[])
{
	int i;
	matrix[0] = 1 - matrix_s[0];

	for (i = 0; i < N + 1; i++)
	{
		if (i != N - 1)
		{
			matrix[i + 1] = matrix_s[i] - matrix_s[i + 1];
		}
		if (i == N - 1)
		{
			matrix[i + 1] = matrix_s[i];
		}
	}
}

void Sorting(float number[], int n)
{
	int i;
	float a;
	int j;

	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (number[i] < number[j])
			{
				a = number[i];
				number[i] = number[j];
				number[j] = a;
			}
		}
	}
}
int Rounded(float x)
{
	return floor(x);
}

int step(float x)
{
	if (x >= 0)
	{
		return 1;
	}

	if (x < 0)
	{
		return 0;
	}
}

int DigitsCount(unsigned int n)
{
	int count = 0;

	while (n != 0)
	{
		n /= 10;             /* n=n/10 */
		count++;
	}

	return count;
}

int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
	int rem, i = 1, binary = 0;
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		binary += rem*i;
		i *= 10;
	}
	return binary;
}

void Transform(float *x, float *y)
{
	int k;
	int i;



	for (k = 0; k < N; k++)
	{
		for (i = 0; i < Np[k]; i++)
		{
			if (x[k] >= values[k][i] && x[k] < values[k][i + 1])
			{
				y[k] = m[k][i] * x[k] + q[k][i];
			}
		}
	}
}

void SimplexCalc(int a_M[N + 1][N], int zround[], int simplex[N + 1][N])
{
	int i;
	int k;

	for (i = 0; i < N + 1; i++)
	{
		for (k = 0; k < N; k++)
		{
			simplex[i][k] = a_M[i][k] + zround[k];
		}
	}
}

void ACalc(float decimal_z[], float sorted[], int a_M[N + 1][N])
{
	int i;
	int k;

	for (k = 0; k < N + 1; k++)
	{
		a_M[0][k] = 0;
	}

	for (i = 1; i < N + 1; i++)
	{
		for (k = 0; k < N; k++)
		{
			a_M[i][k] = step(decimal_z[k] - sorted[i - 1]);
		}
	}
}

int PointsCalc(int points, const int *y)
{
	int i;
	int k;

	for (i = 0; i < N; i++)
	{
		points = points * y[i];
	}
	return points;
}

void PrepZ(int zround[], float zeta_T[], float sorted[], float decimal_z[])
{
	int i;
	int k;

	for (i = 0; i < N; i++)
	{
		zround[i] = Rounded(zeta_T[i]);
		sorted[i] = zeta_T[i] - zround[i];
		decimal_z[i] = sorted[i];
	}
}

void CoeffCalc(int coeff[], const int *y)
{
	int i;
	int k;

	coeff[N - 1] = 1;

	for (i = N - 1; i > 0; i--)
	{
		coeff[i - 1] = y[i] * coeff[i];
	}
}

void AddressCalc(int address[], int coeff[], int simplex[N + 1][N])
{
	int i;
	int k;

	for (i = 0; i < N + 1; i++)
	{
		address[i] = 0;

		for (k = 0; k < N; k++)
		{
			address[i] = address[i] + (coeff[k] * simplex[i][k]);
		}
	}
}