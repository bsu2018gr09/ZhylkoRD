#include"pch.h"
#include<iostream> 
#include<fstream> 
//горизонтальный градиент
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream fff("d:\\1.bmp", ios::binary);
	ofstream ggg("d:\\rez.bmp", ios::binary);

	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << " file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c1, c2;
	c1.r = 255, c1.g = 255, c1.b = 255;
	c2.r = 0, c2.g = 0, c2.b = 0;
	color c;
	unsigned int w, h;
	unsigned int move;
	int cnt{ 0 };

	fff.read((char *)&buf, 18);
	ggg.write((char *)&buf, 18); 

	fff.read((char *)&w, 4);
	fff.read((char *)&w, 4);

	w = 128;
	ggg.write((char *)&w, 4); 
	h = 256;
	move = w / 1.5;
	ggg.write((char *)&h, 4);	
	fff.read((char *)&buf, 28); 
	ggg.write((char *)&buf, 28); 

	c.r = c1.r; c.g = c1.g; c.b = c1.b;
	double dr = abs(c2.r - c1.r) / move;
	double dg = abs(c2.g - c1.g) / move;
	double db = abs(c2.b - c1.b) / move;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (cnt < move) {
				c.b = c.b + db;
				c.g = c.g + dg;
				c.r = c.r + dr;
				++cnt;
			}
			ggg.write((char *)&c, 3); 
		}
		c.r = c1.r;
		c.g = c1.g;
		c.b = c1.b;
		cnt = 0;
	}
	fff.close();
	ggg.close();

	return 1;
}
