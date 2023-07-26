#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int isPrintable(char c)
{
if (c >= 32 && c < 127)
	return (1);
return (0);
}
/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 *      
 * Return: Always 3
 */
int appendHexaCode(char ascii_code, char buffer[], int i)
{
char mapTo[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
				ascii_code *= -1;

		buffer[i++] = '\\';
		buffer[i++] = 'x';
		buffer[i++] = mapTo[ascii_code / 16];
		buffer[i] = mapTo[ascii_code % 16];
		return (3);
}
/**
 *  * is_digit - Verifies if a char is a digit
 *   * @c: Char to be evaluated
 *    *
 *     * Return: 1 if c is a digit, 0 otherwise
 *      */
int isDigit(char c)
{
		if (c >= '0' && c <= '9')
					return (1);

			return (0);
}

/**
 *  * convert_size_number - Casts a number to the specified size
 *   * @num: Number to be casted.
 *    * @size: Number indicating the type to be casted.
 *     *
 *      * Return: Casted value of num
 *       */
long int convertSizeNumber(long int num, int size)
{
		if (size == 2)
					return (num);
			else if (size == 1)
						return ((short)num);

				return ((int)num);
}

/**
 *  * convert_size_unsgnd - Casts a number to the specified size
 *   * @num: Number to be casted
 *    * @size: Number indicating the type to be casted
 *     *
 *      * Return: Casted value of num
 *       */
long int convertSizeUnsgnd(unsigned long int num, int size)
{
		if (size == 2)
					return (num);
			else if (size == 1)
						return ((unsigned short)num);

				return ((unsigned int)num);
}
