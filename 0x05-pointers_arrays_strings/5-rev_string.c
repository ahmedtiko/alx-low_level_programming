#include "main.h"

/**
 * rev_string: prints a string in reverse
 * @s: Input string
 * Return: String in reverse
 */

void rev_string(char *s)
{
	int length = 0;
	char *start = s;
	char temp;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	s--;

	while (start < s)
	{
		temp = *start;
		*start = *s;
		*s = temp;
		start++;
		s--;
	}
}
