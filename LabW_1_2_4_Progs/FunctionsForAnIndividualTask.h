#pragma once
#define FUNCTIONSFORANINDIVIDUALTASK_H_
#include "FunctionsForAnIndividualTask.h"
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

using namespace std;

void addClients			(person*& head, person*& tail, person*& clients);
void sortClients		(person*& head, person*& tail, person*& clients);
void transformClients	(person*& head, person*& tail, person*& clients);
void delClients			(person*& head, person*& tail, person*& clients);
void showClients		(person*& head, person*& tail, person*& clients);
void searchClients		(person*& head, person*& tail, person*& clients);
void saveClients		(person*& head, person*& tail, person*& clients);
void downloadClients	(person*& head, person*& tail, person*& clients); 