#include "main.h"

/**
 * _hex_str - function converts the number from base 10 to hex.
 * @n: gives the number to be converted.
 * @hex: gives base of 16 being passed.
 * @alpha: Char 'A' to 'F' or 'a' to 'f'.
 * Return: number of chars printed on success.
 */

int _hex_str(unsigned int n, unsigned int hex, char alpha)
{
	unsigned int a = n % hex;
	unsigned int b = n / hex;
	char c;

	if (a > 10)
		c = (a - 10) + alpha;
	else
		c = a + '0';
	if (b == 0)
	{
		return (_putchar(c));
	}
	if (b < hex)
	{
		if (b > 10)
			return (_putchar(b - 10 + alpha) + _putchar(c));
		return (_putchar(b + '0') + _putchar(c));
	}
	return (_hex_str(b, hex, alpha) + _putchar(c));
}

/**
 * _hex_l - function prints lower case hexa.
 * @hexa: argument recieved.
 * Return: number of char printed.
 */
int _hex_l(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'a'));
}

/**
 * _hex_u - function prints upper case hexa.
 * @hexa: has the argument recieved.
 * Return: no. of char to be  printed.
 */

int _hex_u(va_list hexa)
{
	return (_hex_str(va_arg(hexa, unsigned int), 16, 'A'));
}
