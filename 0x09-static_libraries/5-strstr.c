#include "main.h"

/**
 * _strstr: Main function prototype
 *
 * @haystack: Function Parameter
 *
 * @needle: Function parameter
 *
 * Return: Always 0
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*needle == '\0')
	{
		return (haystack);
	}

	i = 0;

	while (haystack[i])
	{
		j = 0;

		while (needle[j] && (haystack[i + j] == needle[j]))
		{
			j++;
		}

		if (needle[j] == '\0')
		{
			return (haystack + i);
		}

		i++;
	}

	return (NULL);
}
