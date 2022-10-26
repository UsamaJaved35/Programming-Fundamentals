#include<iostream>
#include<cmath>
using namespace std;

double add(double a, double b)
{
	double d = 0;
	d = a + b;
	return d;
}
double subtract(double a, double b)
{
	double d = 0;
	d = a - b;
	return d;
}
double multiply(double a, double b)
{
	double d = 0;
	d = a * b;
	return d;
}
double divide(double a, double b)
{
	double d = 0;
	d = a / b;
	return d;
}
double takemode(int a, int b)
{
	double d = 0;
	d = a % b;
	return d;
}
double takepower(int a, int b)
{
	double d = 0;
	d = a ^ b;
	return d;
}
double takesquareroot(double a)
{
	double d = 0;
	d = sqrt(a);
	return d;
}
double takecuberoot(double a)
{
	double d = 0;
	d = cbrt(a);
	return d;
}
double takesin(double a)
{
	double d = 0;
	d = sin(a);
	return d;
}
double takecos(double a)
{
	double d = 0;
	d = cos(a);
	return d;
}
double taketan(double a)
{
	double d = 0;
	d = tan(a);
	return d;
}
double takeLog2(double a)
{
	double d = 0;
	d = log2(a);
	return d;
}
double takeInverseSin(double a)
{
	double d = 0;
	d = asin(a);
	return d;
}
double takeInverseCos(double a)
{
	double d = 0;
	d = acos(a);
	return d;
}
double takeFloorVal(double a)
{
	double d = 0;
	d = floor(a);
	return d;
}
double takeCeilVal(double a)
{
	double d = 0;
	d = ceil(a);
	return d;
}
int main()
{
	char c = 'y';
	while (c == 'y')
	{
		cout << "************************************" << endl;
		cout << "CALCULATOR" << endl;
		cout << "Enter 1 to add numbers.\nEnter 2 to subtract numbers.\nEnter 3 to multiply numbers.\nEnter 4 to divide numbers.\n";
		cout << "Enter 5 to take modulus.\nEnter 6 to take power.\nEnter 7 to take squareroot.\nEnter 8,9 and 10 to take sin,cos and tan respectively.\n";
		cout << "Enter 11 to take cuberoot.\nEnter 12 to find log of number with base 2.\nEnter 13 to take sin inverse.\nEnter 14 to take cos inverse.\n";
		cout << "Enter 15 to find floor value of a number.\nEnter 16 to find ceiling value of a number\n";
		int a = 0; int b = 0;
		int m = 0;
		cout << "enter value of m:";
		cin >> m;
		double d = 0;
		switch (m)
		{
		case 1:
		{
			cout << "Enter value of a:";
			cin >> a;
			cout << "Enter value of b:";
			cin >> b;
			d = add(a, b);
			cout << d;
			break;
		}
		case 2:
		{
			cout << "Enter value of a:";
			cin >> a;
			cout << "Enter value of b:";
			cin >> b;
			d = subtract(a, b);
			cout << d;
			break;
		}
		case 3:
		{
			cout << "Enter value of a:";
			cin >> a;
			cout << "Enter value of b:";
			cin >> b;
			d = multiply(a, b);
			cout << d;
			break;
		}
		case 4:
		{
			cout << "Enter value of a:";
			cin >> a;
			cout << "enter value of b:";
			cin >> b;
			d = divide(a, b);
			cout << d;
			break;
		}
		case 5:
		{
			cout << "enter value of a:";
			cin >> a;
			cout << "Enter value of b:";
			cin >> b;
			d = takemode(a, b);
			cout << "ans is:" << d;
			break;
		}
		case 6:
		{
			cout << "Enter value of a:";
			cin >> a;
			cout << "Enter value of b:";
			cin >> b;
			d = takepower(a, b);
			cout << d;
			break;
		}
		case 7:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takesquareroot(a);
			cout << d;
			break;
		}
		case 8:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takesin(a);
			cout << d;
			break;
		}
		case 9:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takecos(a);
			cout << d;
			break;
		}
		case 10:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = taketan(a);
			cout << d;
			break;
		}
		case 11:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takecuberoot(a);
			cout << d;
			break;
		}
		case 12:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takeLog2(a);
			cout << d;
			break;
		}
		case 13:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takeInverseSin(a);
			cout << d;
			break;
		}
		case 14:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takeInverseCos(a);
			cout << d;
			break;
		}
		case 15:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takeFloorVal(a);
			cout << d;
			break;
		}
		case 16:
		{
			cout << "Enter value of a:";
			cin >> a;
			d = takeCeilVal(a);
			cout << d;
			break;
		}
		default:
		{
			cout << "you entered incorrect operation";
		}
		}
		cout << endl;
		cout << "Enter y to reuse or enter any key to stop:";
		cin >> c;
	}
	return 0;
}