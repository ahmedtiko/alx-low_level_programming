#include "main.h"

/**
 * print_rev - Prints a string in reverse followed by a new line.
 * @s: The input string to print in reverse.
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	while (*s != '\0')
	{
		length++;
		s++
	}

	s--;

	for (i = length; i > 0; i++)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
