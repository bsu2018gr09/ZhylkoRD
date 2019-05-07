#include<iostream>
#include<time.h>

using namespace std;

int *memoryAllocation(int);

void randomInitArray(int *, int);

void printArray(int *, int);

void deleteMemory(int *);

void shiftPositive(int *, int);//очень медленно. Никакой оптимизации ((

void shiftArray(int *, int, int &);//очень медленно. Никакой оптимизации ((

void shiftNegative(int *, int, int &);//очень медленно. Никакой оптимизации ((

int main() {
    srand(time(0));
    int N;
    cin >> N;
    int *A = memoryAllocation(N);
    randomInitArray(A, N);
    printArray(A, N);
    shiftPositive(A, N);
    printArray(A, N);
    deleteMemory(A);
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
        *(A + i) = rand() % 21 - 10;
    }
}

void printArray(int *A, int N) {
    for (int i(0); i < N; ++i) {
        cout << *(A + i) << ";";
        cout << "     ";
    }
    cout << "\n";

}

void shiftPositive(int *A, int N) {
    int k = 0;
    for (int i(0); i < N; ++i) {
        if (*(A + i) >= 0) {
            swap(*(A + i), *(A + k));
            ++k;
        }
    }
    shiftArray(A, N, k);
    shiftNegative(A, N, k);
}

void shiftNegative(int *A, int N, int &k) {
    int l = 1, j, i;
    while (l) {
        l = 0;
        for (i = 0, j = 1; j < k; ++i, ++j) {
            if (*(A + i) < *(A + j)) {
                swap(*(A + i), *(A + j));
                l = 1;
            }
        }
    }
}

void shiftArray(int *A, int N, int &k) {
    k = N - k;
    for (int i(0), j = N - 1; i < N / 2; ++i, --j) {
        swap(*(A + i), *(A + j));
    }
    for (int i(0), j = k - 1; i < k / 2; ++i, --j) {
        swap(*(A + i), *(A + j));
    }
    for (int i(k), j = N - 1; i < (N - k) / 2 + k; ++i, --j) {
        swap(*(A + i), *(A + j));
    }
}

void deleteMemory(int *A) {
    A = nullptr;
    delete[] A;
}
