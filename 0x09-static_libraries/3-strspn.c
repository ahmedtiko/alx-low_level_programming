#include "main.h"

/**
 *_strspn - main function
 *
 * @s: Function parameter
 *
 * @accept: Function parameter
 *
 * Return: Always 0
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int match;
	int i;

	while (*s)
	{
		match = 0;

		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				match = 1;
				break;
			}
		}

		if (match)
		{
			count++;
			s++;
		}
		else
		{
			break;
		}
	}

	return (count);
}
