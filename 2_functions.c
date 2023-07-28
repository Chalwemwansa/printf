#include "main.h"
/**
 * pUnsigned - prints unsigned integers
 *
 * @types: variable used
 * @str: variable used in the code
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 * Return: an integer
 */
int pUnsigned(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	int i = 1022;
	unsigned long int num;

	num = convert_Size_Unsgnd(va_arg(types, unsigned long int), size);
	if (num == 0)
		str[i--] = '0';
	str[1023] = '\0';
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_Unsgnd(0, i, str, flag, width, precision, size));
}
/**
 * pOctal - prints number in octal
 *
 * Return: prints a number
 * @types: varaible used
 * @str: variable used
 * @flag: variable used in the code
 * @width: variable used in the code
 * @precision: variable used in the code
 * @size: variable used in the code
 */
int pOctal(va_list types, char str[],
			int flag, int width, int precision, int size)
{
int i = 1022;
unsigned long int num, init_num;

num = va_arg(types, unsigned long int);
init_num = num;
(void)width;
num = convert_Size_Unsgnd(num, size);
if (num == 0)
	str[i--] = '0';
str[1023] = '\0';
while (num > 0)
{
str[i--] = (num % 8) + '0';
num /= 8;
}
if (flag & 8 && init_num != 0)
	str[i--] = '0';
i++;
return (write_Unsgnd(0, i, str, flag, width, precision, size));
}
/**
 * pHexadecimal - prints a number into hexadecimal
 *
 * Return: an integer
 * @types: variable used
 * @str: variable used
 * @flag: variable used
 * @width: variable used
 * @precision: variable used
 * @size: variable used
 */
int pHexadecimal(va_list types, char str[],
			int flag, int width, int precision, int size)
{
	return (pHexa(types, "0123456789abcdef", str,
				flag, 'x', width, precision, size));
}
/**
 * pHexa - prints numbers in hexadecimal
 *
 * Return: prints an integer
 * @types: variable used
 * @mTo: variabvle used
 * @str: variable
 * @flag: variable
 * @fCh: variable
 * @width: width
 * @precision: variable used
 * @size: variable used
 */
int pHexa(va_list types, char mTo[], char str[],
			int flag, char fCh, int width, int precision, int size)
{
	int i = 1022;
	unsigned long int num, initNum;

	num = va_arg(types, unsigned long int);
	initNum = num;
	(void)width;
	num = convert_Size_Unsgnd(num, size);
	if (num == 0)
		str[i--] = '0';
	str[1023] = '\0';
	while (num > 0)
	{
		str[i--] = mTo[num % 16];
		num /= 16;
	}
	if (flag & 8 && initNum != 0)
	{
		str[i--] = fCh;
		str[i--] = '0';
	}
	i++;
	return (write_Unsgnd(0, i, str, flag, width, precision, size));
}
