#define _CRT_SECURE_NO_WARNINGS
#ifndef Car_CPP
#define Car_CPP
#include "Car.h"
#include <ctime>
#include <iomanip>
#include <fstream>
#include <iostream>

char file[] = "D:\\aaa.txt";

Car* initArrayFromFile(int &count) {
	int cnt{ 0 };
	char *tmp = giveMemory<char>(200);
	std::ifstream fff(file);

	while (1) {
		fff >> tmp;
		++cnt;
		if (fff.eof())
			break;
	}
	cnt /= 5;
	count = cnt;
	fff.close();
	Car *arr = giveMemory<Car>(cnt);
	std::ifstream fff2(file);
	int year, color, cost;
	char *model = giveMemory<char>(200), *name = giveMemory<char>(200);
	for (int i{ 0 }; i < cnt; ++i) {
		fff2 >> model; arr[i].SetModel(model);
		fff2 >> name; arr[i].SetName(name);
		fff2 >> year; arr[i].SetYear(year);
		fff2 >> cost; arr[i].SetCost(cost);
		fff2 >> color; arr[i].SetColor(color);
	}
	fff2.close();
	freeMemory(model);
	freeMemory(name);
	freeMemory(tmp);
	return arr;
}

void writeToFile(Car *arr, int n) {
	std::ofstream fff(file, std::ios::trunc);
	for (int i{ 0 }; i < n; ++i)
		fff << arr[i].GetModel() << " " << arr[i].GetName() << " " << arr[i].GetYear() << " " << arr[i].GetCost() << " " << arr[i].GetColor() << "\n";
	fff.close();
}

void printArray(Car *arr, int n) {
	std::cout << "***********************************************\n";
	std::cout << "*   Модель | Владелец |  Год  |  Цена  | Цвет *\n";
	std::cout << "***********************************************\n";
	for (int i{ 0 }; i < n; ++i) {
		std::cout << "* " << std::setw(8) << arr[i].GetModel() << " | " << std::setw(8) << arr[i].GetName() << " | " << std::setw(5) << arr[i].GetYear() << " | " << std::setw(6) << arr[i].GetCost() << " | " << std::setw(3) << arr[i].GetColor() << "  *\n";
	}
	std::cout << "***********************************************\n";
}

void expandArraySize(Car *&arr, int &size, int add) {
	int tmp = size;
	if (size == 0)
		size = 1;
	while (size < tmp + add)
		size *= 2;
	Car *newArr = giveMemory<Car>(size);
	for (int i{ 0 }; i < tmp; ++i) {
		newArr[i].SetModel(arr[i].GetModel());
		newArr[i].SetName(arr[i].GetName());
		newArr[i].SetYear(arr[i].GetYear());
		newArr[i].SetCost(arr[i].GetCost());
		newArr[i].SetColor(arr[i].GetColor());
	}
	arr = giveMemory<Car>(size);
	for (int i{ 0 }; i < tmp; ++i) {
		arr[i].SetModel(newArr[i].GetModel());
		arr[i].SetName(newArr[i].GetName());
		arr[i].SetYear(newArr[i].GetYear());
		arr[i].SetCost(newArr[i].GetCost());
		arr[i].SetColor(newArr[i].GetColor());
	}
	freeMemory(newArr);
}


void changeRecord(Car *&arr, int size, int n) {
	if (n < size) {
		Car *tmp = giveMemory<Car>(1);
		std::cin >> tmp[0];
		arr[n] = tmp[0];
		freeMemory(tmp);
	}
}

void deleteRecord(Car *&arr, int &size, int n) {
	for (int i{ n + 1 }; i < size; ++i) {
		arr[n] = arr[n + 1];
	}
	if (n < size)
		size -= 1;
}

int findOldCars(Car *arr, int n, Car *&rez, int year) {
	int cnt{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		if (arr[i].GetYear() >= year) {
			rez[cnt] = arr[i];
			++cnt;
		}
	}
	return cnt;
}

int findExpensiveCar(Car *arr, int n, Car *rez) {
	int cnt{ 1 };
	int max{ arr[0].GetCost() };
	rez[0] = arr[0];
	for (int i{ 1 }; i < n; ++i) {
		if (arr[i].GetCost() > max) {
			rez[0] = arr[i];
			max = arr[i].GetCost();
			cnt = 1;
			continue;
		}
		if (arr[i].GetCost() == max) {
			rez[cnt] = arr[i];
			++cnt;
		}
	}
	return cnt;
}

void sort(Car *&arr, int start, int end) {
	int i = start, j = end;
	Car *tmp = giveMemory<Car>(1);
	Car pivot = arr[(start + end) / 2];
	while (i <= j) {
		while (arr[i].GetYear() < pivot.GetYear())
			i++;
		while (arr[j].GetYear() > pivot.GetYear())
			j--;
		if (i <= j) {
			tmp[0] = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp[0];
			i++;
			j--;
		}
	};
	if (start < j)
		sort(arr, start, j);
	if (i < end)
		sort(arr, i, end);
}

int sortCarsByYear(Car *arr, int n, Car *&rez, char* model) {
	int cnt{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		if (strcmp(arr[i].GetModel(), model) == 0) {
			rez[cnt] = arr[i];
			++cnt;
		}
	}
	sort(rez, 0, cnt - 1);
	return cnt;
}

void initByRandom(Car *&arr, int n, int cnt) {
	srand(time(0));
	char a[10][10] = { "Tesla" ,  "BMW" ,  "Nissan" ,  "Renault" ,  "Geely" ,  "Ford" ,  "Opel" ,  "KIA" ,  "Mazda" ,  "Volvo" };
	char b[10][10] = { "Ivanov", "Petrov", "Smit", "Sokolov","Kozlov","Vasil'ev","Johnson","Jones","Miller","Wilson" };
	for (int i{ n }; i < n + cnt; ++i) {
		arr[i].SetYear(rand() % 59 + 1960);
		arr[i].SetCost(rand() % 15000 + 1000);
		arr[i].SetColor(rand() % 10 + 1);
		arr[i].SetModel(a[rand() % 10]);
		arr[i].SetName(b[rand() % 10]);
	}
}
#endif