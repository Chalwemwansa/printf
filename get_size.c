#include "main.h"

/**
 * get_size - Does the Calculation of the size to cast the argument.
 * @format:Gives the format string in which to print the arguments.
 * @j: Provides a list of arguments to be printed.
 *
 * Return: Precision on success.
 */

int gSize(const char *format, int *j)
{
	int curr_j = *j + 1;
	int size = 0;

	if (format[curr_j] == 'l')
		size = 2;
	else if (format[curr_j] == 'h')
		size = 1;

	if (size == 0)
		*j = curr_j - 1;
	else
		*j = curr_j;

	return (size);
}

