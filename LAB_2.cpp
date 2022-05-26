//in this lab using dichotomy method, and the iteration method

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
/*var - 8; 2*x-lg(x) = 7; x = [3;4]*/
using namespace std;

double f(double x)
{
	return (2*x-(log10(x)) - 7);
}

int dih()
{
	int ite=0;
	double x1,x0,c;

	cout<<"x1 = ";
	cin >> x1;
	cout << "x0 = ";
	cin >> x0;
	cout << "введите точность вычислений(эпсилон). Для разделения используйте точку" << endl;
	long double eps = 0.000001;
	cin >> eps;

	do
	{
		c = (x1 + x0)/2;
		if (f(c)*f(x1)<=0)
			x0 = c;
		else
			x1 = c;
		ite+=1;
	}
	while (fabs(x1 - x0)>=eps);
	cout << "c=" << c << endl;
	cout << "iterations = " << ite << endl;
	return ite;
}

double fi(double x, double L)
{
    return (x+L*f(x));
}

int iter()
{
	int ite=0;
	double x,y,c,b,L=-0.35;
	cout<<"x=";
	cin >> x;
	cout << "введите точность вычислений(эпсилон). Для разделения используйте точку" << endl;
	long double eps = 0.000001;
	cin >> eps;
	do
	{
		y = fi(x,L);
		b = fabs(x-y);
		x = y;
		ite+=1;
	}
	while (b>=eps);
	cout << "c=" << x <<"\n";
	cout << "iterations = " << ite << endl;
	return ite;
}

int main()
{
	cout << "2*x-lg(x) = 7" << endl;
	iter();
	system("pause");
	dih();
	system("pause");
	return 0;
}
