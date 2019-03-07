//В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.

#include<iostream>
#include<ctime>


using namespace std;

void initArrayByRandom(int* , int, int);
void countIdentialElements(int* , int);
void printArray(int* , int);
void eraseArray(int*);


int main() {
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
	countIdentialElements(A, N);

	eraseArray(A);

	system("pause");
	return 0;
}


void initArrayByRandom(int* A, int N, int b) {
	for (int i{ 0 }; i < N; ++i) {
		*(A + i) = rand() % b;
	}
}

void countIdentialElements(int* A, int N) {
	int* B = new (nothrow) int[N];
	if (!B) {
		system("pause");
	}
	int cnt{ 0 };
	for (int i = 0; i < N; ++i) {
		*(B + i) = *(A + i);
	}
	for (int i = 0; i < N; ++i) {
		cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (*(B + j) == *(A + i)) {
				++cnt;
			}
		}
		cout << "Элемент " << *(A + i) << " встречается " << cnt << " раз\n";
	}
	delete B;
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