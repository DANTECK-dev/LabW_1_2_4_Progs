#include "FunctionsForAnIndividualTask.h"
#include "PersonStruct.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

#define INDIVID_INPUT_FILE_LOCATION		"Input_Clients.txt"
#define INDIVID_OUTPUT_FILE_LOCATION	"Output_Clients.txt"

void addClients(person*& head, person*& tail, person*& clients)
{
	std::cout << "\n\n\tДобавление клиента\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	int		newSumm = 0;

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

void sortClients(person*& head, person*& tail, person*& clients) {
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

void transform(person*& head, person*& tail, person*& clients) {
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
void transformClients(person*& head, person*& tail, person*& clients) {
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

void swapAndDelClients(person*& head, person*& tail, person*& clients) {
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
void delClients(person*& head, person*& tail, person*& clients) {
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
	/*while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
		tail = clients;
	}
	while (true) {
		if (clients->prev == NULL) break;
		clients = clients->prev;
		head = clients;
	}*/
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
		if (inputStr == clients->Data.Surname) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Name) { searchID = true; show(clients); }
		if (inputStr == clients->Data.Patronymic) { searchID = true; show(clients); }
		if (clients->next == NULL) break;
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