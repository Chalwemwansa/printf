#include "main.h"

/**
 * ch - gives function to return char.
 * @character: gives list given.
 * Return: gives number of char printed on success.
 */

int ch(va_list character)
{
	return (_putchar(va_arg(character, int)));
}
