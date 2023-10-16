#include "main.h"

/**
 * puts2 - function should print only one character out of two
 * starting with the first one
 * @str: input
 * Return: print
 */

void puts2(char *str)
{
	int i;

	for (i = 0; str[i] > '\0'; i += 2)
	{
		_putchar(str[i]);
	}
	if (str[i] == '\0')
	{
		_putchar('\n');
	}
}
