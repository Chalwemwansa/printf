#include "main.h"
/**
 * print_stdout - prints to standard output
 *
 * @str: the string to be printed out
 * @i: represents the length of the string
 * Return: nothing
 */
void print_stdout(char *str, int *i)
{
	if (*i > 0)
		write(1, &str[0], *i);
	*i = 0;
}
/**
 * _printf - prints a string
 *
 * @format: the string passed which nedds to be printed
 * @...: symbolises an unknown number of arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, pChar = 0, flag, width, size, sIndex = 0, precision;
	char str[1024];
	va_list arg;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg, format);
	for  (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			print_stdout(str, &sIndex);
			flag = gFlag(format, &i);
			width = gWidth(format, &i, arg);
			precision = gPrecision(format, &i, arg);
			size = gSize(format, &i);
			++i;
			printed = hPrint(format, &i, arg, str, flag, width, precision, size);
			if (printed == -1)
				return (-1);
			pChar += printed;
		}
		else
		{
			str[sIndex++] = format[i];
			if (sIndex == 1024)
				print_stdout(str, &sIndex);
			pChar++;
		}
	}
	print_stdout(str, &sIndex);
	va_end(arg);
	return (pChar);
}
