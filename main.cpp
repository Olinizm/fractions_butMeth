#include <iostream>
#include "fractions.h"

int main()
{
	Fraction f(1, 1), a(1, 2);
	f = a + 1;
	f.fr_print();
	f++;
	f.fr_print();
}