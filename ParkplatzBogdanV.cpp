#include<iostream>
#include<cstdlib>
#include <time.h>
#include<windows.h>
using namespace std;

void main()
{
	double P[5][10], c;
	int n, x, l, r, y, o, w;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "Die gruenen Plaetze sind frei, die roten sind besetzt" << endl;
	srand(time(NULL));

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 10; j++)
		{

			P[i][j] = 0;

		}

	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			n = rand() % 2;
			if (n != 0)
			{
				P[i][j] = 0;
			}
			else
			{
				c = i;
				P[i][j] = (c + 1) + 0.1 * (j + 1);
			}
		}
	}
	do {
		y = 1;
		for (int i = 0; i < 5; i++)
		{

			for (int j = 0; j < 10; j++)
			{

				if (P[i][j] != 0)
				{
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << i + 1 << "." << j + 1 << " ";

				}
				else
				{
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << i + 1 << "." << j + 1 << " ";

				}

			}

			cout << endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		cout << "Sie koennen den naechsten freien Parkplatz (1) waehlen oder den Parkplatz verlassen (2)" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{

			for (int i = 0; i < 5; i++)
			{

				for (int j = 0; j < 10; j++)
				{

					if (P[i][j] != 0)
					{
						c = i;
						P[i][j] = 0;
						cout << "Reihe: " << c + 1 << " Platz: " << j + 1 << endl;
						y = 0;
						o = 0;
						break;
					}
					else
						o = 1;

				}
				if (o == 0)
					break;
			}


		}break;
		case 2:
		{ cout << "Reihe  : ";
		cin >> l;
		cout << "Platz : ";
		cin >> r;
		P[l - 1][r - 1] = l + 0.1 * r;


		}break;
		default: {cout << "Tschuess" << endl; x = 0; }break;
		}

	} while (x != 0);




	system("pause");
}