#include<iostream>
#include<time.h>
#include <iomanip>
#include <math.h>

using namespace std;

int *memoryAllocation(int);

void randomInitArray(int *, int *, int);

void printArray(int *, int);

void deleteMemory(int *, int *);

void d(int *, int *, int *, int, int, int, int);

int sortArr(int *, int);



int main() {
    srand(time(0));
    int N;
    cout << "Enter N" << '\n';
    cin >> N;
    cout << "Enter A, B, C" << '\n';
    int A1, B1, C;
    cin >> A1 >> B1 >> C;
    int *A = memoryAllocation(N);
    int *B = memoryAllocation(N);
    int *D = memoryAllocation(N);
    randomInitArray(A,B, N);
    printArray(A, N);
    d(A,B,D,A1,B1 ,C ,N);
    printArray(B, N);
    sortArr(D, N);
    printArray(D, N);
    deleteMemory(A, B);
}

void d(int *X, int *Y, int *D,int a, int b, int c, int N){
    for (int i(0); i < N; i++) {
         *(D + i) = abs(*(X + i) + *(Y + i) + c) / sqrt(a * a + b * b);
    }
}

int sortArr(int *D, int N){//плохо! Как в первом семестре. Нам надо переставлять не элементы, а строки целеком
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - i - 1; j++) {
                if (*(D + j) > *(D + j + 1)) {
                    swap(*(D + j), *(D + j + 1));
                }
            }
        }
};

int *memoryAllocation(int N) {
    int *Arr = new(nothrow) int[N];
    if (!Arr) {
        cout << "error" << "\n";
    }
    return Arr;
}

void randomInitArray(int *A, int *B, int N) {
    for (int i(0); i < N; ++i) {
        *(A + i) = rand() % 21 - 10;
        *(B + i) = rand() % 21 - 10;
    }
}

void printArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        cout << *(A + i) << ";";
        cout << "     ";
    }
    cout << "\n";

}

void deleteMemory(int *A, int *B) {
    A = nullptr;
    delete[] A;
    B = nullptr;
    delete[] B;
}
