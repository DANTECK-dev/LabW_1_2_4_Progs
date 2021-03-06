
#define VER 2

#include "IndividualTask.h"

#include "FunctionsForAnIndividualTask.h"
#include "PersonStruct.h"
#include "ThisIs.h"

#include <iostream>
#include <conio.h>
#include <ctype.h>


using namespace std;

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
	Load,
	URL
};

void individualTask()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	person* head = NULL;
	person* tail = NULL;
	person* clients = NULL;

	///////	   ????    /////////

	while (true) {
		cout << "\n\t   ___ ___     ______    __  ___     __    __";
		cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		cout << "\n\t  ----== ??????? ????? ??????? ???????? ==----  ";
		cout << "\n\t       ----== 1. ????????  ??????? ==----       ";
		cout << "\n\t   ----== 2. ??????????? ???? ???????? ==----   ";
		cout << "\n\t    ----== 3. ???????? ?????? ??????? ==----    ";
		cout << "\n\t    ----== 4. ???????  ?????? ??????? ==----    ";
		cout << "\n\t    ----== 5. ??????? ?????? ???????? ==----    ";
		cout << "\n\t     ----== 6. ????? ??????? ?? ???? ==----     ";

#if VER == 2

		cout << "\n\t  ----== 7. ????????? ???  ?????? ? ????==----  ";
		cout << "\n\t   ----== 8. ????????? ?????? ?? ????? ==----   ";

#elif VER == 1

		cout << "\n\t----== 9.?????? ???????  ?????? ????????? ==----";
		cout << "\n\t----== ????? ????????? ?  ????????? ????? ==----";

#endif

		cout << "\n\t             ----== 0. ????? ==----             \n\t";

		char inputN;
		cin >> inputN;
		system("cls");
		int N = isInteger(inputN);
		//char k = isChar(inputN);

		clients = head;

		switch ((individualTaskMenu)N) {

			case individualTaskMenu::Exit:
				return;

			case individualTaskMenu::Add:
			{
				try
				{
					addClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				continue;
			}

			case individualTaskMenu::Sort:
			{
				try
				{
					sortClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				continue;
			}

			case individualTaskMenu::Transform:
			{
				try
				{
					transformClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				continue;
			}

			case individualTaskMenu::Del:
			{
				try
				{
					delClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				continue;
			}

			case individualTaskMenu::Show:
			{
				try
				{
					showClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				continue;
			}

			case individualTaskMenu::Search:
			{
				try
				{
					searchClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
					//break;
				}
				continue;
			}

#if VER == 2

			case individualTaskMenu::Save:
			{
				try
				{
					saveClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				continue;
			}

			case individualTaskMenu::Load:
			{
				try {
					downloadClients(head, tail, clients);
				}
				catch (const exception& err)
				{
					cout << "\n\t" << err.what() << " ... ";
					char p = _getch();
					system("cls");
				}
				continue;
			}

#elif VER == 1

			case individualTaskMenu::URL: {system("start pay.html"); break; }

#endif
			default: {
				throw exception("\n\t??????? ???????? ????????, ??????? ????? ??????? ??? ???????????... ");
			}

		}
	}
}