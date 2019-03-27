#include <iostream>
#include <string>

using namespace std;
const int maxLength{ 255 };
const string stopSymbols = " -,.;";
const string digits = "0123456789";
void giveMemory(char *&);
void deleteMemory(char *&);
int countDigitWords(char *);
void deleteWord(char *&, int, int);
int findStopSymbolId(char *, int);
bool isWordDigit(char *, int, int);
void printSubstring(char *, int, int);


int main() {
	setlocale(LC_ALL, "Russian");
	char *str = nullptr;
	cout << "Enter string" << '\n';

	giveMemory(str);
	cin.getline(str, maxLength);
	cout<<"Количество слов "<<countDigitWords(str);
	deleteMemory(str);
}

void giveMemory(char *&str) {
	str = new(nothrow) char[maxLength];
	if (!str) {
		cout << "Error\n";
	}
}

void deleteMemory(char *&str) {
	delete[] str;
	str = nullptr;
}

void printSubstring(char *str, int start, int end) {
	for (int i{ start }; i < end; ++i) {
		cout << str[i];
	}
}

int countDigitWords(char *str) {
	int start{ 0 };
	int end = findStopSymbolId(str, 0);
	int cnt{ 0 };
	cout << "Слова, состоящие из цифр:\n";
	while(end < maxLength&&end!=-1) {
		if (isWordDigit(str, start, end) == true) {
			++cnt;
			printSubstring(str, start, end);
			cout << "\n";
		}
		start = end + 1;
		end = findStopSymbolId(str, start);
	}
	if (cnt == 0) {
		cout << "Нет слов";
	}
	return cnt;
}

int findStopSymbolId(char *str, int start) {
	bool isFound = false;
	char c;
	int i;
	while (!isFound&&start < maxLength) {
		c = str[start];
		for (i = 0; i < 5; ++i) {
			if (c == stopSymbols[i]||c == '\0') {
				isFound = true;
				break;
			}
		}
		++start;
	}
	if (!isFound) {
		return -1;
	}
	else {
		return --start;
	}
}

bool isWordDigit(char *str, int start, int end) {
	int i, j, cnt;
	char c;
	bool isDigit = true;
	for (i = start; i < end; ++i) {
		c = str[i];
		cnt = 0;
		for (j = 0; j < 10; ++j) {
			if (c == digits[j]) {
				++cnt;
			}
		}
		if (!cnt) {
			isDigit = false;
			break;
		}
	}
	return isDigit;
}

void deleteWord(char*& str, int start, int end) {
	
}

