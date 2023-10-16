#include "main.h"

/**
 * _puts - Prints a string followed by a new line to stdout.
 * @str: The input string to print.
 */
void _puts(char *str)
{
	while (*str)
	{
		_putchar(str);
		str++;
	}

	_putchar("\n");
}
