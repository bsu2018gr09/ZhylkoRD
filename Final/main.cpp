#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

using namespace std;

Car* initArrayFromFile(int &count);
void writeToFile(Car *arr, int n);
void printArray(Car *arr, int n);
void expandArraySize(Car *&arr, int &size, int add);
void changeRecord(Car *&arr, int size, int n);
void deleteRecord(Car *&arr, int &size, int n);
int findOldCars(Car *arr, int n, Car *&rez, int year);
int findExpensiveCar(Car *arr, int n, Car *rez);
void sort(Car *&arr, int start, int end);
int sortCarsByYear(Car *arr, int n, Car *&rez, char* model);
void initByRandom(Car *&arr, int n, int cnt);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	bool saved = true;
	int cntFile, cntLocal, localSize;
	Car *arrFile = initArrayFromFile(cntFile);
	Car *arrLocal = initArrayFromFile(cntLocal);
	localSize = cntLocal;
	while (1) {
		cout << "\n1-Вывести записи из файла; 2-Вывести локальные записи; 3-Сделать запись;\n";
		cout << "4-Редактировать запись; 5-Удалить запись; 6-Сохранить; 7-Функции; 8-Выйти\n\n";
		cin >> n;
		switch (n) {
		case 1:
			printArray(arrFile, cntFile);
			break;
		case 2:
			printArray(arrLocal, cntLocal);
			break;
		case 3:
			cout << "\n1-Вручную; 2-Рандомом; 3-В меню\n";
			cin >> n;
			int cnt;
			if (n == 1) {
				cout << "Введите количество: ";
				cin >> cnt;
				if (cnt + cntLocal > localSize) {
					expandArraySize(arrLocal, localSize, cnt);
				}
				for (int i{ cntLocal }; i < cntLocal + cnt; ++i)
					cin >> arrLocal[i];
				cntLocal += cnt;
				printArray(arrLocal, cntLocal);
				saved = false;
			}
			else if (n == 2) {
				cout << "Введите количество: ";
				cin >> cnt;
				if (cnt + cntLocal > localSize) {
					expandArraySize(arrLocal, localSize, cnt);
				}
				initByRandom(arrLocal, cntLocal, cnt);
				cntLocal += cnt;
				printArray(arrLocal, cntLocal);
				saved = false;
			}
			else {
				break;
			}
			break;
		case 4:
			int nmb;
			cout << "\nВведите номер записи, которую хотите отредактировать ";
			cin >> nmb;
			changeRecord(arrLocal, cntLocal, nmb);
			saved = false;
			break;
		case 5:
			int nbr;
			cout << "\nВведите номер записи, которую хотите удалить ";
			cin >> nbr;
			deleteRecord(arrLocal, cntLocal, nbr);
			saved = false;
			break;
		case 6:
			writeToFile(arrLocal, cntLocal);
			arrFile = initArrayFromFile(cntLocal);
			saved = true;
			break;
		case 7:
			int func;
			cout << "\nВыберите функцию:\n";
			cout << "1-Список машин старше введенного года\n";
			cout << "2-Машина с максимальной стоимостью\n";
			cout << "3-Список машин заданной марки по году выпуска\n";
			cin >> func;
			if (func == 1) {
				int year;
				cout << "Введите год: ";
				cin >> year;
				Car *rez = giveMemory<Car>(cntLocal);
				int oldCars = findOldCars(arrLocal, cntLocal, rez, year);
				printArray(rez, oldCars);
				cout << "\nНажмите 1, чтобы записать список в файл ";
				cin >> year;
				if (year == 1) {
					writeToFile(rez, oldCars);
					arrFile = initArrayFromFile(cntFile);
					arrLocal = initArrayFromFile(cntLocal);
				}
			}
			else if (func == 2) {
				cout << "Список машин с наибольшей стоимостью:\n";
				Car *rez = giveMemory<Car>(cntLocal);
				int expCars = findExpensiveCar(arrLocal, cntLocal, rez);
				printArray(rez, expCars);
				int wrt;
				cout << "\nНажмите 1, чтобы записать список в файл ";
				cin >> wrt;
				if (wrt == 1) {
					writeToFile(rez, expCars);
					arrFile = initArrayFromFile(cntFile);
					arrLocal = initArrayFromFile(cntLocal);
				}
			}
			else if (func == 3) {
				cout << "Список машин заданной марки по году выпуска:\n";
				cout << "Введите марку машины: ";
				Car *rez = giveMemory<Car>(cntLocal);
				char *model = giveMemory<char>(100);
				cin >> model;
				int cars = sortCarsByYear(arrLocal, cntLocal, rez, model);
				printArray(rez, cars);
				int wrt;
				cout << "\nНажмите 1, чтобы записать список в файл ";
				cin >> wrt;
				if (wrt == 1) {
					writeToFile(rez, cars);
					arrFile = initArrayFromFile(cntFile);
					arrLocal = initArrayFromFile(cntLocal);
				}
			}
			break;
		case 8:
			if (saved) {
				exit(0);
			}
			else {
				cout << "\nВы не сохранили изменения, сохранить?";
				cout << "\n1-сохранить, 2 - выйти\n";
				int ex;
				cin >> ex;
				if (ex == 1) {
					writeToFile(arrLocal, cntLocal);
					exit(0);
				}
				else
					exit(0);
			}
			break;
		}
	}
}


