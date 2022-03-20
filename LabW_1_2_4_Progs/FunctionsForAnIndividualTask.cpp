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
	std::cout << "\n\n\t���������� �������\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	int		newSumm = 0;

	std::cout << "\n\t������� ������ �������\n";
	std::cout << "\n\t�������: "; 	cin.get();		std::getline(cin, newSurname);
	std::cout << "\n\t���: ";						std::getline(cin, newName);
	std::cout << "\n\t��������: ";					std::getline(cin, newPatronymic);
	std::cout << "\n\t������: ";					std::getline(cin, newAddress);
	std::cout << "\n\t����� �������� (��� +7): ";	std::getline(cin, newPhoneNum);
	std::cout << "\n\t���� ������ (��.��.����): ";	std::getline(cin, newPayDay);
	std::cout << "\n\t����� �������: ";				cin >> newSumm;
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

		std::cout << "\n\t�������� \n" << "\n\t�������: " << newSurname
			<< "\n\t���: " << newName << "\n\t��������: " << newPatronymic
			<< "\n\t������: " << newAddress << "\n\t����� ��������: +7" << newPhoneNum
			<< "\n\t���� ������: " << newPayDay << "\n\t����� �������: " << newSumm;

		std::cout << "\n\n\t������� ����� ������� ��� �������� � ����... ";
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

	std::cout << "\n\t�������� \n" << "\n\t�������: " << newSurname
		<< "\n\t���: " << newName << "\n\t��������: " << newPatronymic
		<< "\n\t������: " << newAddress << "\n\t����� ��������: +7" << newPhoneNum
		<< "\n\t���� ������: " << newPayDay << "\n\t����� �������: " << newSumm;

	std::cout << "\n\n\t������� ����� ������� ��� �������� � ����... ";
	char p = _getch();
	std::system("cls");
};
//finished

void sortClients(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\t��� ������ �������� ��� ����������...";
		char p = _getch();
		system("cls");
		return;
	}
	if (clients == head && clients == tail) {
		std::cout << "\n\n\t���� ������ �������� ��� ����������...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\t����������� ���� �������� ��\n";
	std::cout << "\n\t1. �������\t2. ���\t0.�����\n\n\t";
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
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
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
		std::cout << "\n\n\t���������� �� ������� ���������, ������� ����� ������� ��� �������� � ����... ";
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
		std::cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		return;
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
//finished

void transform(person*& head, person*& tail, person*& clients) {
	std::cout << "\n\n\t����� ������ ��������\n"
		<< "\n\t1. ������� - " << clients->Data.Surname
		<< "\n\t2. ��� - " << clients->Data.Name
		<< "\n\t3. �������� - " << clients->Data.Patronymic
		<< "\n\t4. ������ - " << clients->Data.Address
		<< "\n\t5. ���������� ����� - " << clients->Data.PhoneNum
		<< "\n\t6. ���� ������ - " << clients->Data.PayDay
		<< "\n\t7. ����� - " << clients->Data.Summ
		<< "\n\t0. �����\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\t������� �������: ";		cin.get(); getline(cin, clients->Data.Surname); 	break; }
	case(2): {std::cout << "\n\n\t������� ���: ";			cin.get(); getline(cin, clients->Data.Name); 		break; }
	case(3): {std::cout << "\n\n\t������� ��������: ";		cin.get(); getline(cin, clients->Data.Patronymic);	break; }
	case(4): {std::cout << "\n\n\t������� ������: ";		cin.get(); getline(cin, clients->Data.Address); 	break; }
	case(5): {std::cout << "\n\n\t������� ����������: ";	cin.get(); getline(cin, clients->Data.PhoneNum); 	break; }
	case(6): {std::cout << "\n\n\t������� ����: ";			cin.get(); getline(cin, clients->Data.PayDay);		break; }
	case(7): {std::cout << "\n\n\t������� �����: ";			cin.get();		   cin >> clients->Data.Summ;		break; }
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
		char p = _getch();
		std::system("cls");
		break; }
	}
	std::system("cls");
}
void transformClients(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\t��� ������ �������� ��� ���������...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\t�������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
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
			std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID - 1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(head, tail, clients); return; }
			case(2): { return; }
			default: {
				std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
				char p = _getch();
				std::system("cls");
				return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0) { std::system("cls"); return; }
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(head, tail, clients); return; }
		case(2): { return; }
		default: {
			std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return; }
		}
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
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
		std::cout << "\n\n\t��� ������ �������� ��� ��������...";
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
	std::cout << "\n\t������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
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
			std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID == -1) {
			std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		if (searchID >= 0) {
			std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {
				swapAndDelClients(head, tail, clients);
				std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			case(2): { return; }
			default: {
				std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
				char p = _getch();
				std::system("cls");
				return;
			}
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		clients = head;
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {
			swapAndDelClients(head, tail, clients);
			std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		case(2): { return; }
		default: {
			std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
			char p = _getch();
			std::system("cls");
			return;
		}
		}
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... ";
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
		std::cout << "\n\n\t��� ������ �������� ��� ������...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\n\t������� ������ ��������\n\n";

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
		maxLenSurname, "�������",
		maxLenName, "���",
		maxLenPatronymic, "��������",
		maxLenAddress, "�������� ������",
		maxLenPhoneNum, "���������� �����",
		maxLenPayDay, "���� ������",
		maxLenSumm, "����� �������");
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


	std::cout << "\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");
	std::system("cls");
}
//finished

void show(person*& clients) {
	std::cout << "\n\n\t���: " << clients->Data.Surname << " " << clients->Data.Name << " " << clients->Data.Patronymic << " ������: "
		<< clients->Data.Address << "\n\t��������� �����: " << clients->Data.PhoneNum << " ���� ������: " << clients->Data.PayDay << " �����: " << clients->Data.Summ;
}
void searchClients(person*& head, person*& tail, person*& clients) {
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\t��� ������ �������� ��� ������...";
		char p = _getch();
		system("cls");
		return;
	}
	std::cout << "\n\t����� ������� �� ����";
	std::cout << "\n\n\t������� ������� ��� ��� ��� ��������\t0. �����\n\n\t";
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
	if (searchID == true) { std::cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == false) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}
//finished

void saveClients(person*& head, person*& tail, person*& clients)
{
	if (tail == NULL && head == NULL) {
		std::cout << "\n\n\t��� ������ �������� ��� ����������...";
		char p = _getch();
		system("cls");
		return;
	}
	string defaultFileName = (INDIVID_OUTPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. ��������� � ����� � ��������� " << INDIVID_OUTPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\t������� ����� �������...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {
		ofstream outClients(INDIVID_OUTPUT_FILE_LOCATION);
		clients = head;
		while (true) {
			outClients << "���: " << clients->Data.Surname << " " << clients->Data.Name << " "
				<< clients->Data.Patronymic << " ������: " << clients->Data.Address << " ����� ���.: "
				<< clients->Data.PhoneNum << " ���� ������: " << clients->Data.PayDay << " �����: "
				<< clients->Data.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\t���������� ����� " << INDIVID_OUTPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}
	case(2): {
		std::cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ofstream outClients(newName);
		clients = head;
		while (true) {
			outClients << "���: " << clients->Data.Surname << " " << clients->Data.Name << " "
				<< clients->Data.Patronymic << " ������: " << clients->Data.Address << " ����� ���.: "
				<< clients->Data.PhoneNum << " ���� ������: " << clients->Data.PayDay << " �����: "
				<< clients->Data.Summ << endl;
			if (clients == tail) break;
			clients = clients->next;
		}
		std::cout << "\n\n\t��������� � ����� " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������...";
		char p = _getch();
		break;
	}
	}
}
//finished

void downloadClients(person*& head, person*& tail, person*& clients) {
	string defaultFileName = (INDIVID_INPUT_FILE_LOCATION);
	std::cout << "\n\n\t1. ��������� �� ����� � ��������� " << INDIVID_INPUT_FILE_LOCATION
		<< " � �������� �����\n\t2. �������� �������� �����\n\t0. �����\n\n\t";
	int inNum;
	cin >> inNum;
	system("cls");
	switch (inNum) {
	case(0): {
		std::cout << "\n\n\t������� ����� �������...";
		char p = _getch();
		system("cls");
		break;
	}
	case(1): {

		ifstream inClients(INDIVID_INPUT_FILE_LOCATION);

		if (inClients.bad()) {
			std::cout << "\n\t������ �����-������ ��� ������...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\t��������� ����� �����...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\t�������� ������ ������...";
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

		std::cout << "\n\n\t���������� �� ����� " << INDIVID_INPUT_FILE_LOCATION << "...";
		char p = _getch();
		system("cls");
		break;
	}
	case(2): {
		std::cout << "\n\n\t������� ������� ��������� ����� (��� ����������, ��������� ������ �����): ";
		string newName;
		cin.get();
		getline(cin, newName);
		newName += ".txt";
		system("cls");
		ifstream inClients(newName);

		if (inClients.bad()) {
			std::cout << "\n\t������ �����-������ ��� ������...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.eof()) {
			std::cout << "\n\t��������� ����� �����...";
			char p = _getch();
			system("cls");
			return;
		}
		else if (inClients.fail()) {
			std::cout << "\n\t�������� ������ ������...";
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

		std::cout << "\n\n\t���������� �� ����� " << newName << "...";
		char p = _getch();
		system("cls");
		break;
	}
	default: {
		std::cout << "\n\n\t������� �������� ��������...";
		char p = _getch();
		break;
	}
	}
}
//finished