#pragma once
//is that what they call a self-documenting code?
class Fraction
{
	int numerator = 0;
	int denominator = 1;

public:
	Fraction();
	Fraction(int n); //constructor called when only one argument is given makes it a numerator
	Fraction(int n, int d); //constructor called for 2 values takes numerator and denominator in that order

	void fr_print(); //prints out the Fraction data in "numerator / denominator" form
	void reducefr(); //checks for the greatest common divisor, until the numbers can't be divided

	Fraction& operator++ (); //increases the numerator value by denominator value returns the Fraction object
	Fraction operator++ (int); //does the same as ++Fraction operator but returns the Fraction values

	Fraction& operator-- (); //substracts denominator value from the numerator returns the Fraction object
	Fraction operator-- (int); //does the same as --Fraction operator but returns the Fraction values

	Fraction& operator= (Fraction right); //assigns one fraction values to another
	Fraction operator+ (Fraction right); 
	/*
		if denominator is the same, adds the numerator values
		else first multiplies the numerators and denominators by oposing denominators
		then adds together multiplied numerators and calls reduce fraction function
	*/
	Fraction operator+ (int right); //adds to numerator the value returned by multipling denominator with passed int value
	Fraction operator- (Fraction right); //works like the +Fraction operator but substracts instead of adding values
	Fraction operator- (int right); //works like -int but substracts the value instead

	Fraction operator* (Fraction right); //multiplies numerators and denominators with each other
	Fraction operator* (int right); //multiplies numerator with the argument
	Fraction operator/ (Fraction right); //multiplies numinator with argument denominator and denominator with nominator
	Fraction operator/ (int right); //multiplies denominator with passed value
};