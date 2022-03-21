#include "FirstGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>

using namespace std;

int subtraction(int a, int b)
{
	if (a < 0 || b < 0)
		throw exception("\n\tАргументы должны быть не отрицательными!");
	if (a < b || a - b < 0)
		throw exception("\n\tПервый аргумент должн быть больше второго!");
	return a - b;
}

void firstGeneralTask()
{
	cout << "\n\tВведите 1 число: ";
	int a;
	cin >> a;

	cout << "\n\tВведите 2 число: ";  
	int b;
	cin >> b;

	int g;
	
	try
	{

		g = subtraction(a, b);

	}

	catch (const exception& err)
	{
		cout << "\n\t" << err.what() << "... ";
		char p = _getch();
		system("cls");
		return;
	}

	cout << "\n\tРезультат функции: " << g << " ... ";
	char p = _getch();
	system("cls");
	return;

}