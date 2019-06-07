#include "pch.h"
#include<iostream>
#include<fstream>  
//горизонтальный градиент
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;
struct tmp { float r; float g; float b; } t; //tmp  для w
struct tmpH { float r; float g; float b; } th; // tmp для h

void swap(unsigned char &a, unsigned char &b) {
	a += b;
	b = a - b;
	a = a - b;
}

int main() {
	ifstream fff("D:\\1.bmp", ios::binary);
	ofstream ggg("D:\\rez.bmp", ios::binary);
	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << "No file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c;
	tmp t;
	tmpH th;
	unsigned int w, h;

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18); 
	fff.read((char *)&w, 4); cout << "w=" << w; 
	fff.read((char *)&w, 4); cout << ", h=" << w;
	w = 512; ggg.write((char *)&w, 4);
	h = 256; ggg.write((char *)&h, 4);
	fff.read((char *)&buf, 28);
	ggg.write((char *)&buf, 28);

	c.r = 200; //первый цвет градиента
	c.g = 10;
	c.b = 10;

	unsigned char rr = 10; //второй цвет градиента
	unsigned char gg = 200;
	unsigned char bb = 200;

	float step = 520; // количество шагов

	swap(c.r, rr);
	swap(c.g, gg);
	swap(c.b, bb);
	float stepR = ((float)rr - c.r) / step;
	float stepG = ((float)gg - c.g) / step;
	float stepB = ((float)bb - c.b) / step;
	int kk = 0;
	int jj = 0;
	t.r = (float)c.r;
	t.g = (float)c.g;
	t.b = (float)c.b;

	th.r = (float)c.r;
	th.g = (float)c.g;
	th.b = (float)c.b;
	int tmp{ 0 };
	for (int i = 1; i <= h; ++i) {
		if (jj < step) {
			th.g += stepG;
			th.r += stepR;
			th.b += stepB;
			c.r = (unsigned char)th.r;
			c.g = (unsigned char)th.g;
			c.b = (unsigned char)th.g;
			jj++;
		}
		t.r = c.r;
		t.g = c.g;
		t.b = c.b;
		jj = i - 1;
		kk = i - 1;
		for (int j = 1; j <= w; ++j) {
			if (kk < step) {
				t.g += stepG;
				t.r += stepR;
				t.b += stepB;
				c.r = (unsigned char)t.r;
				c.g = (unsigned char)t.g;
				c.b = (unsigned char)t.b;
				kk++;
			}
			ggg.write((char *)&c, 3);
		}

	}

	fff.close();
	ggg.close();
	return 1;
}
