#include "main.h"

/**
 * get_precision - Sums up the precision for printing output.
 * @format: Gives the format string in which to print the arguments.
 * @k: Gives a list of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision on success.
 */

int gPrecision(const char *format, int *k, va_list list)
{
	int curr_k = *k + 1;
	int precision = -1;

	if (format[curr_k] != '.')
		return (precision);

	precision = 0;

	for (curr_k += 1; format[curr_k] != '\0'; curr_k++)
	{
		if (isDigit(format[curr_k]))
		{
			precision *= 10;
			precision += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (precision);
}

