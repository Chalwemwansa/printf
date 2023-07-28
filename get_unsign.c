#include "main.h"

/**
 * _ui - unsigned int print to stdout.
 * @unsign:gives list being passed.
 * Return: char count on succes.
 */

int _ui(va_list unsign)
{
	unsigned int n;
	int e = 1;
	int l = 0;

	n = va_arg(unsign, unsigned int);

	while (n / e > 9)
		e *= 10;
	while (e != 0)
	{
		l = l + _putchar(n / e + '0');
		n = n % e;
		e = e / 10;
	}
	return (l);
}
