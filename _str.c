#include "main.h"

/**
 * str - function  prints string to stdout.
 * @string: gives list.
 * Return: numbers of char on success.
 */

int str(va_list string)
{
	int len;
	char *str;

	str = va_arg(string, char *);

	if (str == NULL)
		str = "(null)";
	len = 0;

	while (str[len] != '\0')
		len = len + _putchar(str[len]);
	return (len);
}
