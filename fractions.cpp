#include <iostream>
#include "fractions.h"

int fr_error(std::string message)
{
	std::cerr << message;
	return 1;
}

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
	if (denominator == 0) fr_error("invalid denominator value");
	else denominator = d;
}

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
		a.numerator *= f.denominator;
		a.denominator *= f.denominator;
		f.numerator += a.numerator;
	}
	return f;
}
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
		a.numerator *= f.denominator;
		a.denominator *= f.denominator;
		f.numerator -= a.numerator;
	}
	return f;
}
Fraction Fraction::operator*(Fraction a)
{

}