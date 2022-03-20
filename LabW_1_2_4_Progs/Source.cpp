﻿#define _CRT_SECURE_NO_WARNINGS
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
//#include<zconf.h>

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

int calc(double a, double b, int f)
{

	if (f > 4 || f < 0) 
		throw exception ("\n\tОшибка ввода номера операции! ... ");

	int g;

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

#define FUNCTIONSFORANINDIVIDUALTASK_H_ 
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

struct person {
	person* next = NULL;
	person* prev = NULL;
	struct {
		string	Surname = { "None" };
		string	Name = { "None" };
		string	Patronymic = { "None" };
		string	Address = { "None" };
		string	PhoneNum = { "None" };
		string	PayDay = { "None" };
		int 	Summ = 0;
	}Data;
};

/*
void addClients			(person*& head, person*& tail, person*& clients);
void sortClients		(person*& head, person*& tail, person*& clients);
void transformClients	(person*& head, person*& tail, person*& clients);
void delClients			(person*& head, person*& tail, person*& clients);
void showClients		(person*& head, person*& tail, person*& clients);
void searchClients		(person*& head, person*& tail, person*& clients);
void saveClients		(person*& head, person*& tail, person*& clients);
void downloadClients	(person*& head, person*& tail, person*& clients);
*/

void individualTask() {										//<<<<--------main индивидуального задания

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
		std::cout << "\n\t   ----== 8. Загрузить данные из файла ==----  ";
		std::cout << "\n\t              ----== 0.  Выход ==----           \n\t";

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
		/*		
		if (tail == NULL && head == NULL) continue;
		clients = head; 
		while (true) {
			if (clients->next == nullptr) break;
			clients = clients->next;
			tail = clients;
		}
		while (true) {
			if (clients->prev == nullptr) break;
			clients = clients->prev;
			head = clients;
		}
		*/
	}
}
//finished

/*void addClients(person*& head, person*& tail, person*& clients) {
	
	std::cout << "\n\n\tДобавление клиента\n";
	string	newSurname		= { "None" };
	string	newName			= { "None" };
	string	newPatronymic	= { "None" };
	string	newAddress		= { "None" };
	string	newPhoneNum		= { "None" };
	string	newPayDay		= { "None" };
	int		newSumm			= 0;

	std::cout << "\n\tВведите данные клиента\n";
	std::cout << "\n\tФамилия: "; 	cin.get();		std::getline(cin, newSurname);
	std::cout << "\n\tИмя: ";						std::getline(cin, newName);
	std::cout << "\n\tОтчество: ";					std::getline(cin, newPatronymic);
	std::cout << "\n\tАдресс: ";					std::getline(cin, newAddress);
	std::cout << "\n\tНомер телефона (без +7): ";	std::getline(cin, newPhoneNum);
	std::cout << "\n\tДень оплаты (ДД.ММ.ГГГГ): ";	std::getline(cin, newPayDay);
	std::cout << "\n\tСумму покупки: ";				cin >> newSumm;
	std::system("cls");

	if (tail == NULL && head == NULL) {
			tail = new person;
			clients = tail;
			head = tail;
			clients->Data.Surname = newSurname;
			clients->Data.Name = newName;
			clients->Data.Patronymic = newPatronymic;
			clients->Data.Address = newAddress;
			clients->Data.PhoneNum = "+7" + newPhoneNum;
			clients->Data.PayDay = newPayDay;
			clients->Data.Summ = newSumm;

			std::cout << "\n\tДобавлен \n" << "\n\tфамилия: " << newSurname
				<< "\n\tИмя: " << newName << "\n\tОтчество: " << newPatronymic
				<< "\n\tАдресс: " << newAddress << "\n\tНомер телефона: +7" << newPhoneNum
				<< "\n\tДень оплаты: " << newPayDay << "\n\tСумму покупки: " << newSumm;

			std::cout << "\n\n\tНажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
	}
	clients = tail;
	clients->next = new person;
	clients->next->prev = clients;
	clients = clients->next;
	clients->Data.Surname = newSurname;
	clients->Data.Name = newName;
	clients->Data.Patronymic = newPatronymic;
	clients->Data.Address = newAddress;
	clients->Data.PhoneNum = "+7" + newPhoneNum;
	clients->Data.PayDay = newPayDay;
	clients->Data.Summ = newSumm;

	//(*counter)++;

	std::cout << "\n\tДобавлен \n" << "\n\tфамилия: " << newSurname
		<< "\n\tИмя: " << newName << "\n\tОтчество: " << newPatronymic
		<< "\n\tАдресс: " << newAddress << "\n\tНомер телефона: +7" << newPhoneNum
		<< "\n\tДень оплаты: " << newPayDay << "\n\tСумму покупки: " << newSumm;

	std::cout << "\n\n\tНажмите любую клавишу для возврата в меню... ";
	char p = _getch();
	std::system("cls");
};
//finished

void sortClients		(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для сортировки...";
		char p = _getch();
		system("cls");
		return;
	}
	if (clients == head && clients == tail) {
		std::cout << "\n\n\tМало данных клиентов для сортировки...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\tСортировать всех клиентов по\n";
	std::cout << "\n\t1. Фамилии\t2. Имя\t0.Выход\n\n\t";
	int inputNum;
	cin >> inputNum;
	clients = head;
	int counter = 1;
	person* temp = NULL;
	temp = new person;
	while (true) {
		counter++;
		clients = clients->next;
		if (clients == tail) break;
	}
	clients = head;
	std::system("cls");
	switch (inputNum) {
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
	case(1): {
		for (int i = 1; i < counter; i++) {
			clients = head;
			for (int j = 0; j < counter - i; j++) {
				if (clients->Data.Surname > clients->next->Data.Surname) {
					temp->Data = clients->Data;
					clients->Data = clients->next->Data;
					clients->next->Data = temp->Data;
				}
				clients = clients->next;
			}
		}
		std::cout << "\n\n\tСортировка по фамилии завершена, нажмите любую кдавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	case(2): {
		for (int i = 1; i < counter; i++) {
			clients = head;
			for (int j = 0; j < counter - i; j++) {
				if (clients->Data.Name > clients->next->Data.Name) {
					temp->Data = clients->Data;
					clients->Data = clients->next->Data;
					clients->next->Data = temp->Data;
				}
				clients = clients->next;
			}
		}
		std::cout << "\n\n\tСортировка по имени завершена, нажмите любую кдавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
//finished

void transform			(person*& head, person*& tail, person*& clients) {
	std::cout << "\n\n\tКакие данные изменить\n"
		<< "\n\t1. Фамилию - " << clients->Data.Surname
		<< "\n\t2. Имя - " << clients->Data.Name
		<< "\n\t3. Отчество - " << clients->Data.Patronymic
		<< "\n\t4. Адресс - " << clients->Data.Address
		<< "\n\t5. Телефонный номер - " << clients->Data.PhoneNum
		<< "\n\t6. День оплаты - " << clients->Data.PayDay
		<< "\n\t7. Сумму - " << clients->Data.Summ
		<< "\n\t0. Выход\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\tВведите Фамилию: ";		cin.get(); getline(cin, clients->Data.Surname); 	break; }
	case(2): {std::cout << "\n\n\tВведите Имя: ";			cin.get(); getline(cin, clients->Data.Name); 		break; }
	case(3): {std::cout << "\n\n\tВведите Отчество: ";		cin.get(); getline(cin, clients->Data.Patronymic);	break; }
	case(4): {std::cout << "\n\n\tВведите Адресс: ";		cin.get(); getline(cin, clients->Data.Address); 	break; }
	case(5): {std::cout << "\n\n\tВведите Телефонный: ";	cin.get(); getline(cin, clients->Data.PhoneNum); 	break; }
	case(6): {std::cout << "\n\n\tВведите День: ";			cin.get(); getline(cin, clients->Data.PayDay);		break; }
	case(7): {std::cout << "\n\n\tВведите Сумму: ";			cin.get();		   cin >> clients->Data.Summ;		break; }
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
void transformClients	(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для изменения...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\tИзменить данные клиента\n\n\t\tПоиск по \n\n\t1. ФИО\t2. Счёту в базе\t0. Выход\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\tВведите Фамилию или Имя или Отчество. 0. Выход\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int searchID = -1;
		int couErr = 0;
		int id = 1;
		while (true) {
			if (clients->next == NULL) break;
			if (inputStr == clients->Data.Surname) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Name) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic) { searchID = id; couErr++; }
			clients = clients->next;
			id++;
		}
		if (couErr > 1) {
			std::cout << "\n\n\tНайдено более одного клиента, введите дргуие даннные клиента. Нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID - 1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\tИзменить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(head, tail, clients); return; }
			case(2): { return; }
			default: {
				std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
				char p = _getch();
				std::system("cls");
				return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\tВведите номер в базе. 0. Выход\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0) { std::system("cls"); return; }
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\tИзменить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(head, tail, clients); return; }
		case(2): { return; }
		default: {
			std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return; }
		}
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return; }
	}

	std::system("cls");
}
//finished

void swapAndDelClients	(person*& head, person*& tail, person*& clients) {
	if (clients != head && clients != tail) {
		clients->prev->next = clients->next;
		clients->next->prev = clients->prev;
	}
	else if (clients == head && clients != tail) {
		head = clients->next;
		head->prev = NULL;
	}
	else if (clients == tail && clients != head) {
		tail = clients->prev;
		tail->next = NULL;
	}
	else {
		head = NULL;
		tail = NULL;
	}
	delete clients;
}
void delClients			(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для удаления...";
		char p = _getch();
		system("cls");
		return;
	}
	clients = head;
	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}
	std::cout << "\n\tУдалить данные клиента\n\n\t\tПоиск по \n\n\t1. ФИО\t2. Счёту в базе\t0. Выход\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\tВыход"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\tВведите Фамилию или Имя или Отчество. 0. Выход\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int id = 1;
		int searchID = -1;
		int couErr = 0;
		while (true) {
			if (inputStr == clients->Data.Surname) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Name) { searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic) { searchID = id; couErr++; }
			if (clients == tail) break;
			clients = clients->next;
			id++;
		}
		if (couErr > 1) {
			std::cout << "\n\n\tНайдено более одного клиента, введите дргуие даннные клиента. Нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			std::cout << "\n\n\tУдалить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {
				swapAndDelClients(head, tail, clients);
				std::cout << "\n\n\tУспешно удалено, нажмите любую клавишу для выхода в меню... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			case(2): { return; }
			default: {
				std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			}
		}
	}
	case(2): {
		std::cout << "\n\n\tВведите номер в базе. 0. Выход\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		clients = head;
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\tУдалить данные клиента " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. Да\t2. Нет\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {
			swapAndDelClients(head, tail, clients);
			std::cout << "\n\n\tУспешно удалено, нажмите любую клавишу для выхода в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		case(2): { return; }
		default: {
			std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		}
	}
	default: {
		std::cout << "\n\n\tВведено неверное значение, нажмите любую клавишу для возврата в меню... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	}
	clients = head;
std::system("cls");
}
//finished

void showClients(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для вывода...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\tВывести список клиентов\n\n";

	int maxLenSurname = 7;
	int maxLenName = 3;
	int maxLenPatronymic = 8;
	int maxLenAddress = 15;
	int maxLenPhoneNum = 16;
	int maxLenPayDay = 11;
	int maxLenSumm = 13;

	int maxSumm = 0;

	clients = head;
	while (true) {
		int LenSurname = clients->Data.Surname.length();
		int LenName = clients->Data.Name.length();
		int LenPatronymic = clients->Data.Patronymic.length();
		int LenAddress = clients->Data.Address.length();
		int LenPhoneNum = clients->Data.PhoneNum.length();
		int LenPayDay = clients->Data.PayDay.length();
		int LenSumm = 0;
		int Summ = clients->Data.Summ;
		int g = 0;
		while (Summ > 0) { Summ /= 10; LenSumm++; }
		maxSumm += clients->Data.Summ;

		if (LenSurname > maxLenSurname) { maxLenSurname = LenSurname; }
		if (LenName > maxLenName) { maxLenName = LenName; }
		if (LenPatronymic > maxLenPatronymic) { maxLenPatronymic = LenPatronymic; }
		if (LenAddress > maxLenAddress) { maxLenAddress = LenAddress; }
		if (LenPhoneNum > maxLenPhoneNum) { maxLenPhoneNum = LenPhoneNum; }
		if (LenPayDay > maxLenPayDay) { maxLenPayDay = LenPayDay; }
		if (LenSumm > maxLenSumm) { maxLenSumm = LenSumm; }
		if (clients == tail) break;
		clients = clients->next;
	}
	clients = head;
	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic
		+ maxLenAddress + maxLenPhoneNum + maxLenPayDay + maxLenSumm + 22;



	std::cout << "\t";
	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname, "Фамилия",
		maxLenName, "Имя",
		maxLenPatronymic, "Отчество",
		maxLenAddress, "Домашний адресс",
		maxLenPhoneNum, "Телефонный номер",
		maxLenPayDay, "День оплаты",
		maxLenSumm, "Сумма покупки");
	std::cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << "\n";

	while (true) {
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname, clients->Data.Surname.c_str(),
			maxLenName, clients->Data.Name.c_str(),
			maxLenPatronymic, clients->Data.Patronymic.c_str(),
			maxLenAddress, clients->Data.Address.c_str(),
			maxLenPhoneNum, clients->Data.PhoneNum.c_str(),
			maxLenPayDay, clients->Data.PayDay.c_str(),
			maxLenSumm, clients->Data.Summ
		);

		std::cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
		std::cout << endl;
		if (clients->next == NULL) break;
		clients = clients->next;
	}
	clients = head;
	std::cout << "\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	printf_s("| %*d |", maxLenSumm, maxSumm); std::cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	for (int i = 0; i < maxLenPayDay + 6; i++) { std::cout << "-"; }


	std::cout << "\n\tНажмите любую клавишу для возврата в меню... "; char p = _getch(); std::system("cls");
	std::system("cls");
}
//finished

void show(person*& clients) {
	std::cout << "\n\n\tФИО: " << clients->Data.Surname << " " << clients->Data.Name << " " << clients->Data.Patronymic << " Адресс: "
		<< clients->Data.Address << "\n\tТелефоный номер: " << clients->Data.PhoneNum << " День оплаты: " << clients->Data.PayDay << " Сумма: " << clients->Data.Summ;
}
void searchClients(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для поиска...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\tПоиск клиента по базе";
	std::cout << "\n\n\tВведите Фамилию или Имя или Отчество\t0. Выход\n\n\t";
	string inputStr;
	cin >> inputStr;
	std::system("cls");
	if (inputStr == "0") { return; }
	clients = head;
	bool searchID = false;
	while (true) {
		if (clients->next == NULL) break;
		if (inputStr == clients->Data.Surname) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Name) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Patronymic) { searchID = true; show(clients); }
		clients = clients->next;
	}
	clients = head;
	if (searchID == true) { std::cout << "\n\n\tНажмите любую клавишу что-бы вернуться в меню... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == false) { std::cout << "\n\n\tКлиент не найден, нажмите любую клавишу что-бы вернуться в меню... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}
//finished

void saveClients(person*& head, person*& tail, person*& clients)
{
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\tНет данных клиентов для сохранения...";
		char p = _getch();
		system("cls");
		return;
	}
	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. Сохранить в файле с названием " << INDIVID_OUTPUT_FILE_LOCATION
		<< " с исходным кодом\n\t2. Изменить название файла\n\t0. Выход\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\tНажмите любую клавишу...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {
		ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);
		clients = head;
		while (true) {
			outClients << "ФИО: " << clients->Data.Surname << " " << clients->Data.Name << " "
				<< clients->Data.Patronymic << " Адресс: " << clients->Data.Address << " Номер тел.: "
				<< clients->Data.PhoneNum << " День оплаты: " << clients->Data.PayDay << " Сумма: "
				<< clients->Data.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\tСохраненов файле " << INDIVID_OUTPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}
	case(2): {
		std::cout << "\n\n\tВведите навание выходного файла (без расширения, используя только буквы): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ofstream outClients(newName);
		clients = head;
		while (true) {
			outClients << "ФИО: " << clients->Data.Surname << " " << clients->Data.Name << " "
				<< clients->Data.Patronymic << " Адресс: " << clients->Data.Address << " Номер тел.: "
				<< clients->Data.PhoneNum << " День оплаты: " << clients->Data.PayDay << " Сумма: "
				<< clients->Data.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\tСохранено в файле " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}
	default: {
		std::cout << "\n\n\tВведено невенрое значение...";
		char p = _getch();
		break;
	}
	}
}
//finished

void downloadClients(person*& head, person*& tail, person*& clients) {
	string defaultFileName = (INDIVID_INPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. Загрузтиь из файла с названием " << INDIVID_INPUT_FILE_LOCATION
		<< " с исходным кодом\n\t2. Изменить название файла\n\t0. Выход\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\tНажмите любую клавишу...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {

		ifstream inClients(INDIVID_INPUT_FILE_LOCATION);

		if (inClients.bad()) {
			std::cout << "\n\tОшибка ввода-вывода при чтении...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\tДостигнут конец файла...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\tНеверный формат данных...";
			char p = _getch();
			system("cls");
			return;
		}

		int size = 0;
		inClients >> size;

		for (int i = 0; i < size; i++) {
			if (clients == NULL) {
				clients = new person;
				head = clients;
				tail = clients;
			}
			else {
				clients = tail;
				clients->next = new person;
				clients->next->prev = clients;
				clients = clients->next;
				tail = clients;
			}
			inClients.get();
			getline(inClients, clients->Data.Surname);
			getline(inClients, clients->Data.Name);
			getline(inClients, clients->Data.Patronymic);
			getline(inClients, clients->Data.Address);
			getline(inClients, clients->Data.PhoneNum);
			getline(inClients, clients->Data.PayDay);
			inClients >> clients->Data.Summ;
		}

		std::cout << "\n\n\tЗагруженно из файле " << INDIVID_INPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}
	case(2): {
		std::cout << "\n\n\tВведите навание выходного файла (без расширения, используя только буквы): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ifstream inClients(newName);

		if (inClients.bad()) {
			std::cout << "\n\tОшибка ввода-вывода при чтении...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\tДостигнут конец файла...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\tНеверный формат данных...";
			char p = _getch();
			system("cls");
			return;
		}

		int size = 0;
		inClients >> size;

		clients = new person;
		head = clients;

		for (int i = 0; i < size; i++) {
			if (clients == NULL) {
				clients = new person;
				head = clients;
			}
			else {
				clients = clients->next = new person;
				tail = clients;
			}
			inClients.get();
			getline(inClients, clients->Data.Surname);
			getline(inClients, clients->Data.Name);
			getline(inClients, clients->Data.Patronymic);
			getline(inClients, clients->Data.Address);
			getline(inClients, clients->Data.PhoneNum);
			getline(inClients, clients->Data.PayDay);
			inClients >> clients->Data.Summ;
		}

		std::cout << "\n\n\tЗагруженно из файле " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}
	default: {
		std::cout << "\n\n\tВведено невенрое значение...";
		char p = _getch();
		break;
	}
	}
}
//finished
*/

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
			#pragma region restore_stdin
				/*int old;
				FILE* DataFile;

				old = _dup(0);   // "old" now refers to "stdin"   
								   // Note:  file descriptor 0 == "stdin"   
				if (old == -1)
				{
					perror("_dup( 1 ) failure");
					exit(1);
				}

				if (fopen_s(&DataFile, "input.txt", "r") != 0)
				{
					puts("Can't open file 'data'\n");
					exit(1);
				}

				// stdin now refers to file "data"   
				if (-1 == _dup2(_fileno(DataFile), 0))
				{
					perror("Can't _dup2 stdin");
					exit(1);
				}
				int n;
				cin >> n;
				cout << n << std::endl;

				_flushall();
				fclose(DataFile);*/
			#pragma endregion
				//int old;
				//old = _dup(0);
				//int savestdin = _fileno(stdin);
				//_dup2(_fileno(stdout), 0);

				//#pragma warning(suppress : 4996) savestdin = dup(savestdin);

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
				
				// Restore original stdin 
				//_flushall();
				//#pragma warning(suppress : 4996) stdout = _dup2(old, 0);

				
				//system("cls");

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