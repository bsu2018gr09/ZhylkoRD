// В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.

#include <iostream>
#include <ctime>

using namespace std;

void initArrayByRandom(int* , int, int);
void printArray(int* , int);
void eraseArray(int*);
int findMaxIdentialElementsLength(int* , int);

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

	initArrayByRandom(A, N, 10);
	printArray(A, N);
	cout << findMaxIdentialElementsLength(A, N);

	eraseArray(A);

	system("pause");
	return 0;
}

void initArrayByRandom(int* A, int N, int b) {
	for (int i{ 0 }; i < N; ++i) {
		*(A + i) = rand() % b;
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

int findMaxIdentialElementsLength(int* A, int N) {
	int max{ 0 }, cnt{ 1 };
	for (int i{ 0 }; i < N - 1; ++i) {
		if (*A == *(A + 1)) {
			++cnt;
		}
		else {
			if (cnt > max) {
				max = cnt;
			}
			cnt = 1;
		}
		++A;
	}
	if (cnt > max) {
		max = cnt;
	}
	return max;
}