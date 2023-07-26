#include "main.h"

/**
 * is_printable - Analyses whether a char is printable
 * @k: Gives the Char to be analysed.
 *
 * Return: 1 if k is printable, 0 otherwise.
 */

int isPrintable(char k)
{
	if (k >= 32 && k < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Appends the ascci in hexadecimal code to the buffer
 * @buffer: Gives Array of chars.
 * @j: Gives Index which onsets appending.
 * @ascii_code: ASSCI COD.
 * Return: Always 3 on success or not.
 */

int appendHexaCode(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - It verifies whether a given char is a digit.
 * @k: Gives Char to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int isDigit(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Function casts number to the specified size.
 * @num: Gives a number to be casted.
 * @size: Shows the number indicating type to be casted.
 *
 * Return: Gives casted value of num
 */

long int convertSizeNumber(long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 2)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd -Function casts number to specified size.
 * @num: Shows number to be casted
 * @size: Gives number indicating type to be casted.
 *
 * Return: Casted value of num on success.
 */

long int convertSizeUnsgnd(unsigned long int num, int size)
{
	if (size == 2)
		return (num);
	else if (size == 1)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

