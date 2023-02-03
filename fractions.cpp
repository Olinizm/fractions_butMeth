#include <iostream>
#include "fractions.h"

//greatest common divisor
int NWD(int a, int b)
{
	int smaller = (a > b) ? b : a;
	for (int i = 2; i <= smaller; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			return NWD(a / i, b / i) * i;
		}
			
	}
	return 1;
}


int fr_error(std::string message)
{
	std::cerr << message;
	return 1;
}

//section .CONSTRUCTORS
Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int n)
{
	numerator = n;
	denominator = 1;
}
Fraction::Fraction(int n, int d)
{
	numerator = n;
	if (d == 0) fr_error("invalid denominator value");
	else denominator = d;
}
Fraction::~Fraction()
{

}

void Fraction::fr_print()
{
	std::cout << numerator << " / " << denominator;
}

void fr_print(Fraction f)
{
	std::cout << f.numerator << " / " << f.denominator;
}

void Fraction::reducefr()
{
	Fraction cp(numerator, denominator);
	numerator /= NWD(numerator, denominator);
	denominator /= NWD(cp.numerator, cp.denominator);
}

//section .INCREMENTATION .DECREMENTATION
Fraction& Fraction::operator++ ()
{
	numerator += denominator;
	return *this;
}
Fraction Fraction::operator++ (int)
{
	Fraction tmp(numerator, denominator);
	numerator += denominator;
	return tmp;
}
Fraction& Fraction::operator-- ()
{
	numerator -= denominator;
	return *this;
}
Fraction Fraction::operator-- (int)
{
	Fraction tmp(numerator, denominator);
	numerator -= denominator;
	return tmp;
}

Fraction& Fraction::operator=(Fraction a)
{
	numerator = a.numerator;
	denominator = a.denominator;
	return *this;
}

//section .ADDITION
Fraction Fraction::operator+(Fraction a)
{
	Fraction f(numerator, denominator);
	if (denominator == a.denominator)
	{
		f.numerator += a.numerator;
		return f;
	}
	else
	{
		f.numerator *= a.denominator;
		f.denominator *= a.denominator;
		a.numerator *= denominator;
		f.numerator += a.numerator;
	}
	f.reducefr();
	return f;
}
Fraction Fraction::operator+(int a)
{
	Fraction f(numerator, denominator);
	f.numerator += denominator * a;
	return f;
}

//section .SUBSTRACTION
Fraction Fraction::operator-(Fraction a)
{
	Fraction f(numerator, denominator);
	if (denominator == a.denominator)
	{
		f.numerator -= a.numerator;
		return f;
	}
	else
	{
		f.numerator *= a.denominator;
		f.denominator *= a.denominator;
		a.numerator *= denominator;
		f.numerator -= a.numerator;
	}
	f.reducefr();
	return f;
}
Fraction Fraction::operator-(int a)
{
	Fraction f(numerator, denominator);
	f.numerator -= denominator * a;
	return f;
}

//section .MULTIPLICATION
Fraction Fraction::operator*(Fraction a)
{
	Fraction f(numerator, denominator);
	f.numerator *= a.numerator;
	f.denominator *= a.denominator;
	f.reducefr();
	return f;
}
Fraction Fraction::operator*(int a)
{
	Fraction f(numerator, denominator);
	f.numerator *= a;
	f.reducefr();
	return f;
}

//section .DIVISION
Fraction Fraction::operator/(Fraction a)
{
	Fraction f(numerator, denominator);
	f.numerator *= a.denominator;
	f.denominator *= a.numerator;
	f.reducefr();
	return f;
}
Fraction Fraction::operator/(int a)
{
	Fraction f(numerator, denominator);
	f.denominator *= a;
	f.reducefr();
	return f;
}