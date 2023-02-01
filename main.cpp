#include <iostream>
#include "fractions.h"

int main()
{
	Fraction f(1, 1), a(1, 2);
	f = a;
	f.fr_print();
}