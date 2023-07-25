#include "main.h"
/**
 * printPointer - prints the value of a pointer variable
 *
 * Return: an integer
 * @types: variable used
 * @str: variable used
 * @flag: variable used
 * @width: variable used
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int printPointer(va_list types, char str[],
			int flag, int width, int precision, int size)
{
char extraC = 0, padding = ' ', char mapTo[];
int index = 1022, l = 2, paddStart = 1;
unsigned long numAddress;
void *address = va_arg(types, void *)

mapTo = "0123456789abcdef";
(void)width;
(void)size;
(void)precision;
if (address == NULL)
	return (write(1, "(nil)", 5));
str[1023] = '\0';
numAddress = (unsigned long)address;
while (numAddress > 0)
}
	str[index--] = mapTo[numAddress % 16];
	numAddress /= 16;
	l++;
}
if ((flag & 4) && !(flag & 1))
	padding = '0';
if (flag & 2)
	extraC = '+', length++;
else if (flag & 16)
	extraC = ' ', length++;
index++;
return (writePointer(str, index, l, width, flag, padding, extraC, paddStart));

}
/**
 * printNonPrintable - prints non printable
 *
 * Return: an integer
 * @types: variable used in the code
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int printNonPrintable(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *string = va_arg(types, char *);

	(void)flag;
	(void)width;
	(void)precision;
	(void)size;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (string[i] != '\0')
	{
		if (isPrintable(string[i]))
			str[i + offset] = string[i];
		else
			offset += appendHexaCode(string[i], str, i + offset);
		i++;
	}
	str[i + offset] = '\0';
	return (write(1, str, i + offset));
}
/**
 * printReverse - prints a string in reverse
 *
 * Return: returns an integer
 * @types: variable used in the code
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int printReverse(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	char *string;
	int i, c = 0, j;
	char z;

	(void)str;
	(void)flag;
	(void)width;
	(void)size;
	(void)precision;

	string = va_arg(types, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; string[i]; i++)
		for (j = i - 1; j >= 0; j--)
		{
			z = string[i];
			write(1, &z, 1);
			c++;
		}
	return (c);
}
/**
 * printRot13string - prints a string
 *
 * Return: an integer
 * @types: variable used in the code
 * @str: variable used
 * @flag: variable used in the code
 * @width: variable used in the project
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int printRot13string(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	char x;
	char *string;
	unsigned int i, j;
	int c = 0;
	char p[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char exit[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	(void)str;
	(void)flag;
	(void)width;
	(void)precision;
	(void)size;
	if (string == NULL)
		str = "Error";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; p[j]; j++)
		{
			if (p[j] == string[i])
			{
			x = exit[j];
			write(1, &x, 1);
			c++;
			break;
			}
		}
		if (!p[j])
		{
		x = string[i];
		write(1, &x, 1);
		c++;
		}
	}
	return (c);
}
