#include <iostream>
#include "fractions.h"

using namespace std;

int main()
{
	Fraction f(3,5);
	cout << "f = ";
	fr_print(f);

	Fraction tmp = f;
	cout << "\nf++ = ";
	fr_print(++tmp);

	tmp = f;
	cout << "\nf-- = ";
	fr_print(--tmp);

	Fraction a(2, 3), b(5, 6);
	cout << "\n\n";
	fr_print(a);
	cout << " + ";
	fr_print(b);
	cout << " = ";
	fr_print(a + b);

	a = Fraction(4, 9);
	b = Fraction(1, 6);
	cout << "\n\n";
	fr_print(a);
	cout << " - ";
	fr_print(b);
	cout << " = ";
	fr_print(a - b);

	a = Fraction(1, 6);
	b = Fraction(3, 4);
	cout << "\n\n";
	fr_print(a);
	cout << " * ";
	fr_print(b);
	cout << " = ";
	fr_print(a * b);

	a = Fraction(5, 4);
	b = Fraction(3, 2);
	cout << "\n\n(";
	fr_print(a);
	cout << ") / (";
	fr_print(b);
	cout << ") = ";
	fr_print(a / b);


}