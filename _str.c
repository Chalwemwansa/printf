#include "main.h"

/**
 * str - function  prints string to stdout.
 * @string: gives list.
 * Return: numbers of char on success.
 */

int str(va_list string)
{
	int l;
	char *str;

	str = va_arg(string, char *);

	if (str == NULL)
		str = "(null)";
	l = 0;

	while (str[l] != '\0')
		l = l + _putchar(str[l]);
	return (l);
}
