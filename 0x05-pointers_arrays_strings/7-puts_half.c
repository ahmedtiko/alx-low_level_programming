#include "main.h"

/**
 * puts_half - a function that prints half of a string
 * if odd len, n = (length_of_the_string - 1) / 2
 * @str: input
 * Return: half of input
 */

void puts_half(char *str)
{
	int length = 0;
	int i;
	int start;
	int end;

	while (str[length] != '\0')
	{
		length++;
	}

	start = length / 2;
	end = length;

	if (length % 2 == 1)
	{
		end = start + 1;
		start = (length - 1) / 2;
	}

	for (i = start; i < end; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}	
