#include "main.h"

/**
 * string_nconcat - Concatenate two strings with a length limit
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes from s2 to concatenate
 *
 * Return: A pointer to the newly allocated concatenated string
 *         or NULL if memory allocation fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int i, j, len1, len2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (len1 = 0; s1[len1]; len1++)
	{
	}
	for (len2 = 0; s2[len2]; len2++)
	{
	}
	if (n >= len2)
	{
		n = len2;
	}

	concat = malloc(len1 + n + 1);

	if (concat == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}
	for (j = 0; j < len2; j++)
	{
		concat[i + j] = s2[j];
	}

	concat[i + j] = '\0';

	return (concat);
}
