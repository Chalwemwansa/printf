#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * pChar - prints a character to std output
 *
 * @types: variable used in the code
 * @str: charcter used in the code
 * @flag: shows special exceptions
 * @width: the width of the numbers
 * @precision: girves the precision of floating numbers
 *@size: variable used in the code
*Return: returns an integer
 */
int pChar(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	char c;

	c = va_arg(types, int);
	return (handleWriteChar(c, str, flag, width, precision, size));
}
/**
 * pString - prints a string
 *
 * @types: list of arguments
 * @str: variable
 * @flag: variable
 * @width: variable
 * @precision: variable
 * @size: variable
 * Return: an integer
 */
int pString(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	int l = 0, i;
	char *string = va_arg(types, char *);

	(void)str;
	(void)size;
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[l] != '\0')
		l++;
	if (precision >= 0 && precision < l)
		l = precision;
	if (width > l)
	{
		if (flag & 1)
		{
			write(1, &string[0], l);
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], 1);
			return (width);
		}
	}
	return (write(1, string, l));
}
/**
 * pPercent - prints a percent sign
 *
 * @types: lists of arguments
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in th3 coode
 * @precision: variable usd in the code
 * @size: variable used in the code
 * Return: an integer
 */
int pPercent(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	(void)types;
	(void)str;
	(void)flag;
	(void)width;
	(void)precision;
	(void)size;
	return (write(1, "%%", 1));
}
/**
 * pInt - prints an integer
 *
 * Return: an integer
 * @types: variable used
 * @str: variable used
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used iin the code
 */
int pInt(va_list types, char str[],
			int flag, int width, int precision, int size)
{
int i = 1022;
int j = 0;
long int n = va_arg(types, long int);
unsigned long int num;

n = convertSizeNumber(n, size);
if (n == 0)
{
	str[i--] = '0';
}
str[1023] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
j = 0;
}
while (num > 0)
{
	str[i--] = (num % 10) + '0';
	num /= 10;
}
i++;
return (writeNumber(j, i, str, flag, width, precision, size));
}
/**
 * pBinary - prints a given  number in binary
 *
 * @types: variable used in the code
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 * Return: does not return anything
 */
int pBinary(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;
	char z;

	(void)str;
	(void)flag;
	(void)width;
	(void)precision;
	(void)size;
	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

