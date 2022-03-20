
#define _CRT_SECURE_NO_WARNINGS
#define VER 1

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <malloc.h>
#include <algorithm>
#include <cstddef>
#include <utility>
#include <fstream>
#include <io.h> 
#include "FunctionsForAnIndividualTask.h"
#include "PersonStruct.h"

using namespace std;

void firstGeneralTask();
void secondGeneralTask();
void individualTask();
void additionalTask();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	while (true) {
		std::cout << "\n\t\tОбщие задания\n\t1. Задание 1\t2. Задание 2\n\n\t3. Индивидуальное задание 7 вариант\n\n\t4. Дополнительное задание\n\n\t0. Выход\n\n\t";
		int inputNum;
		cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
		case(0): {return 0; }
		case(1): {firstGeneralTask();	break; }
		case(2): {secondGeneralTask();	break; }
		case(3): {individualTask();		break; }
		case(4): {additionalTask();		break; }
		default: {std::cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... "; char p = _getch(); std::system("cls"); break; }
		}
		std::system("cls");
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region firstGeneralTask

	/*Напишите функцию, которая получает 2 целых числа в качестве аргумента. Эти числа
	должны быть положительными. Функция вычисляет разницу между первым и вторым. При этом
	результат разницы не должен быть меньше 0.
	Функция должна вызывать исключение, если один из переданных аргументов не
	положительный или если первый аргумент оказался меньше второго.
	Также необходимо отловить и обработать эти исключения*/

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
		cout << "\n\t" << err.what()<<"... ";
		char p = _getch();
		system("cls");
		return;
	}
	cout << "\n\tРезультат функции: " << g<<" ... ";
	char p = _getch();
	system("cls");
	return;

}


#pragma endregion 
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region secondGeneralTask

	/*Функция принимает 2 числа и номер операции (число от 1 до 4). Между двумя аргументами
	выполняется арифметическая операция в зависимости от ее номера (1 – сложение, 2 – вычитание,
	3 – деление, 4 - умножение). Для выбора операции используйте конструкцию switch().
	Функция должна вызывать исключение, если номер операции оказывается неправильным.
	Необходимо отловить и обработать это исключение. Также обработайте ситуацию с делением на0*/

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
	if (f > 4 || f < 0) 
		throw exception ("\n\tОшибка ввода номера операции! ... ");

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
		{
			std::cout << "\n\n\tОшибка ввода... ";
			char p = _getch();
			std::system("cls");
			break;
		}
	}
	return g;
}

void secondGeneralTask()
{
	cout << "\n\tВведите 1 число: ";
	double a;
	cin >> a;

	cout << "\tВведите 2 число: ";
	double b;
	cin >> b;

	cout << "\n\tВведите номер действия: \n\n\t1. Сложение\n\t2. Вычитание\n\t3. Умножение\n\t4. Деление\n\t0. Выход\n\n\t";
	int f;
	cin >> f;

	if (f == 0) return;

	double g;

	try
	{
		g = calc(a, b, f);
	}
	catch (const exception& err)
	{
		cout << err.what();
		char p = _getch();
		std::system("cls");
		return;
	}

	std::cout << "\n\tРезультат функции: " << g << " ... ";
	char p = _getch();
	std::system("cls");
	return;
}


#pragma endregion
//finished


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region individualTask


#define INDIVID_INPUT_FILE_LOCATION		"Input_Clients.txt"
#define INDIVID_OUTPUT_FILE_LOCATION	"Output_Clients.txt"

enum class individualTaskMenu
{
	Exit,
	Add,
	Sort,
	Transform,
	Del,
	Show,
	Search,
	Save,
	Load

};

void individualTask()
{										//<<<<--------main индивидуального задания

	/*Структура «Покупатель»: Дата покупки; ФИО; домашний адрес; номер телефона; сумма
	покупки. Вычисляемое значение – общая сумма покупки.*/ 
	// 1 laba

	/*1) Создание нового элемента массива структур (ввод его данных);
	2) Сортировка массива структур;
	3) Изменение заданной структуры (вводится номер элемента в массиве структур, и его
	данные изменяются на новые введенные пользователем данные);
	4) Удаление структуры из массива (можно удаляемому элементу массива присвоить
	значение последнего элемента и уменьшить количество элементов в массиве структур);
	5) Вывод на экран массива структур в виде таблицы. Также выводите вычисляемое
	значение по всему массиву, указанное в вашем варианте.
	6) Поиск в массиве структур по заданному параметру (самостоятельно выберите поле
	структуры и реализуйте поиск по нему). То есть это вывод, но только определенных данных.*/ 
	// 2 laba

	/*Измените программу индивидуального задания прошлой лабораторной работы. Добавьте
	в меню выбора новые действия пользователя «Сохранение» и «Загрузка».
	Действие «Сохранение» должно выполнять сохранение в файл всех данных вашего
	списка. При этом пользователю должен предоставляться выбор: сохранить в файл по
	умолчанию (придумайте название, к примеру, list.data) или пользователь сам вводит название
	файла, в который нужно сохранить список.
	Действие «Загрузить» должно выполнять загрузку данных вашего списка (заполнять
	список) из файла в память программы. При этом пользователю также должен предоставляться
	выбор: загрузить из файла по умолчанию или пользователь сам вводит название файла, из
	которого нужно загрузить список*/
	// 3 laba

	/*Внесите в готовую программу из предыдущей лабораторной работы следующие изменения:
	1) Программа теперь должна состоять из нескольких файлов. Функция main() должна
	содержаться в главном файле, в который подключаются остальные файлы. Программу на
	файлы разделите по функционалу. К примеру:
		 Файл, содержащий структуру данных (здесь должны быть только структура без экземпляров).
		 Файл, содержащий функции по работе с файловой системой.
		 Файл, содержащий функции по работе со списком.
	Если файлы содержат только функции, то лучше всего создать для них заголовочный файл
	(.h) с тем же именем, что и файл с описанием/кодом этих функций (.cpp). В заголовочном
	файле определите прототипы этих функций. В главный файл с функцией main() подгружайте
	именно заголовочные файлы.
	2) Добавьте условную компиляцию в программу (#if, #else, #elif и #endif). Определите макрос
	VER (#define VER). В зависимости от того чему он равен будет компилироваться
	определенная версия программы:
	1. Данные в структуру считываются только с клавиатуры. Нужно сделать так, чтобы при
	VER=1блокировались возможности считывания и сохранения данных в файл.
	2. Полная версия (VER=2), позволяющая считывать данные с файла и с клавиатуры.*/
	// 4 laba

	person* head	= NULL;
	person* tail	= NULL;
	person* clients	= NULL;

	///////	   МЕНЮ    /////////

	while (true) {
		std::cout << "\n\t   ___ ___     ______    __  ___     __    __";
		std::cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		std::cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		std::cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		std::cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		std::cout << "\n\t  ----== Введите номер нужного действия ==----  ";
		std::cout << "\n\t       ----== 1. Добавить  клиента ==----       ";
		std::cout << "\n\t   ----== 2. Сортировать всех клиентов ==----   ";
		std::cout << "\n\t    ----== 3. Изменить данные клиента ==----    ";
		std::cout << "\n\t    ----== 4. Удалить  данные клиента ==----    ";
		std::cout << "\n\t    ----== 5. Вывести список клиентов ==----    ";
		std::cout << "\n\t     ----== 6. Поиск клиента по базе ==----     ";
		std::cout << "\n\t  ----== 7. Сохранить все  данные в файл==----  ";
		std::cout << "\n\t   ----== 8. Загрузить данные из файла ==----   ";
		std::cout << "\n\t             ----== 0. Выход ==----             \n\t";

		int inputNum;
		std::cin >> inputNum;
		std::system("cls");

		clients = head;

		switch ((individualTaskMenu)inputNum) {
			case individualTaskMenu::Exit:		return;
			case individualTaskMenu::Add:		{addClients			(head, tail, clients); break; }
			case individualTaskMenu::Sort:		{sortClients		(head, tail, clients); break; }
			case individualTaskMenu::Transform: {transformClients	(head, tail, clients); break; }
			case individualTaskMenu::Del:		{delClients			(head, tail, clients); break; }
			case individualTaskMenu::Show:		{showClients		(head, tail, clients); break; }
			case individualTaskMenu::Search:	{searchClients		(head, tail, clients); break; }
			case individualTaskMenu::Save:		{saveClients		(head, tail, clients); break; }
			case individualTaskMenu::Load:		{downloadClients	(head, tail, clients); break; }
			default: {
			std::cout << "\n\tВведено неверное значение, нажмите любую клавишу для продолжения... ";
			char p = _getch();
			std::system("cls");
			break;
		}
		}
	}
}
//finished


#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region additionalTask


enum class Additional_Menu {
	Exit,
	AddStr,
	DelStr,
	ShowStr,
	SaveStr,
	LoadStr
};

void additionalTask() {

	/*
	Обеспечьте всю работу с файлами с помощью перенаправления стандартных потоков
	функцией freopen_s().
	Программа должна выполнять простую работу с массивом строк. При запуске
	пользователю на выбор предоставляется несколько действий:
		 Пользователь может добавить новую строку в массив.
		 Пользователь может удалить строку из массива по номеру (порядок строк должен остаться тот же).
		 Пользователь может вывести массив на экран.
		 Пользователь может сохранить массив строк в файле.
		 Пользователь может загрузить массив строк из файла.
		*/

	string* str = NULL;
	int size = 0;
	while (true)
	{
		cout	<< "\n\t1. Добавить строку"
				<< "\n\t2. Удалить строку" 
				<< "\n\t3. Вывести строки" 
				<< "\n\t4. Сохранить строки" 
				<< "\n\t5. Загрузить строки"
				<< "\n\t0. Выход\n\n\t";
		int menuNum;
		cin >> menuNum;
		//system("cls");
		switch ((Additional_Menu)menuNum) 
		{
			case Additional_Menu::Exit: 
				return;

			case Additional_Menu::AddStr: 
			{
				cout << "\n\tДобавить строку\n\t0. Выход\n\n\t";
				string inputStr;
				cin.get();
				getline(cin, inputStr);
				if (inputStr == "0") break;
				size++;
				if (str == NULL) str = new string[size];
				else {

					string *temp = new string[size];

					for (int i = 0; i < size-1; i++)
					{
						temp[i] = str[i];
					}

					delete[] str;

					str = new string[size];

					for (int i = 0; i < size - 1; i++) 
					{
						str[i] = temp[i];
					}

					delete[] temp;
				}
				str[size-1] = inputStr;
				//system("cls");
				//cout << str[size - 1];
				break;
			}

			case Additional_Menu::DelStr: 
			{
				if (size == 0)
				{
					cout << "\n\tНечего удалять... ";
					char p = _getch();
					//system("cls");
					break;
				}

				if (size == 1)
				{
					cout << "\n\tУдалёнa последняя строка... ";
					delete[] str;
					size = 0;
					char p = _getch();
					//system("cls");
					break;
				}

				cout << "\n\tУдаление строки\n\n\tВыберете строку:\n\n\t";

				for (int i = 0; i < size; i++)
				{
					cout << i + 1 << ": " << str[i]<<"\n\t";
				}

				int inI;
				cin >> inI;
				//system("cls");

				cout << "\n\tУдалить " << str[inI - 1] << "\n\t1. Да\t0. Выход\n\t";

				int inputI;
				cin >> inputI;
				//system("cls");

				switch (inputI) {
					case(0): break;
					case(1):
					{
						size--;

						string* temp = new string[size];

						for (int i = 0; i < inI; i++) 
						{
							temp[i] = str[i];
						}

						for (int i = inI; i < size; i++) 
						{
							temp[i] = str[i + 1];
						}

						delete[] str;

						str = new string[size];

						for (int i = 0; i < size; i++) 
						{
							str[i] = temp[i];
						}

						delete[] temp;
					}

					default:
					{
						cout << "Введено невеное значение... ";
						char p = _getch();
						//system("cls");
						break;
					}
				}

				break;
			}

			case Additional_Menu::ShowStr: 
			{
				if (size == 0) {
					cout << "\n\tНечего выводить... ";
					char p = _getch();
					//system("cls");
					break;
				}
				cout << "\n\tВывод строк(и): \n\n\t";
				for (int i = 0; i < size; i++) {
					cout << str[i]<<"\n\t";
				}
				break;
			}

			case Additional_Menu::SaveStr: 
			{	
				cout << endl << "\n\tВведите имя файла (без расширения): ";
				char fileNameOut[100];
				//cin.get();
				cin >> fileNameOut;

				int counter = strlen(fileNameOut);
				fileNameOut[counter] = '.';
				fileNameOut[counter + 1] = 't';
				fileNameOut[counter + 2] = 'x';
				fileNameOut[counter + 3] = 't';
				fileNameOut[counter + 4] = '\0';

				if (size == 0)
				{
					cout << "\n\tНечего выводить... ";
					char p = _getch();
					//system("cls");
					break;
				}
				
				FILE* file = nullptr;
				
				freopen_s(&file, fileNameOut, "w", stdout);

				for (int i = 0; i < size; i++)
				{
					cout << str[i] << endl;
				}

				freopen_s(&file, "CON", "w", stdout);

				cout << endl << "\n\tСохранено... ";
				char p = _getch();

				break;
			}

			case Additional_Menu::LoadStr: 
			{
				cout << endl << "\n\tВведите имя файла (без расширения): ";
				char fileNameIn[100];
				cin >> fileNameIn;

				cout << "\n\tВведите количество строк: ";
				int s;
				cin >> s;

				int counter = strlen(fileNameIn);
				fileNameIn[counter] = '.';
				fileNameIn[counter + 1] = 't';
				fileNameIn[counter + 2] = 'x';
				fileNameIn[counter + 3] = 't';
				fileNameIn[counter + 4] = '\0';

				FILE* file = NULL;

				freopen_s(&file, fileNameIn, "r", stdin);

				if (file != NULL) {
					cout << "\n\tФайл успешно откыт\n\t";
					for (int i = 0; i < s; i++)
					{
						size++;
						if (str == NULL) str = new string[size];
						else
						{
							string* temp = new string[size];

							for (int i = 0; i < size - 1; i++)
							{
								temp[i] = str[i];
							}

							delete[] str;

							str = new string[size];

							for (int i = 0; i < size - 1; i++)
							{
								str[i] = temp[i];
							}

							delete[] temp;
						}
						getline(cin, str[size - 1]);
						cout << "\n\tДобавлена строка: " << str[size-1];
					}
					cout << endl;
					//fclose(file);
					freopen_s(&file, "CON", "r", stdin);
				}
				else
				{
					cout << "\n\tОшибка открытия... ";
					freopen_s(&file, "CON", "r", stdin);
					char p = _getch();
					system("cls");
				}
				break;
			}
			default: 
			{
				cout << "\n\tОшибка... ";
				char p = _getch();
				//system("cls");
			}
		}
	}
}



#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////