#include "main.h"

/**
 * _strlen - function gets length of string.
 * @string: names the string.
 * Return: length (int).
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
