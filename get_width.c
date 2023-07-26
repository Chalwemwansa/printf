#include "main.h"

/**
 * get_width - Does the Calculation for  width printing.
 * @format: Gives string in which to print the arguments.
 * @z: Gives a list of arguments to be printed.
 * @list:Gives a list of arguments.
 *
 * Return: width.
 */

int gWidth(const char *format, int *z, va_list list)
{
	int curr_z;
	int width = 0;

	for (curr_z = *z + 1; format[curr_z] != '\0'; curr_z++)
	{
		if (isDigit(format[curr_z]))
		{
			width *= 10;
			width += format[curr_z] - '0';
		}
		else if (format[curr_z] == '*')
		{
			curr_z++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*z = curr_z - 1;

	return (width);
}

