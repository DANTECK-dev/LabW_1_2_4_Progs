#pragma once

/*
	Структура «Покупатель»: Дата покупки; ФИО; домашний адрес; номер телефона; сумма
	покупки. Вычисляемое значение – общая сумма покупки.
*/
// 1 laba

/*
	1) Создание нового элемента массива структур (ввод его данных);
	2) Сортировка массива структур;
	3) Изменение заданной структуры (вводится номер элемента в массиве структур, и его
	данные изменяются на новые введенные пользователем данные);
	4) Удаление структуры из массива (можно удаляемому элементу массива присвоить
	значение последнего элемента и уменьшить количество элементов в массиве структур);
	5) Вывод на экран массива структур в виде таблицы. Также выводите вычисляемое
	значение по всему массиву, указанное в вашем варианте.
	6) Поиск в массиве структур по заданному параметру (самостоятельно выберите поле
	структуры и реализуйте поиск по нему). То есть это вывод, но только определенных данных.
*/
// 2 laba

/*
	Измените программу индивидуального задания прошлой лабораторной работы. Добавьте
	в меню выбора новые действия пользователя «Сохранение» и «Загрузка».
	Действие «Сохранение» должно выполнять сохранение в файл всех данных вашего
	списка. При этом пользователю должен предоставляться выбор: сохранить в файл по
	умолчанию (придумайте название, к примеру, list.data) или пользователь сам вводит название
	файла, в который нужно сохранить список.
	Действие «Загрузить» должно выполнять загрузку данных вашего списка (заполнять
	список) из файла в память программы. При этом пользователю также должен предоставляться
	выбор: загрузить из файла по умолчанию или пользователь сам вводит название файла, из
	которого нужно загрузить список
*/
// 3 laba

/*
	Внесите в готовую программу из предыдущей лабораторной работы следующие изменения:
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
	VER=1 блокировались возможности считывания и сохранения данных в файл.
	2. Полная версия (VER=2), позволяющая считывать данные с файла и с клавиатуры.
*/
// 4 laba

/*
	Внесите в готовую программу из предыдущей лабораторной работы следующие изменения:
	Вместо файла содержащего структуру данных у вас должен быть определен файл,
	содержащий класс списка.
	Класс должен включать в себя все необходимые для работы со списком элементы: функции
	по работе со списком и переменные-указатели на список. При этом переменные указатели
	должны быть недоступны извне, то есть, определены как private.
	По факту в главной функции будет создаваться объект класса списка, и вся работа со
	списком должна вестись только через его методы.
	Определите конструкторы списка. К примеру, пустой конструктор и конструктор
	принимающий данные для создания первого элемента списка. Также определите деструктор для
	списка (функция очистки списка).
	Сам класс должен быть определен в заголовочном файле (.h), однако реализация его методов
	должны быть вынесена в файл кода (.cpp).
	Функции по работе с файловой системой оставьте в отдельном файле 
*/
// 5 laba

void individualTask();