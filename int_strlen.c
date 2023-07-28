#include "main.h"

/**
 * _strlen - function gets length of string.
 * @string: names the string.
 * Return: gives length (int) on success.
 */

int _strlen(char *string)
{
	int length;

	length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}
