#include "main.h"

/**
 * handle_print - Prints an argument according to its own type.
 * @fmt:Gives a format of  string in which to print the arguments.
 * @list:Gives a list of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffers array to handle print.
 * @flags: Does the Calculation of active flags.
 * @width: gets width of function.
 * @precision:Gives the Precision specifications.
 * @size: Gives size of specifier.
 * Return: either 1 or 2;
 */

int handlePrint(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int k, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', pChar}, {'s', pString}, {'%', pPercent},
		{'i', pInt}, {'d', pInt}, {'b', pBinary},
		{'u', pUnsigned}, {'o', pOctal}, {'x', pHexadecimal},
		{'X', pHexaUpper}, {'p', pPointer}, {'S', printNonPrintable},
		{'r', pReverse}, {'R', pRot13string}, {'\0', NULL}
	};
	for (k = 0; fmt_types[k].fmt != '\0'; k++)
		if (fmt[*ind] == fmt_types[k].fmt)
			return (fmt_types[k].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[k].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

