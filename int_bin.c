#include "main.h"

/**
 * _bin - gives function to print binary.
 * @bin: gives list being passed in function.
 * Return: gives updated count on return.
 */

int _bin(va_list bin)
{
	int count = 0, i;
	int *ar;
	unsigned int n = va_arg(bin, unsigned int);
	unsigned int p = n;

	while (n / 2 != 0)
	{
		n /= 2;
		count++;
	}
	count++;
	ar = malloc(count * sizeof(int));
	if (ar == NULL)
	{
		free(ar);
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		ar[i] = p % 2;
		p /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(ar[i] + '0');
	}
	free(ar);
	return (count);
}
