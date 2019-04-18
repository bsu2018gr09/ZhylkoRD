//смешанная дробь
#include "pch.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

class Fraction {
public:
	Fraction() : Ent{ 0 }, Numrt{ 0 }, Dentr{ 1 } { cout << "constructor 0\n"; }
	Fraction(int tmp1, int tmp2, int tmp3) : Ent{ tmp1 }, Numrt{ tmp2 }, Dentr{ tmp3 } {cout << "constructor 1\n"; };
	Fraction(int tmp1) : Ent{ tmp1 }, Numrt{ 0 }, Dentr{ 1 } {cout << "constructor 2\n"; };
	Fraction(Fraction const &tmp) : Ent{ tmp.Ent }, Numrt{ tmp.Numrt }, Dentr{ tmp.Dentr } { cout << "copy constructor 0\n"; };
	const Fraction& operator=(Fraction const &t);

	Fraction operator+(Fraction const t);
	Fraction operator-(Fraction const t);
	Fraction operator*(Fraction const t);
	Fraction operator/(Fraction const t);
	Fraction pow(Fraction const t, int n);

	friend ostream& operator<<(ostream& os, Fraction const &t);
	friend istream& operator>>(istream& is, Fraction &t);

	void SetEnt(int tmp) { Ent = tmp; }
	void SetNumrt(int tmp) { Numrt = tmp; }
	void SetDentr(int tmp) { Dentr = tmp; }
	int GetEnt() { return Ent; }
	int GetNumrt() { return Numrt; }
	int GetDentr() { return Dentr; }
	~Fraction() {
		cout << "Destructor\n";
	}
private:
	int Ent;
	int Numrt;
	int Dentr;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Fraction a{ 3,4,5 };
	Fraction b{ 41,52,63 };
	const Fraction e = 5;
	Fraction d = b - a;
	Fraction f = a / b;
	a = e;
	cin >> f;
	cout << e << "\n";
	cout << d << "\n";
	cout << f << "\n";
	cout << a << "\n";
	system("pause");
	return 0;
}

const Fraction& Fraction::operator=(Fraction const &t) {
	this->Ent = t.Ent;
	this->Numrt = t.Numrt;
	this->Dentr = t.Dentr;
	return t;
}

Fraction Fraction::operator+(Fraction const t) {
	Fraction tmp;
	tmp.Dentr = this->Dentr*t.Dentr;
	int tmpNumrt{ this->Numrt*t.Dentr + this->Dentr*t.Numrt };
	int tmpEnt{ tmpNumrt / tmp.Dentr };
	tmp.Ent = tmpEnt + this->Ent + t.Ent;
	tmp.Numrt = tmpNumrt - tmp.Dentr*tmpEnt;
	return tmp;
}

Fraction Fraction::operator-(Fraction const t) {
	Fraction tmp;
	int tmpNumrt{ (this->Ent*this->Dentr + this->Numrt)*t.Dentr - (t.Ent*t.Dentr + t.Numrt)*this->Dentr };
	int tmpDentr{ this->Dentr*t.Dentr };
	int tmpEnt{ tmpNumrt / tmpDentr };
	tmp.Ent = tmpEnt;
	tmp.Dentr = tmpDentr;
	tmp.Numrt = tmpNumrt - tmpDentr * tmpEnt;
	return tmp;
}

Fraction Fraction::operator*(Fraction const t) {
	Fraction tmp;
	int tmpNumrt{ (this->Ent*this->Dentr + this->Numrt) * (t.Ent*t.Dentr + t.Numrt) };
	int tmpDentr{ this->Dentr*t.Dentr };
	tmp.Ent = tmpNumrt / tmpDentr;
	tmp.Dentr = tmpDentr;
	tmp.Numrt = tmpNumrt - tmpDentr * tmp.Ent;
	return tmp;
}

Fraction Fraction::operator/(Fraction const t) {
	Fraction tmp;
	int tmpNumrt{ (this->Ent*this->Dentr + this->Numrt) * t.Dentr };
	int tmpDentr{ (t.Ent*t.Dentr + t.Numrt) * this->Dentr };
	tmp.Ent = tmpNumrt / tmpDentr;
	tmp.Dentr = tmpDentr;
	tmp.Numrt = tmpNumrt - tmpDentr * tmp.Ent;
	return tmp;
}

Fraction Fraction::pow(Fraction const t, int n) {
	Fraction tmp;
	int num{ t.Numrt + t.Ent*t.Dentr }, tmpNumrt{ num }, tmpDentr{ t.Dentr };
	for (int i{ 0 }; i < n - 1; ++i) {
		tmpNumrt *= num;
		tmpDentr *= t.Dentr;
	}
	tmp.Ent = tmpNumrt / tmpDentr;
	tmp.Dentr = tmpDentr;
	tmp.Numrt = tmpNumrt - tmpDentr * tmp.Ent;
	return tmp;
}

ostream& operator<<(ostream& os, Fraction const &t) {
	os << t.Ent << " " << t.Numrt << "/" << t.Dentr;
	return os;
}

istream& operator>>(istream& is, Fraction &t) {
	is >> t.Ent >> t.Numrt >> t.Dentr;
	return is;
}
