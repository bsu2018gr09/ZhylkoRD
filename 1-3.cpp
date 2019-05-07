#include<iostream>
#include<time.h>
#include <math.h>
#include <iomanip>

using namespace std;

int *memoryAllocation(int);

void randomInitArray(int *, int);

void printArray(int *, int);

void deleteMemory(int *);

bool isSimple (int);

void arrSort(int *, int);


int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int N;
    cin >> N;
    int *A = memoryAllocation(N);
    randomInitArray(A, N);
    printArray(A, N);
    arrSort(A, N);
    printArray(A, N);
    deleteMemory(A);

}

void arrSort(int *A, int N){
    for(int i(0); i < N ; i++) {
        if (isSimple (*(A + i))) {
            for (int j(0); j < N ; j++) {
                if (isSimple(*(A + j)) && *(A + i) < *(A + j)) {//это ж сколько раз проверяешь ты на "простоту" ((
                    swap(*(A + i), *(A + j));
                }
            }
        }
    }

}


bool isSimple (int a){
    if (a == 1 || a==0){
        return 0;
    }
    for (int j(2); j<=sqrt(a); j++){
        if (a % j == 0){
            return 0;
        }
    }
    return 1;
}



int *memoryAllocation(int N) {
    int *Arr = new(nothrow) int[N];
    if (!Arr) {
        cout << "error" << "\n";
    }
    return Arr;
}

void randomInitArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        *(A + i) = rand() % 20;
    }
}

void printArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        cout << setw(3) << *(A + i) << '|';

    }
    cout << "\n";

}

void deleteMemory(int *A) {
    A = nullptr;
    delete[] A;
}
