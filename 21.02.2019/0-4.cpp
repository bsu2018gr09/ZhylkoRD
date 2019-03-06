// Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.

#include <iostream>
#include <ctime>

using namespace std;

void initArrayByRandom(int*, int, int);
void printArray(int*, int);
void eraseArray(int*);
void sortFromElement(int*, int, int);

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

	int k;
	cout << "С какого элемента отсортировать массив?";
	cin >> k;
	k = k % N;
	sortFromElement(A, N, k);
	printArray(A, N);

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

void sortFromElement(int* A, int N, int k) {
	for (int i = k; i < N - 1; i++) {
		for (int j = k; j < N - i - 1 + k; j++) {
			if (*(A + j) > *(A + j + 1)) {
				swap(*(A + j), *(A + j + 1));
			}
		}
	}
}