#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

unsigned int X = 1,Y = 1;
double Z;
double linearKongMeth()
{
	const unsigned int m = int (pow(2,32) - 1);
	const int a = 2140131;
	const int c = 25312;
	X = (a*X + c) % m;
	return double(X) / m;
}

double squareKongMeth()
{
	const unsigned int m = int (pow(2, 32) - 1);
	const int a = 2140131;
	const int c = 25312;
	const int d = 25314;
	X = (d*X*X + a*X + c) % m;
	return double(X) / m;
}

double fibNumbMeth()
{
	const unsigned int m = int (pow(2, 32) - 1);
	int barChart[] = { 0,0,0,0,0,0,0,0,0,0 };
	int unsigned temp = X;
	X = X + Y;
	Y = temp;
	return double(X) / m;
}

int reverseNum(int a, int b, unsigned int & x, int & y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	unsigned int x1;
	int y1;
	int d = reverseNum(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}


double reverseKongMeth()
{
	const unsigned int m = int (pow(2, 10));
	const int a = 2140133;
	const int c = 25310;
	int y;
	reverseNum(X, m, X, y);
	X = int(a*X + c) % m;
	return double(X) / m;
}

double combinedMeth()
{
	const unsigned int m = int (pow(2, 32) - 1);
	const int a = 2140131;
	const int c = 25312;
	const int d = 25314;
	X = (a*X + c) % m;
	Y = (d*Y*Y + a*Y + c) % m;
	X = (X - Y) % m;
	return double(X) / m;
}

double threeSigmaMeth()
{
	int m = 0;
	int sigma = 1;
	double sum = 0;
	for (int i = 0; i < 12; i++)
	{
		sum += linearKongMeth();
	}
	Z = m + (sum - 6)*sigma;
	if (Z < -3) return -2.9999;
	if (Z > 3) return 2.9999;
	return Z ;
}
double polarCoordMeth()
{
	double x_1;
	double x_2;
	double s;
	do {
		x_1 = 2 * linearKongMeth() - 1;
		x_2 = 2 * linearKongMeth() - 1;
		s = pow(x_1, 2) + pow(x_2, 2);
	} while (s >= 1);
	x_1 = x_1 * sqrt((-2) * log(s) / s);
	x_2 = x_2 * sqrt((-2) * log(s) / s);
	if (x_1 < -3) return -2.9999;
	if (x_1 > 3) return 2.9999;
	return x_1;
}

double corrMeth()
{
	double xn;
	double x_1;
	double x_2;
	const double M = sqrt(8 / M_E);
	do {
		x_1 = linearKongMeth();
		do {
			x_2 = linearKongMeth();
		} while (x_2 == 0);
		xn = M * (x_1 - 0.5) / x_2;
	} while (pow(xn, 2) >= (4 * pow(M_E, -1.35) / x_2 + 1.4) || ( pow(xn, 2) > (5 - 4 * pow(M_E, 0.25) * x_2) && pow(xn, 2) > (-4 * log(xn) ) ) );
	if (xn < -3) return -3;
	if (xn > 3) return 3;
	return xn;
}

double logMeth()
{
	double temp = linearKongMeth();
	
	return (-1)* 7 * log(temp);
}

double aranceMeth()
{
	double a = 1;
	double y;
	double x;
	do {
		y = tan(M_PI * linearKongMeth());
		x = sqrt(2 * a - 1) * y + a - 1;
	} while (x <= 0 || linearKongMeth() > (1 + y) * exp((a-1) * log(x / (a - 1)) - sqrt(2 * a - 1) * y));
	if (x > 100) return 99.9;
	return x;
}
