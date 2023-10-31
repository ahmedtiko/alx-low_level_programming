#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * containing a copy of the string
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if it fails
 */

char *_strdup(char *str)
{
	char *duplicate;
	unsigned int l = 0;
	unsigned int i = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[l])
	{
		l++;
	}

	duplicate = (char *)malloc((l + 1) * sizeof(char));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < l; i++)
	{
		duplicate[i] = str[i];
	}

	duplicate[l] = '\0';

	return (duplicate);
}
