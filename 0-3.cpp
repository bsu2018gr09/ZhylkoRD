// Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N. Написать функцию циклического сдвига элементов массива вправо на k элементов.

#include <iostream>
#include <ctime>

using namespace std;

void initArrayOnInterval(int*, int, int);
void printArray(int*, int);
void eraseArray(int*);
void shiftRightArray(int*, int, int);
void reverseArray(int*, int, int, int);

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	int N;
	cout << "Введите размер массива ";
	cin >> N;

	int* A = new (nothrow) int[N];
	if (!A) {
		cout << "Память не выделилась";
		return 0;
	}

	int k;
	cout << "Введите на сколько сдвинуть массив ";
	cin >> k;
	k = k % N;
	initArrayOnInterval(A, N, 10);
	printArray(A, N);
	shiftRightArray(A, N, k);
	printArray(A, N);

	eraseArray(A);

	system("pause");
	return 0;
}

void initArrayOnInterval(int* A, int N, int n) {
	for (int i{ 0 }; i < N; ++i) {
		*(A + i) = rand() % (2 * n + 1) - n;
	}
}

void printArray(int* A, int N) {
	for (int i{ 0 }; i < N; ++i) {
		cout << *(A + i) << " ";
	}
	cout << "\n";
}

void eraseArray(int* A) {
	delete[]A;
	A = nullptr;
}

void shiftRightArray(int* A, int N, int k) {
	reverseArray(A, N, 0, N);
	reverseArray(A, N, 0, k);
	reverseArray(A, N, k, N);
}

void reverseArray(int *A, int N, int start, int end) {
	int tmp{ 0 };
	for (int i{ 0 }; i < (end - start) / 2; ++i) {
		tmp = *(A + (start + i));
		*(A + (start + i)) = *(A + (end - i - 1));
		*(A + (end - i - 1)) = tmp;
	}
}