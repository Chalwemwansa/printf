#include "main.h"
/**
 * handleWriteChar - prints a charcter to standard output
 *
 * Return: returns an int
 * @c: variable used
 * @str: cahracter used
 * @flag: character used
 * @width: character used
 * @precision: character used
 * @size
 */
int handle_write_char(char c, char str[],
			int flag, int width, int precision, int size)
{
	int index = 0, i;
	char padding = ' ';

	(void)precision;
	(void)size;
	if (flag & 4)
		padding = '0';
	str[index++] = c;
	str[i] = '\0';
	if (width > 1)
	{
	str[1023] = '\0';
	for (i = 0; i < width - 1; i++)
		str[1022 - i] = padding;
	if (flag & 1)
		return (write(1, &str[0], 1) +
				write(1, &str[1023 - i], width - 1));
	else
		return (write(1, &str[1023 - i], width - 1) +
				write(1, &str[0], 1));
	}
	return (write(1, &str[0], 1));
}
/**
 * writeNumber - writes a number
 *
 * Return: an integer
 * @isNegative: variable used in the code
 * @index: variable used in the code
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int writeNumber(int isNegative, int index, char str[],
			int flag, int width, int precision, int size)
{
	int l;
	char padding, extraCh;

	l = 1023 - index;
	padding = ' ';
	extraCh = 0;
	(void)size;
	if ((flag & 4) && (!(flag & 1)))
		padding = '0';
	if (isNegative)
		extraCh = '-';
	else if (flag & 2)
		extraCh = '+';
	else if (flag & 16)
		extraCh = ' ';
	return (writeNum(index, str, flag, width, precision,
				l, padding, extraCh));
}
/**
 * writeNum - writes a number using a buffer
 *
 * Return: an integer
 * @index: variable
 * @str: variable
 * @flag: variable
 * @width: variable
 * @precision: variable
 * @l: variable
 * @padding: variable
 * @extraC: variable
 */
int write_num(int index, char str[], int flag, int width,
	int precision, int l, char padding, char extraC)
{
int i, paddStart = 1;

if (precision == 0 && index == 1022 && str[index] == '0' && width == 0)
	return (0);
if (precision == 0 && index == 1022 && str[index] == '0')
	str[index] = padd = ' ';
if (precision > 0 && precision < l)
	padding = ' ';
while (precision > l)
{
str[--index] = '0';
l++;
}
if (extraC != 0)
	l++;
if (width > l)
{
for (i = 1; i < width - l + 1; i++)
	str[i] = padding;
str[i] = '\0';
if (flag & 1 && padding == ' ')
{
if (extraC)
	str[--index] = extraC;
return (write(1, &str[index], l) + write(1, &str[1], i - 1));
}
else if (!(flag & 1) && padding == ' ')
{
if (extraC)
	str[--index] = extraC;
return (write(1, &str[1], i - 1) + write(1, &str[index], l));
}
else if (!(flag & 1) && padding == '0')
{
if (extraC)
	str[--paddStart] = extraC;
return (write(1, &str[paddStart], i - paddStart) +
		write(1, &str[index], l - (1 - paddStart)));
}
}
if (extraC)
str[--index] = extraC;
return (write(1, &str[index], l));
}
/**
* writeUnsgnd - writes unsigned number
*
* Return: an integer
* @isNegative: variable used
* @index: variable used
* @str: variable used
* @flag: variable used
* @width: variable used
* @precision: variable used
* @size: variable used
*/
int writeUnsgnd(int isNegative, int index,
	char str[],
		int flag, int width, int precision, int size)
{
	int l = 1023 - index, i = 0;
	char padding = ' ';

	(void)isNegative;
	(void)size;

	if (precision == 0 && index == 1022 && str[index] == '0')
		return (0);
	if (precision > 0 && precision < l)
		padding = ' ';
	while (precision > l)
	{
	str[--index] = '0';
	l++;
	}
	if ((flag & 4) && !(flag & 1))
		padding = '0';
	if (width > l)
	{
	for (i = 0; i < width - l; i++)
		str[i] = padding;
	str[i] = '\0';
	if (flag & 1)
		return (write(1, &str[index], l) + write(1, &str[0], i));
	else
		return (write(1, &str[0], i) + write(1, &str[index], l));
	}
	return (write(1, &str[index], l));
}
/**
 * writePointer - prints a pointer
 *
 * Return: an integer
 * @str: variable
 * @index: variable used
 * @l:variable used
 * @width: variable used
 * @flag: variable used
 * @padding: variable used
 * @extraC: variable used
 * @paddStart: variable used
 */
int writePointer(char str[], int index, int l,
		int width, int flag, char padding, char extraC, int paddStart)
{
int i;
if (width > l)
{
for (i = 3; i < width - l + 3; i++)
	str[i] = padding;
str[i] = '\0';
if (flag & 1 && padding == ' ')
{
str[--index] = 'x';
str[--index] = '0';
if (extraC)
	str[--index] = extraC;
return (write(1, &str[index], l) + write(1, &str[3], i - 3));
}
else if (!(flag & 1) && padding == ' ')
{
str[--index] = 'x';
str[--index] = '0';
if (extraC)
	str[--index] = extraC;
return (write(1, &str[3], i - 3) + write(1, &str[index], l));
}
else if (!(flag & 1) && padding == '0')
{
if (extraC)
	str[--paddStart] = extraC;
str[1] = '0';
str[2] = 'x';
return (write(1, &str[paddStart], i - paddStart) +
			write(1, &str[index], l - (1 - paddStart) - 2));
}
}
str[--index] = 'x';
str[--index] = '0';
	if (extraC)
	str[--index] = extraC;
	return (write(1, &str[index], 1024 - index - 1));
}
