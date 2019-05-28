#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//Определить, сколько слов в строке состоит только из цифр. Вывести такие слова на экран и удалить после них следующее слово.
using namespace std;
const int maxLength{ 255 };
const char *stopSymbols = " -,.;";
const char *digits = "0123456789";
void giveMemory(char *&);
void freeMemory(char *&);
int countDigitWords(char *);
int findStopSymbolId(char *, int);
bool isWordDigit(char *, int, int);
void printSubstring(char *, int, int);
void subStr(char *, char *, int, int);

int main() {
	setlocale(LC_ALL, "Russian");
	char *str = nullptr;
	cout << "Enter string" << '\n';
	giveMemory(str);
	cin.getline(str, maxLength);
	cout << "Количество слов " << countDigitWords(str);
	freeMemory(str);
}

void giveMemory(char *&str) {
	str = new(nothrow) char[maxLength];
	if (!str) {
		cout << "Error\n";
	}
}

void freeMemory(char *&str) {
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
	char *str2 = nullptr, *tmp = nullptr;
	giveMemory(str2);
	giveMemory(tmp);
	strcpy(str2, "");
	cout << "Слова, состоящие из цифр:\n";
	while (end < maxLength&&end != -1) {
		if (isWordDigit(str, start, end) == true) {
			++cnt;
			printSubstring(str, start, end);
			subStr(str, tmp, start, end + 1);
			strcat(str2, tmp);
			cout << "\n";
		}
		start = end + 1;
		end = findStopSymbolId(str, start);
	}
	if (cnt == 0) {
		cout << "Нет таких слов";
	}
	strcpy(str, str2);
	cout << "Строка после удаления слов: " << str2 << "\n";
	freeMemory(str2);
	return cnt;
}

void subStr(char *s, char *rez, int begin, int end){
	int cnt = end - begin;
	s = s + begin;
	strncpy(rez, s, cnt);
	rez[cnt] = '\0';
}

int findStopSymbolId(char *str, int start) {
	bool isFound = false;
	char c;
	int i;
	while (!isFound&&start < maxLength) {
		c = str[start];
		for (i = 0; i < 5; ++i) {
			if (c == stopSymbols[i] || c == '\0') {
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
