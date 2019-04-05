#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <iterator>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

const size_t N = 5000;

void readFile(char*, char**);
void findEquals(char**, int);

int main() {
	setlocale(LC_ALL, "Russian");

	char **A = new (nothrow) char*[N];
	if (!A) {
		cout << "No memory";
		exit(1);
	}
	readFile("D:\\.txt", A);
}


void readFile(char* filename, char **A)
{
	char* tmp;
	char* buffer = new (nothrow) char[N];

	if (!buffer) {
		cout << "Can't create buffer";
		exit(1);
	}

	ifstream file(filename);

	if (!file)
	{
		cout << "Can't open file " << filename << "\n";
		exit(1);
	}

	int cnt{ 0 };

	while (1) {
		file.getline(buffer, N - 1);
		if (file.fail()) {
			file.clear();
		}

		tmp = strtok(buffer, ".");
		while (tmp != 0) {
			A[cnt] = tmp;
			++cnt;
			tmp = strtok(0, ".");
		}
		if (file.eof()) {
			break;
		}
	}


	file.close();
	findEquals(A, cnt);
}	

void findEquals(char** A, int cnt) {
	char* tmp;
	char **words = new (nothrow) char*[100];
	int wordsCnt{ 0 }, j{ 0 }, l{ 0 };

	ofstream outputFile("D:\\.txt");
	if (!outputFile)
	{
		cout << "Can't create file " << "D:\.txt" << "\n";
		exit(1);
	}

	for (int i{ 0 }; i < cnt; ++i) {
		tmp = strtok(A[i], " ,-");
		wordsCnt = 0;
		while (tmp != 0) {
			words[wordsCnt] = tmp;
			++wordsCnt;
			tmp = strtok(0, " ,-");
			if (tmp == 0) {
				break;
			}
		}
		for (j = 0; j < wordsCnt; ++j) {
			for (l = j + 1; l < wordsCnt; ++l) {
				if (_stricmp(words[j] ,words[l])==0) {
					outputFile << A[i] << "\n";
					break;
				}
			}
		}
	}
	outputFile.close();
}

