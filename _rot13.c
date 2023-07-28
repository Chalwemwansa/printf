#include "main.h"

/**
 * _rot13 - function prints the rot13 version.
 * @rot: gives the list being passed.
 * Return: count of chars on success.
 */

int _rot13(va_list rot)
{
	int a, c;
	char *s;

	a = c = 0;
	s = va_arg(rot, char *);

	if (s == NULL)
		return (-1);
	while (s[a] != '\0')
	{
		if ((s[a] >= 'a' && s[a] <= 'z') ||
		    (s[a] >= 'A' && s[a] <= 'Z'))
		{
			if ((s[a] >= 'n' && s[a] <= 'z') ||
			    (s[a] >= 'N' && s[a] <= 'Z'))
				c = c + _putchar(s[a] - 13);
			else
				c = c + _putchar(s[a] + 13);
		}
		else
			c = c + _putchar(s[a]);
		a++;
	}
	return (c);
}
