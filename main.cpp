#include <iostream>
#include "methods.h"
using namespace std;


void gist(double(*meth)(), int meth_numb)
{	
	int barsAmnt;	//Кількість інтервалів.
	int I_MAX;	//Кількість згенерованих чисел.
	int shift;	//Зміщення відносно 0 вліво.
	double interval;	//Обернений розмір інтервалів.
	if(meth_numb <= 5)
	{
		barsAmnt = 10;
		I_MAX = 1000000;
		shift = 0;
		interval = 10;

	}
	if (meth_numb >= 6 && meth_numb <= 8)
	{
		barsAmnt = 10;
		I_MAX = 1000000;
		shift = 3;
		interval = 1 / 0.6;
	}

	if (meth_numb == 9 ||  meth_numb == 10)
	{
		barsAmnt = 100;
		I_MAX = 1000000;
		shift = 0;
		interval = 1;
	}

	int *barChart = new int [barsAmnt] ;	//Лічільник, рахує кількість 

	for (int j = 0; j < barsAmnt; j++) barChart[j] = 0;

	for (int i = 0; i < I_MAX; ++i)
	{
		double x_n = meth();
		barChart[int((x_n + shift) * interval)]++;
	}

	for (int i = 0; i < barsAmnt; ++i)
	{
		cout << "[" << (i / interval) - shift << "," << ((i + 1) / interval) - shift << "] \t" << barChart[i] / double(I_MAX) << endl;
	}

	delete [] barChart;
}

int main()
{
	double (*methods[])() = { linearKongMeth,
		squareKongMeth, 
		fibNumbMeth, 
		reverseKongMeth, 
		combinedMeth,
		threeSigmaMeth, 
		polarCoordMeth,
		corrMeth,
		logMeth,
		aranceMeth};
	int i = 0;
	cout << "This is the programme showing the bar chart for a choosen algorithm, \nthat generates random numbers. \nType number _ for algorithm:" << endl;
	cout << "1 - Linear Congruent Method.\n";
	cout << "2 - Square Congruent Method.\n";
	cout << "3 - Fibonachi Numbers Method.\n";
	cout << "4 - Reverse Congruent Method.\n";
	cout << "5 - Combined Method.\n";
	cout << "6 - Rule 'Three Sigma'.\n";
	cout << "7 - Polar Coordinates Method.\n";
	cout << "8 - Correlation Method.\n";
	cout << "9 - Logarithm Method.\n";
	cout << "10 - Arance's Method.\n";
	for (int j = 0; j < 10; j++)
	{
		cin >> i;
		cout << "You've choosen method number : " << i << endl;
		gist((*methods[i - 1]), i);
	}
	system("pause");
}