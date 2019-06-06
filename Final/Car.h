#pragma once
#ifndef Car_H
#define Car_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

template <class T>
T* giveMemory(int n)
{
	T *arr = new (nothrow) T[n];
	if (!arr)
	{
		cout << "Can't give memory";
		exit(0);
	}
	return arr;
}

template <class T>
void freeMemory(T*& arr)
{
	free(arr);
	arr = nullptr;
}

class Car {
private:
	char *name;
	char *model;
	int year;
	int color;
	int cost;
public:
	Car() : model{ giveMemory<char>(5) }, name{ giveMemory<char>(5) }, year{ 2010 }, cost{ 1000 }, color{ 0 }
	{
		strcpy(model, "null");
		strcpy(name, "null");
	}

	Car(char* _model, char * _name, int _year, int _cost, int _color) :model{ giveMemory<char>(strlen(_model) + 1) }, name{ giveMemory<char>(strlen(_name) + 1) }, year{ _year }, cost{ _cost }, color{ _color }
	{
		strcpy(model, _model);
		strcpy(name, _name);
	}

	Car(Car const &tmp) : model{ tmp.model }, name{ tmp.name }, year{ tmp.year }, cost{ tmp.color }, color{ tmp.color } {};

	~Car()
	{
		freeMemory<char>(name);
		freeMemory<char>(model);
	}

	void SetYear(int tmp) {
		year = tmp;
	}

	void SetCost(int tmp) {
		cost = tmp;
	}

	void SetColor(int tmp) {
		color = tmp;
	}

	void SetModel(char* tmp) {
		strcpy(model, tmp);
	}

	void SetName(char* tmp) {
		strcpy(name, tmp);
	}

	int GetYear() {
		return year;
	}

	int GetCost() {
		return cost;
	}

	int GetColor() {
		return color;
	}

	char* GetModel() {
		return model;
	}

	char* GetName() {
		return name;
	}

	friend std::ostream& operator<<(std::ostream& os, Car const &t) {
		os << "Model: " << t.model << " Name: " << t.name << " Year: " << t.year << " Cost: " << t.cost << " Color: " << t.color << "\n";
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Car &t) {
		std::cout << "Model: ";
		is >> t.model;
		std::cout << "Name: ";
		is >> t.name;
		std::cout << "Year: ";
		is >> t.year;
		std::cout << "Cost: ";
		is >> t.cost;
		std::cout << "Color: ";
		is >> t.color;
		std::cout << "\n";
		return is;
	}
};

#endif