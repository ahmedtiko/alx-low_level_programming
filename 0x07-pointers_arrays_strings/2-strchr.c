#include "main.h"

/**
 * _strchr - main function
 *
 * @s: Function parameter
 *
 * @c: Function parameter
 *
 * Return: Always 0
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return s;
		}

		s++;
	}

	if (c == '\0')
	{
		return s;
	}

	return (NULL);
}
