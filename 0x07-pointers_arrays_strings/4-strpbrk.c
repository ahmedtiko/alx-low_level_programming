#include "main.h"

/**
 * _strpbrk: main function prototype
 *
 * @s: Function parameter
 *
 * @accept: Function parameter
 *
 * Return: Always 0
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return s;
			}
		}

		s++;
	}

	return (NULL);
}
