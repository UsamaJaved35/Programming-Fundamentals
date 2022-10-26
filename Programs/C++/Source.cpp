#include<iostream>
using namespace std;
int main()
{
	char a[3][3] = { '1','2','3','4','5','6','7','8','9' };
	int b=5,c,d,e,f;
	char g = 'X';
	char h = 'O';
	for (char i = 0; i < 3; i++)
	{
		for (char j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		} 
		cout << endl;
	}
	for (e = 0; e < 4; e++)
	{
		cout << "Enter the position where you want to enter X : ";
		cin >> c;
		if (c == 1)
		{
			a[0][0] = g;
		}
		else if (c == 2)
		{
			a[0][1] = g;
		}
		else if (c == 3)
		{
			a[0][2] = g;
		}
		else if (c == 4)
		{
			a[1][0] = g;
		}
		else if (c == 5)
		{
			a[1][1] = g;
		}
		else if (c == 6)
		{
			a[1][2] = g;
		}
		else if (c == 7)
		{
			a[2][0] = g;
		}
		else if (c == 8)
		{
			a[2][1] = g;
		}
		else
		{
			a[2][2] = g;
		}
		for (char i = 0; i < 3; i++)
		{
			for (char j = 0; j < 3; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
			cout << "Enter the position where you want to enter O : ";
			cin >> d;

			if (d == 1)
			{
				a[0][0] = h;
			}
			else if (d == 2)
			{
				a[0][1] = h;
			}
			else if (d == 3)
			{
				a[0][2] = h;
			}
			else if (d == 4)
			{
				a[1][0] = h;
			}
			else if (d == 5)
			{
				a[1][1] = h;
			}
			else if (d == 6)
			{
				a[1][2] = h;
			}
			else if (d == 7)
			{
				a[2][0] = h;
			}
			else if (d == 8)
			{
				a[2][1] = h;
			}
			else
			{
				a[2][2] = h;
			}
			for (char i = 0; i < 3; i++)
			{
				for (char j = 0; j < 3; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
	}
	if (a[0][0]  && a[0][1]  && a[0][2]  || a[1][0]  && a[1][1] && a[1][2]  || a[2][0]  && a[2][1]  && a[2][2] )
	{
		cout << "Player X WINS!!!!\n";
	}
	return 0;
}