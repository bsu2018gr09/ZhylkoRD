/* В массиве А(N,M) переставить столбцы так, чтобы столбец с максимальной суммой элементов стал первым,
 а остальные столбцы расположить в порядке возрастания элементов первой строки.*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void giveMemoryToArray(int **&, int, int);
void initArrayRandom(int **, int, int);
void outputArray(int **, int, int);
void swapColumns(int **, int, int, int);
void shuffleColumns(int **, int, int);
int countSum(int **, int, int);
void deleteMemory(int **&, int);

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));

	int N, M;
	cout << "Введите количество строк: ";
	cin >> N;
	cout << "Введите количество столбцов: ";
	cin >> M;
	int**A = nullptr;

	giveMemoryToArray(A, N, M);
	initArrayRandom(A, N, M);
	outputArray(A, N, M);
	shuffleColumns(A, N, M);
	deleteMemory(A, N);

	system("pause");
	return 0;
}
void giveMemoryToArray(int **&A, int N, int M) {
	A = new(nothrow)int*[N];
	if (!A) cout << "Не хватает памяти" << '\n';
	for (int i{ 0 }; i < N; ++i) {
		A[i] = new(nothrow)int[M];
		if (!A) cout << "Не хватает памяти" << '\n';
	}
}
void initArrayRandom(int **A, int N, int M) {
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			A[i][j] = rand()%20;
		}
	}
}
void outputArray(int**A, int N, int M) {
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cout << setw(3) << A[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int countSum(int **A, int col, int N) {
	int sum{ 0 };
	for (int i{ 0 }; i < N; ++i) {
			sum+=A[i][col];
	}
	return sum;
}

void swapColumns(int **A, int col1, int col2, int N) {
	for (int i{ 0 }; i < N; ++i) {
		swap(A[i][col1], A[i][col2]);
	}
}

void shuffleColumns(int **A, int N, int M) {
	int i, j, maxSum{ 0 }, maxSumNumber{ 0 }, currentSum{ 0 };

	for (i = 0; i < M; ++i) {
		currentSum = countSum(A, i, N);
		if (currentSum > maxSum) {
			maxSum = currentSum;
			maxSumNumber = i;
		}
	}

	if (maxSumNumber != 0) {
		swapColumns(A, 0, maxSumNumber, N);
	}


	for (i = 1; i < M - 1; ++i) {
		for (j = 1; j < M - i; ++j) {
			if (A[0][j] > A[0][j + 1]) {
				swapColumns(A, j, j + 1, N);
			}
		}
	}

	outputArray(A, N, M);
}

void deleteMemory(int **&A, int N) {
	for (int i{ 0 }; i < N; ++i) {
		delete[] * (A + i);
		*(A + i) = nullptr;
	}
	delete[] A;
	A = nullptr;
}
