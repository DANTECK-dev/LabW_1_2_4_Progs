#include "SecondGeneralTask.h"
#include "ThisIs.h"
#include <iostream>
#include <conio.h>

using namespace std;

enum class secondGeneralTaskMenu
{
	Exit,
	Addition,
	Subtraction,
	Multiplication,
	Division
};

double calc(double a, double b, int f)
{
	double g;

	switch ((secondGeneralTaskMenu)f)
	{
		case secondGeneralTaskMenu::Exit:
			return 0;

		case secondGeneralTaskMenu::Addition:
		{
			g = a + b;
			break;
		}

		case secondGeneralTaskMenu::Subtraction:
		{
			g = a - b;
			break;
		}

		case secondGeneralTaskMenu::Multiplication:
		{
			g = a * b;
			break;
		}

		case secondGeneralTaskMenu::Division:
		{
			if (b == 0)
				throw exception("\n\tОшибка, деление на 0! ... ");
			g = a / b;
			break;
		}

		default:
			throw exception("\n\tОшибка ввода номера операции");
	}
	return g;
}

void secondGeneralTask()
{
	cout << "\n\tВведите 1 число: ";
	int a;
	cin >> a;

	cout << "\tВведите 2 число: ";
	int b;
	cin >> b;

	cout << "\n\tВведите номер действия: \n\n\t1. Сложение\n\t2. Вычитание\n\t3. Умножение\n\t4. Деление\n\t0. Выход\n\n\t";
	char ff;
	cin >> ff;

	int f = isInteger(ff);

	double g;

	g = calc(a, b, f);

	cout << "\n\tРезультат функции: " << g << " ... ";
	char p = _getch();
	system("cls");
	return;
}